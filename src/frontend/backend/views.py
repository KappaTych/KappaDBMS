import backend.kira as kira

from django.http import HttpResponseNotFound, HttpResponse
from django.shortcuts import render
from django.utils.decorators import method_decorator
from django.views.decorators.csrf import csrf_exempt
from django.views.generic import TemplateView
from django.views import View


class AppView(View):
	template_name = 'index.html'

	def get(self, request):
		return render(request, self.template_name, {})


@method_decorator(csrf_exempt, name='dispatch')
class QueryView(View):
	def post(self, request):
		conn = kira.connect()
		response = HttpResponse()
		response.content = conn.cursor().execute(request.body)
		return response
