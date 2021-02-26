from django.contrib import admin
from .models import Articulo, Empleado, Lavado, LugarCompra, Paquete
# Register your models here.
admin.site.register(Empleado)
admin.site.register(Paquete)
admin.site.register(LugarCompra)
admin.site.register(Articulo)
