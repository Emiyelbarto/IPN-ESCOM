#!/usr/bin/python3
#Programa realizado por Victor Anaya Martinez, Emiliano Pérez y Mauricio Meléndez
import os
import sys
import shutil
import threading
from PIL import Image

def main():
    print("***\tPrograma A Practica 1\t***")
    wrkspace='/tmp/images/' # Se define el espacio de trabajo
    cleanWrkspace(wrkspace) # Limpieza del espacio de trabajo por si ya se han puesto imágenes ahí
    copyFiles(wrkspace)     # Llamada a función que copia imágenes al espacio de trabajo
    openImages(wrkspace)    # Llamada a función que abre imágenes anteriormente copiadas para ser tratadas
    print("[+] - Procesando imágenes ...")

def copyFiles(wrkspace):    # Función que copia las imágenes al espacoi de trabajo
    flag_dir = validateIntInput("1.-Copiar imagenes desde directorio actual\n2.-Copiar imagenes desde otro directorio\n")
    if(flag_dir == 2):
        filelist= verifyNumImages(flag_dir)
        print('[+] - Copiando imágenes ...')
        for im in filelist:
            destination=wrkspace+im
            shutil.copyfile(im, destination)
    elif(flag_dir == 1):
        filelist= verifyNumImages(flag_dir)
        print('[+] - Copiando imagenes ...')
        for im in filelist:
            destination=wrkspace+im
            shutil.copyfile(im, destination)
    else:
        print("Opción incorrecta.")
        sys.exit()

def ruleImage(file):        # Validación de archivos de tipo imagen
    if(file.endswith('.png') or file.endswith('.jpg') or file.endswith('.jpeg')): 
        return True
    return False

def validateIntInput(message):  # Validación de la opción ingresada
    while True:
        try:
            tryUserInput = int(input(message))
        except ValueError:
            print('El valor introducido no es un entero, intentar de nuevo.\n')
            continue
        else:
            return tryUserInput

def verifyFolder(message):  # Valida que el directorio de donde se copiarán las imágenes existe (Usar dirección absoluta para funcionamiento correcto)
    while True:
        dir = input(message)
        if(os.path.isdir(dir)):
            return dir
        print('El directorio ingresado no existe, intentar de nuevo.\n')
            

def verifyNumImages(flag):  # Verifica que existan al menos diez archivos de tipo imagen para trabajar.
    while True:
        if(flag == 2):
            dir = verifyFolder("Escribir el directorio desde el que se copiaran las 10 imagenes\n")     # Llamada a función que valida la existencia de directorio de origen
            filelist = [file for file in os.listdir(dir) if ruleImage(file)]    # ruleImage es la llamada a la función que valida los archivos de tipo imagen
            os.chdir(dir)
            if(len(filelist) >= 10):
                return filelist
            print('El directorio no tiene al menos 10 imagenes, intentar de nuevo.\n')
        elif(flag == 1):
            filelist = [file for file in os.listdir('.') if ruleImage(file)]    # ruleImage es la llamada a la función que valida los archivos de tipo imagen
            if(len(filelist) >= 10):
                return filelist
            print('El directorio no tiene al menos 10 imagenes.\n')
            sys.exit()

def openImages(wrkspace):   # Función que lanza un hilo por cada imagen en el espacio de trabajo para su procesamiento
    os.chdir(wrkspace)
    filelist = [file for file in os.listdir('.') if ruleImage(file)]    # ruleImage es la llamada a la función que valida los archivos de tipo imagen
    num_hilo=1
    for nombre in filelist:
        print('Lanzando hilo para trabajar con la imagen ' + nombre + '...')
        hilo = threading.Thread(name='hilo%s' %num_hilo, target=modifyImages, args=(nombre,))   # Creación de hilo con la función modifyImages asociada al hilo
        hilo.start()    # Inicialización de hilo
        num_hilo+=1

def cleanWrkspace(wrkspace):    # Función que limpia espacio de trabajo
    if(os.path.isdir(wrkspace)):
        print('Limpiando directorio de trabajo.')
        shutil.rmtree(wrkspace) 
        os.mkdir(wrkspace)
    else:
        print('Creando directorio de trabajo.')
        os.mkdir(wrkspace)

def modifyImages(nombre):   # Función que procesa la imagen del hilo y llama a las funciones que modifican los valores RGB de ésta
        changeR(nombre)     # Llamada a función que modifica todos los valores R de la imagen fuente en 255 y crea una nueva imagen con esta modificación
        changeG(nombre)     # Llamada a función que modifica todos los valores G de la imagen fuente en 255 y crea una nueva imagen con esta modificación
        changeB(nombre)     # Llamada a función que modifica todos los valores B de la imagen fuente en 255 y crea una nueva imagen con esta modificación
        print('Proceso de imagen ' + nombre + ' terminado.')

def changeR(nombre):        # Función que modifica la imagen fuente con valores en R de 255 y genera una nueva copia con estas modificaciones
    image = Image.open(nombre)
    pixels=image.load()
    nombre=nombre.split('.')
    for i in range(image.size[0]):    
        for j in range(image.size[1]):
            pixels[i,j]=(255,pixels[i,j][1],pixels[i,j][2],pixels[i,j][3])
    image.save(nombre[0] + '_R.png')
    image.close()

def changeG(nombre):        # Función que modifica la imagen fuente con valores en G de 255 y genera una nueva copia con estas modificaciones
    image = Image.open(nombre)
    pixels=image.load()
    nombre=nombre.split('.')
    for i in range(image.size[0]):    
        for j in range(image.size[1]):
            pixels[i,j]=(pixels[i,j][0],255,pixels[i,j][2],pixels[i,j][3])
    image.save(nombre[0] + '_G.png')
    image.close()

def changeB(nombre):        # Función que modifica la imagen fuente con valores en B de 255 y genera una nueva copia con estas modificaciones
    image = Image.open(nombre)
    pixels=image.load()
    nombre=nombre.split('.')
    for i in range(image.size[0]):    
        for j in range(image.size[1]):
            pixels[i,j]=(pixels[i,j][0],pixels[i,j][1],255,pixels[i,j][3])
    image.save(nombre[0] + '_B.png')
    image.close()

if __name__ == "__main__":
    main()