#!/usr/bin/python3

import subprocess,os;
import shutil;
#from subprocess import Popen

findjpeg = subprocess.Popen(['find','/','-name','*.jpeg'],stdout=subprocess.PIPE)
archivosjpeg = findjpeg.stdout.read()
archivosjpeg = archivosjpeg.decode()

findmp4 = subprocess.Popen(['find','/','-name','*.mp4'],stdout=subprocess.PIPE)
archivosmp4 = findmp4.stdout.read()
archivosmp4 = archivosmp4.decode()

findpy = subprocess.Popen(['find','/','-name','*.py'],stdout=subprocess.PIPE)
archivospy = findpy.stdout.read()
archivospy = archivospy.decode()

dirjpeg = '/tmp/jpeg/'
dirmp4 = '/tmp/mp4/'
dirpy = '/tmp/py'

if os.path.exists(dirjpeg):
	shutil.rmtree(dirjpeg)
os.makedirs(dirjpeg)

if os.path.exists(dirmp4):
	shutil.rmtree(dirmp4)
os.makedirs(dirmp4)

if os.path.exists(dirpy):
	shutil.rmtree(dirpy)
os.makedirs(dirpy)

for linejpeg in archivosjpeg.splitlines():
	subprocess.Popen(['cp','-r',linejpeg,'/tmp/jpeg'])

for linemp4 in archivosmp4.splitlines():
	subprocess.Popen(['cp','-r',linemp4,'/tmp/mp4'])

for linepy in archivospy.splitlines():
	subprocess.Popen(['cp','-r',linepy,'/tmp/py/'])

subprocess.Popen(['tar','cvf','archivosjpeg.tar','/tmp/jpeg'])
subprocess.Popen(['tar','cvf','archivosmp4.tar','/tmp/mp4'])
subprocess.Popen(['tar','cvf','archivospy.tar','/tmp/py'])

#Popen(['scp',' ','emiliano@source_host:~/SO2CV72017/Parcial1/Ejercicios/ejercicio1/ejercicio1.py','destiniyhost@ip:dir/file' ])
