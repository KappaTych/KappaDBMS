import socket

from queue import Queue
from backend.api.tasks import wait_response
from django.conf import settings

from base64 import b64encode
from multiprocessing import current_process
from multiprocessing.reduction import ForkingPickler
from io import BytesIO


# TODO: make second mode without using Celery (e.g., ProcessPoolExecutor)

__db = settings.KAPPA_DB['default']

def connect(dbname=__db['DB'], host=__db['HOST'], port=__db['PORT'], \
			user=__db['USER'], passwd=__db['PASS']):
	return Connection(dbname, host, port, user, passwd)


class Connection(object):
	def __init__(self, dbname, host, port, user, passwd):
		self.host = host
		self.port = port
		self.closed = False

		try:
			self.socket = socket.socket()
		except OSError as msg:
			print('1', msg)
			self.close()
			return

		try:
			self.socket.connect((host, port))
		except OSError as msg:
			print('2', msg)
			self.close()
			return

		# ip_address_parts = [chr(int(x)) for x in host.split('.')]
		#0x01
		# self.connection.sendall(
		# 		'{}{}{}\x00{}\x00'.format(
		# 				chr(0x01),
		# 				''.join(ip_address_parts),
		# 				user,
		# 				passwd
		# 			)
		# 	)

	def __del__(self):
		self.close()

	def cursor(self):
		if self.closed:
			return Cursor()
		return Cursor(self)

	def close(self):
		if self.socket:
			self.socket.close()
		self.socket = None
		self.closed = True
		#0x00

	def commit(self):
		#0x03
		self.socket.sendall(chr(0x03))

	def rollback(self):
		#0x04
		self.socket.sendall(chr(0x04))


class Cursor:
	def __init__(self, connection=None):
		self.conn = connection
		self.records = Queue()

	def execute(self, query):
		#0x02
		if self.conn == None:
			self.records.put('Couldn\'t connect to Kappa')
			return self
		self.conn.socket.sendall( b'%s%s\x00' % (b'\x02', query) )
		buf = BytesIO()
		ForkingPickler(buf).dump(self.conn.socket)
		self.records.put(
				wait_response.delay(
					buf.getvalue(),
					b64encode(current_process().authkey)
				)
			)
		return self

	def prepare(self):
		pass

	def fetch(self):
		if self.records.empty():
			return 'None'
		record = self.records.get()
		if type(record) == str:
			return record
		try:
			result = record.get(timeout=20)
		except:
			result = 'WTF'
		finally:
			record.forget()
		return result

	def fetch_all(self):
		return [self.fetch() for _ in range(len(self.records))]
