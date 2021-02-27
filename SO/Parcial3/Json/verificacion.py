#!/usr/bin/python3

import json
import psycopg2
from psycopg2.extensions import ISOLATION_LEVEL_AUTOCOMMIT
import sys
from configparser import ConfigParser
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

cursor2 = con.cursor()
conn.close()

try:
	qry = cursor2.execute("CREATE TABLE data (idEstado INT NOT NULL, estado VARCHAR(100) NOT NULL, idMunicipio INT NOT NULL, ciudad VARCHAR DEFAULT NULL, zona VARCHAR(100) NOT NULL, cp INT NOT NULL, asentamiento VARCHAR NOT NULL, tipo VARCHAR NOT NULL)")
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
		try:		
			cursor2.execute("INSERT INTO data VALUES('"+str(Entidades['idEstado'])+"','" + Entidades['estado'] + "','"+str(Entidades['idMunicipio'])+"','null','"+Entidades['zona']+"','"+str(Entidades['cp'])+"','"+Entidades['asentamiento']+"','"+Entidades['tipo']+"')")
			con.commit()
		except(Exception, psycopg2.DatabaseError) as error:
			print(error)
		print("IdEstado: ", Entidades['idEstado'])
		print("Estado: " + Entidades['estado'])
		print("IdMunicipio: ", Entidades['idMunicipio'])
		print("Ciudad: 'null'")
		print("Zona: " + Entidades['zona'])
		print("CP: ", Entidades['cp'])
		print("Asentamiento: " + Entidades['asentamiento'])
		print("Tipo: " + Entidades['tipo'])
		print("------------------")
		res = cursor2.execute("SELECT * FROM data WHERE idEstado = "+str(Entidades['idEstado'])+"")
		print(type(res))
		'''if(res is None):
			print("error")
		else:
			print("Query realizada sin problema")
		con.commit()'''

	else: 
		try:		
			cursor2.execute("INSERT INTO data VALUES('"+str(Entidades['idEstado'])+"','" + Entidades['estado'] + "','"+str(Entidades['idMunicipio'])+"','"+Entidades['ciudad']+"','"+Entidades['zona']+"','"+str(Entidades['cp'])+"','"+Entidades['asentamiento']+"','"+Entidades['tipo']+"')")
			con.commit()
		except(Exception, psycopg2.DatabaseError) as error:
			print(error)
		'''print("IdEstado: ", Entidades['idEstado'])
		print("Estado: " + Entidades['estado'])
		print("IdMunicipio: ", Entidades['idMunicipio'])
		print("Ciudad: " + Entidades['ciudad'])
		print("Zona: " + Entidades['zona'])
		print("CP: ", Entidades['cp'])
		print("Asentamiento: " + Entidades['asentamiento'])
		print("Tipo: " + Entidades['tipo'])
		print("------------------")'''

con.close()