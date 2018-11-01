import socket
from django.conf import settings

__db = settings.KAPPA_DB['default']

def connect(dbname=__db['DB'], host=__db['HOST'], port=__db['PORT'], user=__db['USER'], passwd=__['PASS']):
	return Connection(dbname, host, port, user, passwd)


class Connection(object):
	def __init__(self, host, port, user, passwd):
		self.host = host
		self.port = port
		# char[] = [0x01, 0xFF, 0xFF, 0xFF, 0xFF, ''....'\0',  ''....'\0']
		# chr(1) + chr(int) x 4 + string + '\0' + string + '\0'
		self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.socket.bind((host, port))
		self.listen(1)
		self.connection, self.addr = self.socket.accept()
		self.closed = False
		self.request_id = 0
		ip_addres_parts = [chr(int(x)) for x in host.split('.')]
		#0x01
		self.connection.sendall(
				'{}{}{}\x00{}\x00'.format(
						chr(0x01),
						''.join(ip_addres_parts),
						user,
						passwd
					)
			)

	def __del__(self):
		self.close()

	def cursor(self):
		return Cursor(self)

	def close():
		self.connection.close()
		self.closed = True
		#0x00

	def commit():
		#0x03
		self.connection.sendall(chr(0x03))

	def rollback():
		#0x04
		self.connection.sendall(chr(0x04))


class Cursor:
	def __init__(self, connection):
		self.connection = connection

	def execute(self, query):
		#0x02
		self.connection.sendall(chr(0x02) + query + '\x00')
		self.connection.rec
		result = ''
		while True:
			data = self.connection.recv(1024)
			if (data):
				result += data
			else:
				break
		return result

	# def prepare():

	def fetch(self):
		pass

	def fetch_all(self):
		pass


# class Query:
# 	def bind()