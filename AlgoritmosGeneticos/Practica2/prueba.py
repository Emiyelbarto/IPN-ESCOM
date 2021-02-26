#!/usr/bin/python
import random
import unicodedata
import re
#Codigo realizado por Jose Emiliano para la materia de Algoritmos Geneticos 3CM8

def GenerarBitAleatorio():
    x = random.random()
    #print(x)
    if x > 0.5:
        #print("El valor es mayor a .5, asi que es 1")
        return 1
    else:
        #print("El valor es menor a .5, asi que es 0")
        return 0

def GenerarNumeroAleatorio(rango):
    num = []
    aux = '';
    for x in range(0,rango):
        #print("de {} a rango {}".format(x,rango))
        aux = aux + str(GenerarBitAleatorio())
        #num.append(GenerarBitAleatorio())
    num = int(aux)
    return num

def EsEntero(valor):
    patron = re.compile(r"^[0-9][0-9]*\.?[0-9]*")
    flag = re.search(patron, valor)
    if flag:
        return True
    else:
        return False
    
def VerificarInputNumListas():
    flag = False
    while not flag:
        num = raw_input("Introducir un numero par de arreglos para crear\n")
        flag = EsEntero(num)
        if (flag == False):
            print("Introducir un numero entero")
        else:
            num = int(num)
            if ((num % 2) == 0):
                return num
            else:
                print("Introducir un numero par")
                flag = False

def VerificarInputTamano(i):
    flag = False
    while not flag:
        print("Introducir el tamano de la lista "+str(i+1))
        longitud = raw_input()
        flag = EsEntero(longitud)
        if (flag == False):
            print("Introducir un numero entero")
        else:
            longitud = int(longitud)
            if(longitud > 9 and longitud < 301):
                flag = True
                return longitud
            else:
                print("Introducir un valor entre 10 y 300")
                flag = False

def VerificarInputRango(i):
    flag = False
    while not flag:
        print("Introducir el rango de la lista " + str(i + 1)+ "\n (0 -> n) (maximo 300) en entero")
        rango = raw_input()
        flag = EsEntero(rango)
        if (flag == False):
            print("Introducir un numero entero")
            flag = False
        else:
            flag = True
            rango = int(rango)
    return rango

def CrearLista(i):
    longitud = VerificarInputTamano(i)
    rango = VerificarInputRango(i)
    Lista = []
    for x in range (0 , longitud):
        a = GenerarNumeroAleatorio(rango)
        Lista.append(a)
    return Lista

def PoblarLista(L,x):
    aux = []
    aux = CrearLista(x)
    L.append(aux)
    return L

def ImprimirLista(L):
    for x in range (0,4):
        print("Lista[{}] = [".format(x+1)),
        for y in range (0,len(L[x])):
            if (y == len(L[x])-1):
                print(L[x][y]),
            else:
                print(L[x][y]),
                print(","),
        print("]\n")

def FuncionBinario(L):
    for y in range (0 , len(L)):
        for x in range (0 , len(L[y])):
            L[y][x] = int(str(L[y][x]),2)
    return L

def FuncionGray(L):
    aux = L
    for y in range(0,len(L)):
        for x in range(0,len(L[y])):
            aux[y][x] ^= (aux[y][x] >> 1)
            aux[y][x] = bin(int(aux[y][x]))[2:]
    return aux



def CrearArreglos(L):
    num = VerificarInputNumListas()
    for x in range(0,num):
        L = PoblarLista(L,x)
    return L
    

def main():
    print("Jose Emiliano Perez Garduno")
    print("********Practica 2********")
    Decimales = []
    Binarios = [[010,010,0110,0100],[101,101,1001,1011],[010,010,0110,0100],[101,101,1001,1011]]
    Gray = []
    '''
    Decimales = CrearArreglos(Decimales)
    Decimales = PoblarLista(Binarios,4)
    print("Todas las listas quedan como: \n")
    ImprimirLista(Binarios)
    print("Todas las listas en decimal quedan como:\n")
    Decimales = FuncionBinario(Binarios)
    ImprimirLista(Decimales)
    '''
    ArreglosGray = FuncionGray(Binarios)
    print("\nTodas las listas en codigo gray quedan como:\n")
    ImprimirLista(ArreglosGray)
    
if __name__ == '__main__':
    main()
