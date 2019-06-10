#!/usr/bin/python
from __future__ import print_function
#Programa realizado por Jose Emiliano Perez Garduno
def imprimir_menu():
    print("\n\n***Menu de seleccion***\n")
    print("1.-Escribir cuadros adyacentes")
    print("2.-Mostrar cuadros adyacentes")
    print("3.-Calcular Resultado")
    print("4.-Imprimir Resultado")
    print("0.-Salir")


def crear_cuadro():
    adyacentes = [None] * 8
    adyacentes[0] = input("Introducir el valor del cuadro izquierdo superior\n")
    adyacentes[1] = input("Introducir el valor del cuadro superior\n")
    adyacentes[2] = input("Introducir el valor del cuadro superior derecho\n")
    adyacentes[3] = input("Introducir el valor del cuadro izquierdo\n")
    adyacentes[4] = input("Introducir el valor del cuadro derecho\n")
    adyacentes[5] = input("Introducir el valor del cuadro izquierdo inferior\n")
    adyacentes[6] = input("Introducir el valor del cuadro inferior\n")
    adyacentes[7] = input("Introducir el valor del cuadro derecho inferior\n")
    return adyacentes

def imprimir_cuadro(adyacentes):
    print("Se imprimiran los cuadros adyacentes:\n")
    for numeros in range(0,len(adyacentes)):
        if(numeros == 3):
            print("\n")
        if(numeros == 4):
            print("x\t{}\n\n".format(adyacentes[numeros]), end="")
        else:
            print("{}\t".format(adyacentes[numeros]), end="")

def calculo(resultados, adyacentes):
    if (adyacentes[0] == "0"):
        resultados[0] = 0
        resultados[1] = (float(adyacentes[1])**2 + float(adyacentes[3])**2 / 2)
        resultados[5] = (float(adyacentes[1])**2 + float(adyacentes[3])**2 / 2)
    else:
        resultados[0] = 10
        resultados[1] = 10 - (int(adyacentes[1]) + int(adyacentes[3]) / 2)
        resultados[5] = 10 - (int(adyacentes[1]) + int(adyacentes[3]) / 2)

    if (adyacentes[2] == "0"):
        resultados[4] = 0
        resultados[3] = (int(adyacentes[1])**2 + int(adyacentes[4])**2 / 2)
        resultados[9] = (int(adyacentes[1])**2 + int(adyacentes[4])**2 / 2)
    else:
        resultados[4] = 10
        resultados[3] = 10 - (int(adyacentes[1])**2 + int(adyacentes[4])**2 / 2)
        resultados[9] = 10 - (int(adyacentes[1])**2 + int(adyacentes[4])**2 / 2)

    if (adyacentes[5] == "0"):
        resultados[20] = 0
        resultados[15] = (int(adyacentes[3])**2 + int(adyacentes[5])**2 / 2)
        resultados[21] = (int(adyacentes[3])**2 + int(adyacentes[5])**2 / 2)
    else:
        resultados[20] = 10
        resultados[15] = 10 - (int(adyacentes[3])**2 + int(adyacentes[5])**2 / 2)
        resultados[21] = 10 - (int(adyacentes[3])**2 + int(adyacentes[5])**2 / 2)

    if (adyacentes[7] == "0"):
        resultados[24] = 0
        resultados[23] = (int(adyacentes[6])**2 + int(adyacentes[4])**2 / 2)
        resultados[19] = (int(adyacentes[6])**2 + int(adyacentes[4])**2 / 2)
    else:
        resultados[24] = 10
        resultados[23] = 10 - (int(adyacentes[6])**2 + int(adyacentes[4])**2 / 2)
        resultados[19] = 10 - (int(adyacentes[6])**2 + int(adyacentes[4])**2 / 2)

    if(resultados[0] == 0 and resultados[1] == 0 and resultados[5] == 0):
        resultados[2] = 0
    else:
        resultados[2] = 10 - ((resultados[0] + resultados[1] + resultados[5]) / 3)

    if(resultados[4] == 0 and resultados[3] == 0 and resultados[9] == 0):
        resultados[10] = 0
    else:
        resultados[10] = 10 - ((resultados[4] + resultados[3] + resultados[9]) / 3)

    if(resultados[20] == 0 and resultados[15] == 0 and resultados[21] == 0):
        resultados[14] = 0
    else:
        resultados[14] = 10 - ((resultados[20] + resultados[15] + resultados[21]) / 3)

    if(resultados[24] == 0 and resultados[23] == 0 and resultados[19] == 0):
        resultados[22] = 0
    else:
        resultados[22] = 10 - ((resultados[24] + resultados[23] + resultados[19]) / 3)

    resultados[6] = int(adyacentes[0])
    resultados[7] = int(adyacentes[1])
    resultados[8] = int(adyacentes[2])
    resultados[11] = int(adyacentes[3])
    resultados[12] = "x"
    resultados[13] = int(adyacentes[4])
    resultados[16] = int(adyacentes[5])
    resultados[17] = int(adyacentes[6])
    resultados[18] = int(adyacentes[7])

    return resultados

def crear_cuadro_resultado(adyacentes):
    print("\n\nCalculando resultados")
    resultados = [10] * 25
    calculo(resultados, adyacentes)
    return resultados


def imprimir_cuadro_resultado(resultados,adyacentes):
    print("\nSe imprimira la probabilidad de que cada cuadro contenga una mina.")
    for numeros in range(0,25):
        if(numeros % 5 == 0):
            print("\n")
        if(numeros == 12):
            print("{}\t".format(resultados[numeros]), end="")
        else:
            print("%.1f\t"%resultados[numeros], end="")

def main():
    print("Programa para calcular el mejor camino para buscaminas.")
    opc = True
    valores = False
    res = False
    while opc:
        imprimir_menu()
        opc = input("Seleccionar opcion:\n")
        if opc == "1":
            print("Favor de introducir los valores mostrados:")
            adyacentes = crear_cuadro()
            valores = True
        elif opc == "2":
            if valores:
                imprimir_cuadro(adyacentes)
            else:
                print("\n**Favor de introducir los valores antes**\n")
                opc = "1"
        elif opc == "3":
            if valores:
                resultados = crear_cuadro_resultado(adyacentes)
                res = True
            else:
                print("\n**Favor de introducir los valores antes**\n")
                opc = "1"
        elif opc == "4":
            if valores and res:
                imprimir_cuadro_resultado(resultados,adyacentes)
            else:
                if valores == False:
                    print("\n**Favor de introducir los valores antes**\n")
                elif res == False:
                    print("\n**Favor de calcular los valores antes**\n")
        elif opc == "0":
            print("Saliendo del programa.")
            opc = False
        elif opc !="":
            print("Opcion no valida, favor de escoger de nuevo.")

main()
