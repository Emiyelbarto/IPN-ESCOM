from django.urls import path

from . import views

urlpatterns = [
    path('', views.index, name='index'),
    path('paquetes.html', views.paquetes, name="paquetes")
]
