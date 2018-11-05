from __future__ import absolute_import, unicode_literals

import socket
import pickle
import multiprocessing as mp
from celery import shared_task
from base64 import b64decode

# mp.allow_connection_pickling()


@shared_task
def wait_response(bsock, auth):
	result = ''
	return 'Done'
	mp.current_process().authkey = b64decode(auth)
	sock = pickle.loads(bsock)
	while True:
		sock.settimeout(8.0)
		try:
			data = sock.recv(4096)
			if data:
				result += data.decode()
			else:
				result += '\n\nOoops! Unexpected error. Data isn\'t completed.'
				break
		except:
			result += '\n\nKappa\'s timeout exceeded'
			break
	return result
