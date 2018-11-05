from __future__ import absolute_import, unicode_literals

import os
from celery import Celery


os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'kappaweb.settings')

TaskQueue = Celery('kappaweb')
TaskQueue.config_from_object('django.conf:settings', namespace='CELERY')
TaskQueue.autodiscover_tasks()
