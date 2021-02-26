#!/usr/bin/python3
#Programa realizado por Victor Anaya Martinez, Emiliano Pérez y Mauricio Meléndez
from numpy.random import seed
from numpy.random import randint
import threading

def main():
    seed()
    menu()

def menu():
    flag = 0
    while (flag != -1):
        print("***\tPrograma B Practica 1\t***")
        opc = validateIntInput("\tOpciones:\n[1]2 Hilos\n[2]4 Hilos\n[3]8 Hilos\n[4]16 Hilos\n[5]32 Hilos\n")
        A = crearMatrices(2,2)
        B = crearMatrices(2,2)
        if opc == 1:
            numHilos = 2
        elif opc == 2:
            numHilos = 4
        elif opc == 3:
            numHilos = 8
        elif opc == 4:
            numHilos = 16
        elif opc == 5:
            numHilos = 32
        C = operacionMatrices(A,B,numHilos)
        opc = validateIntInput('Realizar otro calculo?\n[1]Si\n[2]No\n')
        if(opc == 2):
            break

def validateIntInput(message):  # Validación de la opción ingresada
    while True:
        try:
            tryUserInput = int(input(message))
        except ValueError:
            print('El valor introducido no es valido, intentar de nuevo.\n')
            continue
        else:
            return tryUserInput

def crearMatrices(fila, columna):
    matriz = []
    for i in range(fila):
        listaFilas = []
        for j in range(columna):
            listaFilas.append(randint(0,5))
        matriz.append(listaFilas)
    print('Matriz creada: \n')
    imprimirMatriz(matriz)
    return matriz

def alocarMatriz(fila, columna):
    matriz = []
    for i in range(fila):
        listaFilas = []
        for j in range(columna):
            listaFilas.append(0)
        matriz.append(listaFilas)
    return matriz


def operacionMatrices(matrizA, matrizB, numHilos):
    print('Realizando multiplicacion de matrices con {} hilos.\n'.format(numHilos))
    filasA = len(matrizA)
    colsA = len(matrizA[0])
    colsB = len(matrizB[0])
    res = alocarMatriz(filasA, colsB)
    for i in range(filasA):
        for j in range(colsB):
            total = 0
            for k in range(colsA):
                total += matrizA[i][k] * matrizB[k][j]
            res[i][j] = total
    print('Matriz resultante: \n')
    imprimirMatriz(res)
    return res

def imprimirMatriz(matriz):
    filas = len(matriz)
    for i in range(filas):
        col = len(matriz[i])
        for j in range(col):
            if(j == col - 1):
                print('{}\n'.format(matriz[i][j]))
            else:
                print('{}'.format(matriz[i][j]), end=' ')

if __name__ == "__main__":
    main()