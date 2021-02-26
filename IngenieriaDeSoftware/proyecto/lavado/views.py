from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, 'index.html')

def paquetes(request):
    return render(request, 'paquetes.html')