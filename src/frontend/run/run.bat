@echo off
chcp 1251
title KappaDBMS

cd ..
cls
echo Starting KappaDBMS Services...
sleep 1
start "Redis" cmd /k "title 'Redis' && redis-server redis.conf"
sleep 2
echo Redis started!
start "Celery" cmd /k "title 'Celery' && cd backend && celery worker -A tasks --loglevel=info"
sleep 2
echo Celery started!
sleep 1

:loop
python manage.py runserver
echo "KappaDBMS is crashed!"
echo.
echo "############################################"
echo "#       KappaDBMS is restarting now        #"
echo "############################################"
goto loop