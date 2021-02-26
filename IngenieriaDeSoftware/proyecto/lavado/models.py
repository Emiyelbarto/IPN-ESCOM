# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey and OneToOneField has `on_delete` set to the desired behavior
#   * Remove `managed = True` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models
from django.contrib.auth.models import User
from django.db.models.signals import post_save
from django.dispatch import receiver

"""
class RolEmpleado(models.Model):
    idrol_empleado = models.AutoField(primary_key=True)
    titulo = models.CharField(max_length=10)
    privilegios = models.IntegerField()

    class Meta:
        managed = True
        db_table = 'rol_empleado'
"""

class Paquete(models.Model):
    idpaquete = models.AutoField(primary_key=True)
    titulo = models.CharField(max_length=15)
    descripcion = models.TextField()
    precio = models.FloatField()
    duracion_estimada = models.TimeField(blank=True, null=True)

    class Meta:
        managed = True
        db_table = 'paquete'
    def __str__(self):
        return str(self.titulo)

class LugarCompra(models.Model):
    idlugar_compra = models.AutoField(primary_key=True)
    nombre_tienda = models.CharField(max_length=15)
    direccion = models.CharField(max_length=45)

    class Meta:
        managed = True
        db_table = 'lugar_compra'

    def __str__(self):
        return str(self.nombre_tienda)

class Articulo(models.Model):
    idarticulo = models.AutoField(primary_key=True)
    nombre = models.CharField(max_length=15)
    descripcion = models.CharField(max_length=45)
    precio = models.FloatField()
    cantidad = models.IntegerField()
    codigo_barras = models.CharField(max_length=30, blank=True, null=True)
    lugar_compra_idlugar_compra = models.ForeignKey('LugarCompra', models.DO_NOTHING, db_column='lugar_compra_idlugar_compra', default = -1)

    class Meta:
        managed = True
        db_table = 'articulo'
    def __str__(self): # __str__ for Python 3, __unicode__ for Python 2
        return self.nombre


class Empleado(models.Model):
    idempleado = models.AutoField(primary_key=True)
    user = models.OneToOneField(User, on_delete=models.CASCADE)
    nombre = models.CharField(max_length=35)
    apaterno = models.CharField(max_length=35)
    amaterno = models.CharField(max_length=35)
    curp = models.CharField(db_column='CURP', max_length=18)  # Field name made lowercase.
    fecha_nacimiento = models.DateField()
    fecha_ingreso = models.DateField()
    #activo = models.IntegerField()
    no_ss = models.CharField(max_length=15, blank=True, null=True)
    usuario = models.CharField(max_length=10)
    contrasena = models.CharField(max_length=45)
    correo_electronico = models.CharField(max_length=45)
    nfc_data = models.TextField(db_column='NFC_data', blank=True, null=True)  # Field name made lowercase.
    #rol_empleado_idrol_empleado = models.ForeignKey('RolEmpleado', models.DO_NOTHING, db_column='rol_empleado_idrol_empleado')

    class Meta:
        managed = True
        db_table = 'empleado'

class Lavado(models.Model):
    idlavado = models.AutoField(primary_key=True)
    placas = models.CharField(max_length=5)
    fecha = models.DateField()
    hora_inicio = models.TimeField()
    hora_termino = models.TimeField()
    lote = models.IntegerField(blank=True, null=True)
    empleado_idempleado = models.ForeignKey(Empleado, models.DO_NOTHING, db_column='empleado_idempleado', related_name='empleado_idempleado')
    supervisor_idempleado = models.ForeignKey(Empleado, models.DO_NOTHING, db_column='supervisor_idempleado', related_name='supervisor_idempleado')
    encargado_idempleado = models.ForeignKey(Empleado, models.DO_NOTHING, db_column='encargado_idempleado')
    paquete_idpaquete = models.ForeignKey('Paquete', models.DO_NOTHING, db_column='paquete_idpaquete')

    class Meta:
        managed = True
        db_table = 'lavado'
"""
class LavadoHasArticulo(models.Model):
    lavado_idlavado = models.OneToOneField(Lavado, models.DO_NOTHING, db_column='lavado_idlavado', primary_key=True)
    articulo_idarticulo = models.ForeignKey(Articulo, models.DO_NOTHING, db_column='articulo_idarticulo')

    class Meta:
        managed = True
        db_table = 'lavado_has_articulo'
        unique_together = (('lavado_idlavado', 'articulo_idarticulo'),)
"""

