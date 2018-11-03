import socket
from django.conf import settings

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

	def execute(self, query):
		#0x02
		if self.conn == None:
			return 'Couldn\'t connect to Kappa'

		self.conn.socket.sendall( b'%s%s\x00' % (b'\x02', query) )
		result = ''
		# while True:
		# 	data = self.conn.socket.recv(1024)
		# 	print(data)
		# 	if (data):
		# 		result += data
		# 	else:
		# 		break
		return result

	def prepare(self):
		pass

	def fetch(self):
		pass

	def fetch_all(self):
		pass


# class Query:
# 	def bind()