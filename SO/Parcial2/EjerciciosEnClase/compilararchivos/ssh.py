#!/usr/bin/python3

import os,subprocess,re
from subprocess import Popen, PIPE
from os import system
from re import match, compile

Popenip = Popen(['hostname','-I'],stdout=PIPE)
ip = Popenip.stdout.read().decode()
print("La red actual es:")
for words in ip.split():
	ip = words.split(".")
	break
network = ip[0]+"."+ip[1]+"."+ip[2]+"."
print(network+"0/8\n")

for i in range(2,5):
	i = str(i)
	ip = network+i
	res = os.system("ping -c 3 "+ip)
	if(res == 0):
		print("La maquina con ip "+ ip +" esta conectada a la red\n")
		system("ssh alumno@"+ip)
		Popen(['scp','-4','compilararchivos.py','alumno@'+ip+':/home/compilararchivos.py'])
		res = Popen(["./compilararchivos.py"])
		if(res):
			print("operacion exitosa")
		else:
			print("error al hacer transferencia de archivos")
	else:
		print("La maquina con ip "+ ip +" no esta conectada a la red.\n")

