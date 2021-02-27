#!/usr/bin/python3
#Usamos json para leer el json
import json
#Usamos psycopg2 para conectarnos a PSQL
import psycopg2
#Usamos este permiso para poder crear bases de datos y tablas
from psycopg2.extensions import ISOLATION_LEVEL_AUTOCOMMIT
'''Primero nos conectamos a la base de datos con estas credenciales'''
cred = ['localhost','postgres','admin','root','entidades']
#Definimos la coneccion
conn = None
con = None
#Hacemos la coneccion, si no es posible regesa error
try:
	print("Conectando a la base de datos de postgre con los datos: " + cred[0] + ", " + cred[1] + ", " + cred[2] + ", " + cred[3] + ".")
	conn = psycopg2.connect(host = cred[0], dbname = cred[1], user = cred[2], password = cred[3])
	conn.set_isolation_level(ISOLATION_LEVEL_AUTOCOMMIT)
	cursor = conn.cursor()
	print ("¡Conectado!")
except (Exception, psycopg2.DatabaseError) as error:
	print(error)
#Verificamos si la BD existe, si no, la creamos
cursor.execute("SELECT 1 AS result FROM pg_database WHERE datname='entidades'")
db_exists = cursor.fetchone()
if(db_exists is None):
	print("La base de datos no existe.\nCreando BD.")
	cursor.execute("CREATE DATABASE entidades")
	print("DB 'entidades' creada")
	con = psycopg2.connect(host = cred[0], dbname = cred[4], user = cred[2], password = cred[3])
	con.set_isolation_level(ISOLATION_LEVEL_AUTOCOMMIT)
else:
	print("La base de datos existe.")
	con = psycopg2.connect(host = cred[0], dbname = cred[4], user = cred[2], password = cred[3])
	con.set_isolation_level(ISOLATION_LEVEL_AUTOCOMMIT)
#Realizamos la conección a la base de datos y 
cursor2 = con.cursor()
conn.close()

try:
	qry = cursor2.execute("CREATE TABLE data (idestado INT NOT NULL, estado VARCHAR(100) NOT NULL, idmunicipio INT NOT NULL, ciudad VARCHAR DEFAULT NULL, zona VARCHAR(100) NOT NULL, cp INT NOT NULL, asentamiento VARCHAR NOT NULL, tipo VARCHAR NOT NULL)")
	if(qry is not None):
		print("Error al crear tabla")
	else:
		print("Tabla Data creada")
except(Exception, psycopg2.DatabaseError) as error:
	print(error)
#Abrimos el Json
with open('data.json', encoding = "ISO-8859-1") as json_file:
	data = json.load(json_file)
#Definimos las localidades del JSON
Mexico = data[0]
#Para cada Asentamiento hacemos un insert a la BD
for Entidades in Mexico['localidad']:
	if(Entidades['ciudad'] is None): 
		#Insertamos los datos
		try:		
			cursor2.execute("INSERT INTO data VALUES('"+str(Entidades['idEstado'])+"','" + Entidades['estado'] + "','"+str(Entidades['idMunicipio'])+"','null','"+Entidades['zona']+"','"+str(Entidades['cp'])+"','"+Entidades['asentamiento']+"','"+Entidades['tipo']+"')")
			con.commit()
			#Verificamos que los datos sean correctos
			cursor2.execute("SELECT * FROM data WHERE idestado='"+str(Entidades['idEstado'])+"' AND estado='"+Entidades['estado']+"' AND idmunicipio='"+str(Entidades['idMunicipio'])+"' AND ciudad='null' AND zona='"+Entidades['zona']+"' AND cp='"+str(Entidades['cp'])+"' AND asentamiento='"+Entidades['asentamiento']+"' AND tipo='"+Entidades['tipo']+"'")
			res = cursor2.fetchone()
			res = str(res)
			print(res)
			consulta = "("+str(Entidades['idEstado'])+", '" + Entidades['estado'] + "', "+str(Entidades['idMunicipio'])+", 'null', '"+Entidades['zona']+"', "+str(Entidades['cp'])+", '"+Entidades['asentamiento']+"', '"+Entidades['tipo']+"')"
			print(consulta)
			if(res == consulta):
				print("Datos insertados de forma correcta.")
			else:
				print("Error al insertar la consulta: ")
				errores = open("error.txt","w")
				errores.write("Error al consultar:")
				errores.write(consulta)
				errores.close()

		except(Exception, psycopg2.DatabaseError) as error:
			print(error)
	else: 
		try:		
			#Insertamos los datos	
			cursor2.execute("INSERT INTO data VALUES('"+str(Entidades['idEstado'])+"','" + Entidades['estado'] + "','"+str(Entidades['idMunicipio'])+"','"+Entidades['ciudad']+"','"+Entidades['zona']+"','"+str(Entidades['cp'])+"','"+Entidades['asentamiento']+"','"+Entidades['tipo']+"')")
			con.commit()
			#Verificamos que los datos sean correctos
			cursor2.execute("SELECT * FROM data WHERE idestado='"+str(Entidades['idEstado'])+"' AND estado='"+Entidades['estado']+"' AND idmunicipio='"+str(Entidades['idMunicipio'])+"' AND ciudad='"+Entidades['ciudad']+"' AND zona='"+Entidades['zona']+"' AND cp='"+str(Entidades['cp'])+"' AND asentamiento='"+Entidades['asentamiento']+"' AND tipo='"+Entidades['tipo']+"'")
			res = cursor2.fetchone()
			res = str(res)
			print(res)
			consulta = "("+str(Entidades['idEstado'])+", '" + Entidades['estado'] + "', "+str(Entidades['idMunicipio'])+", '"+Entidades['ciudad']+"', '"+Entidades['zona']+"', "+str(Entidades['cp'])+", '"+Entidades['asentamiento']+"', '"+Entidades['tipo']+"')"
			print(consulta)
			if(res == consulta):
				print("Datos insertados de forma correcta.")
			else:
				print("Error al insertar la consulta: ")
				errores = open("error.txt","w")
				write("Error al consultar:")
				write(consulta)
				errores.close()

		except(Exception, psycopg2.DatabaseError) as error:
			print(error)