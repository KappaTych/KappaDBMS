from __future__ import absolute_import, unicode_literals

import os
from celery import Celery

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'kappaweb.settings')

TaskQueue = Celery('kappaweb') #, include=['kappaweb'])
TaskQueue.config_from_object('django.conf:settings', namespace='CELERY')
TaskQueue.autodiscover_tasks()
# TaskQueue.conf.update(
# 	task_serializer='pickle'
# 	result_serializer='pickle',
# 	accept_content=['pickle']
# )

# @TaskQueue.task(bind=True)
# def debug_task(self):
#     print('Request: {0!r}'.format(self.request))