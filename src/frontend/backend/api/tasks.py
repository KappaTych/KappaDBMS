from __future__ import absolute_import, unicode_literals

import socket
import pickle
import multiprocessing as mp
from celery import shared_task
from base64 import b64decode


@shared_task
def wait_response(bsock, auth):
	result = ''
	mp.current_process().authkey = b64decode(auth)
	sock = pickle.loads(bsock)
	while True:
		sock.settimeout(8.0)
		try:
			data = sock.recv(4096)
			if data:
				result += data.decode()
			else:
				break
		except socket.timeout:
			result += '\n\nKappa\'s timeout exceeded'
			break
		except:
			result += '\n\nOoops! Unexpected error. Data isn\'t completed.'
			break
	return result
