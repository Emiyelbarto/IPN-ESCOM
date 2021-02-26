#!/usr/bin/python
#Codigo realizado por Jose Emiliano para la materia de Algoritmos Geneticos 3CM8
import re
import random

def FuncionFitness(n):
    x = n * n
    return x

def CalcularLongBinaria(n):
    long_bit = n.bit_length()
    max_bit = 2 ** long_bit
    print("La longitud maxima del rango es: 2^{}={}".format(long_bit,max_bit))
    return long_bit

def CalcularProbabilidad(prob):
    x = random.random()
    return 1 if x < prob else 0

def GuardarNumAleatorio(arreglo,x):
    arreglo.append(x)
    return arreglo

#Crea un bit aleatorio a partir de una probabilidad de 1/2

def RegresarBitAleatorio(x):
    return 1 if x > 0.5 else 0

#Crea un numero aleatorio del rango de bits indicado por el usuario
def CrearNumAleatorio(rango,arreglo):
    aux = ''
    num = 0
    for x in range(0,rango):
        rand = random.random()
        arreglo.append(rand)
        #print("Guardo el numero {} de la iteracion {}".format(rand,x))
        aux = aux + str(RegresarBitAleatorio(rand))
    num = int(aux)
    arreglo.append(num)
    return arreglo

def VerificacionINT(str):
    try:
        value = int(str)
        print(value)
        flag = True
    except ValueError:
        print("Escoger un numero entero positivo")
        flag = False
    return flag

def BinarioADecimal(n):
    for x in range(0,len(n)):
        n[x] = int(n[x])
    return int(str(n[0]),2)

def OpcionFitness():
        print("Se realizara la funcion fitness")
        flag = False
        while(flag == False):
            user_input = input("Indicar el limite inferior del rango\n")
            flag = VerificacionINT(user_input)
            if flag == True:
                lim_inf = int(user_input)
        flag = False
        while(flag == False):
            user_input = input("Indicar el limite superior del rango\n")
            flag = VerificacionINT(user_input)
            if flag == True:
                lim_sup = int(user_input)
                if(lim_sup <= lim_inf):
                    print("Escoger un limite superior mayor que al menor")
                    flag = False
        flag = False
        while(flag == False):
            user_input = input("Indicar el numero de individuos\n")
            flag = VerificacionINT(user_input)
            if(flag == True):
                num_individuos = int(user_input)
                if(num_individuos % 2 == 0):
                    flag = True
                else:
                    print("El numero de individuos debe ser par")
                    flag = False

        max_bit = CalcularLongBinaria(lim_sup)
        print("Se crearan {0:.0f} pares de individuos".format(num_individuos/2))
        
        conjunto_individuos = [None] * num_individuos
        arreglo_num_aleatorios = []

        for y in range(0,num_individuos):
            aux = [None] * (lim_sup-lim_inf)
            a = CrearNumAleatorio(max_bit,arreglo_num_aleatorios)
            arreglo_num_aleatorios = [item for item in a if isinstance(item,float)]
            a = [item for item in a if isinstance(item,int)]            
            aux = a
            conjunto_individuos[y] = aux

        print("El conjunto de individuos queda como:")
        for x in range(0,num_individuos):
            print(conjunto_individuos[x],end=',')
        print("\n")
        print("El conjunto de numeros aleatorios queda como:")
        for x in range(0,len(arreglo_num_aleatorios)):
            print("{0:.2f}".format(arreglo_num_aleatorios[x]),end=',')
        print("\n")

        flag = False
        while(flag == False):
            user_input = input("Indicar la probabilidad de cruza[0-100]\n")
            flag = VerificacionINT(user_input)
            if(flag == True):
                prob_cruce = int(user_input)
                if(prob_cruce <= 0):
                    print("Introducir un numero mayor a 0")
                    flag = False
                else:
                    prob_cruce = prob_cruce / 100
                    flag = True
                    break

        print("La probabilidad de cruce es: {}".format(prob_cruce))
        
        flag = False
        while(flag == False):
            user_input = input("Indicar la probabilidad de mutacion[0-100]\n")
            flag = VerificacionINT(user_input)
            if(flag == True):
                prob_mut = int(user_input)
                if(prob_mut <= 0):
                    print("Introducir un numero mayor a 0")
                    flag = False
                else:
                    prob_mut = prob_mut / 100
                    break
        
        print("La probabilidad de mutacion es: {}".format(prob_mut))
        print("No. Cadena\tPoblacion Inicial\tValor x\t\tAptitud f(x)\tProb i\tProb Acumulada\tPadres Elegidos")
        array_aptitud = [None] * num_individuos
        array_prob = [None] * num_individuos
        for y in range (0,num_individuos):
            bin_decimal = BinarioADecimal(conjunto_individuos[y])
            fit_decimal = FuncionFitness(bin_decimal)
            array_aptitud[y] = fit_decimal
        suma_aptitud = sum(array_aptitud)
        promedio_aptitud = suma_aptitud/num_individuos
        max_aptitud = max(array_aptitud)
        prob_acum = 0
        for y in range (0,num_individuos):
            bin_decimal = BinarioADecimal(conjunto_individuos[y])
            fit_decimal = FuncionFitness(bin_decimal)
            array_prob[y] = array_aptitud[y] / suma_aptitud
            print("{}\t\t{}\t\t\t{}\t\t{}".format(y+1,conjunto_individuos[y],bin_decimal,fit_decimal),end='\t\t')
            print("{0:.2f}".format(array_prob[y]),end='\t')
            prob_acum = prob_acum + array_prob[y]
            print("{0:.2f}".format(prob_acum))
        print("Suma\t\t\t\t\t\t\t{}".format(suma_aptitud))
        print("Promedio\t\t\t\t\t\t{}".format(promedio_aptitud))
        print("Max\t\t\t\t\t\t\t{}".format(max_aptitud))     

def OpcionGeneralizacional():
    print("Se realizara la Generalizacional")

def OpcionElitista():
    print("Se realizara la funcion Elitista")

def menu():
    opc = -1
    while (opc > 3 or opc < 0):
        print("1.-Funcion Fitness")
        print("2.-Generalizacional")
        print("3.-Elitista")
        print("0.-Salir")
        opc = int(input("Escoger opcion\n"))
    
    if(opc == 1):
        #Función Fitness 
        OpcionFitness()

    elif(opc == 2):
        #Generalizacional
        OpcionGeneralizacional()
    elif(opc == 3):
        #Elitista
        OpcionElitista()
    elif(opc == 0):
        print("Adios")
        return 0

def main():
    print("Jose Emiliano Perez Garduno")
    print("********Practica 3********")
    menu()

if __name__ == '__main__':
    main()