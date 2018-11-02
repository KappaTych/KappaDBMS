from django.shortcuts import render
from django.http import HttpResponseNotFound, HttpResponse
import kira

# Create your views here.
class ActionQuery:

	@staticmethod
	def index(cls, request):
		if request.method != 'POST':
			return HttpResponseNotFound()
		conn = kira.connect()
		response = HttpResponse()
		response.content = conn.cursor().execute(request.body)
		return response

ActionQuery.index()