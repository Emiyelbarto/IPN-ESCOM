#!/usr/bin/python
#Codigo realizado por Jose Emiliano para la materia de Algoritmos Geneticos 3CM8
import re
import random

#Crea un bit aleatorio a partir de una probabilidad de 1/2
def CrearBinarioAleatorio():
    x = random.random()
    return 1 if x > 0.5 else 0

#Crea un numero aleatorio del rango de bits indicado por el usuario
def CrearNumAleatorio(rango):
    num = 0
    aux = '';
    for x in range(0,rango):
        aux = aux + str(CrearBinarioAleatorio())
    num = int(aux)
    return num

#crea arreglo de binarios que seran poblados
def CrearBinarios():
    tam_array = VerificacionInputListas()
    print("Introducir el numero de conjuntos que habra"),
    tam_conjunto = VerificacionInputEntero()
    Binario = [None] * tam_array
    print("Introducir el rango de bits que tendra"),
    rango_bits = VerificacionInputEntero()
    for y in range(0,tam_array):
        aux = [None] * tam_conjunto
        for x in range(0,tam_conjunto):
            a = CrearNumAleatorio(rango_bits)
            aux[x] = a
        Binario[y] = aux
    return Binario

def PoblarArregloDecimal():
    min_range = input("Introducir el limite menor de generacion.\n")
    max_range = input("Introducir el limite mayor de generacion.\n")
    longitud = input("Introducir el numero de objetos que generara.\n")
    Decimal = [None] * longitud
    for x in range (0,longitud):
        Decimal[x] = random.uniform(min_range,max_range)
    return Decimal

#Crea el arreglo de decimales a partir del arreglo de binario ya creado
'''
def TransformarBinarioDecimal(Binario):
    Decimal = [None] * len(Binario)
    aux = []
    for y in range (0, len(Binario)):
        for x in range(0,len(Binario[y])):
            aux.append(int(str(Binario[y][x]),2))
        Decimal[y] = aux
        aux = []
    return Decimal
'''

#Crea el arreglo de codigo gray a partir del arreglo de binarios ya creado    
def TransformarBinarioGray(Binario):
    Gray = [] * len(Binario)
    for y in range(0,len(Binario)):
        aux = [] * len(Binario[y])
        for x in range(0,len(Binario[y])):
            a = int(str(Binario[y][x]),2)
            a ^= (a >> 1)
            a = bin(a)[2:]
            aux.append(a)
        Gray.append(aux)
    return Gray
    
#Verifica que el numero introducido por el usuario sea un entero
def VerificacionInputEntero():
    flag = False
    while not flag:
        n = raw_input("con un numero entero\n")
        patron = re.compile(r"^[0-9][0-9]*\.?[0-9]*")
        flag = re.search(patron, n)
    return int(n)
        
#Verifica que el numero sea entero y par
def VerificacionInputListas():
    flag = False
    while not flag:
        n = raw_input("Introducir el numero de arreglos que habra (debe ser par)\n")
        patron = re.compile(r"^[0-9][0-9]*\.?[0-9]*")
        flag = re.search(patron, n)
        if flag:
            if int(n) % 2 == 0:
                return int(n)
            else:
                flag = False
    
#Imprime todas las listas
def ImprimirTodo(Binario,Decimal,Gray):
    print("Los elementos en binario son: ")
    for y in range (0,len(Binario)):
        print("L[{}] = [".format(y)),
        for x in range (0,len(Binario[y])):
            if x == len(Binario[y]) - 1:
                print("{}".format(Binario[y][x])),
            else:
                print("{}, ".format(Binario[y][x])),
        print("]\n")

    print("Los elementos en Gray son: ")
    for y in range (0, len(Gray)):
        print("L[{}] = [".format(y)),
        for x in range (0,len(Gray[y])):
            if x == len(Gray[y]) - 1:
                print("{}".format(Gray[y][x])),
            else:
                print("{},".format(Gray[y][x])),
        print("]\n")
        
    print("Los elementos creados en decimal son: ")
    print("Decimal = ["),
    for y in range (0, len(Decimal)):
        if y == len(Decimal) - 1:
            print("{0:.2f}".format(Decimal[y])),
        else:
            print("{0:.2f},".format(Decimal[y])),
    print("]\n")

def main():
    print("Jose Emiliano Perez Garduno")
    print("********Practica 2********")

    Binarios = CrearBinarios()
    Decimal = PoblarArregloDecimal()
    Gray = TransformarBinarioGray(Binarios)
    ImprimirTodo(Binarios,Decimal,Gray)
    
    
if __name__ == '__main__':
    main()
