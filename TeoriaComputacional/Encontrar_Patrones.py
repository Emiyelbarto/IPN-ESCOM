#!/usr/bin/python
#Autor: Jose Emiliano Perez Garduno
#Creamos la tabla de caracteres erroneos
def CrearTablaCaracteresErroneos(patron):
    Lista = {} #definimos la lista
    longitud = len(patron) #Definimos la longitud del patron
    #recorremos el string "patron"
    for i in range (0, longitud - 1):
        Lista[patron[i]] = longitud - 1 - i #Guardamos el caracter unico en la lista con su patron
        #print("Lista[patron[{}]] = {} - 1 - {} = {}".format(i,longitud,i,Lista[patron[i]]))
    print("La tabla de errores queda como: {}".format(Lista))
    return Lista #regresamos la lista de caracteres erroneos
#Definimos la funcion para encontrar las posiciones de los sufijos con el caracter erroneo, los sufijos y el patron completo
def EncontrarPosicionSufijo(caracter_malo, sufijo, patron):
    longitud_patron = len(patron) #Obtenemos longitud del patron
    longitud_sufijo = len(sufijo) #Obtenemos longitud del sufjo
    for offset in range(1, longitud_patron + 1)[::-1]: #Recorremos el patron CARACTER POR CARACTER HACIA ATRAS [::-1]
        flag = True # Definimos una bandera
        for index_sufijo in range(0, longitud_sufijo): #Recorremos el sufijo
            index_patron = offset - longitud_sufijo - 1 + index_sufijo #Definimos el index del patron
            if (index_patron > 0 or sufijo[index_sufijo] != patron[index_patron]): #Si encontramos un caracter diferente al patron
                flag = False #La bandera se cambia a falsa
        index_patron = offset - longitud_sufijo - 1 #redefinimos el index del patron como el offset - la longitud del sufijo para regesar sin perder tanto espacio
        if (flag and (index_patron <= 0 or patron[index_patron - 1] != caracter_malo)):#Si el caracter encontrado esta en la tabla de errores.
            resultado = (longitud_sufijo - offset + 1) #Definimos la posicion en la que se encontro un resultado.
            #print("Se encontro un sufijo!\n")
            return resultado #Solamente regresamos los caracteres necesarios
#Creamos la funcion para recorrer el sufijo
def CrearMovimientoSufijo(patron):
    Lista = {} #Creamos una lista donde lo guardaremos
    aux = "" #Establecemos un auxiliar
    longitud_patron = len(patron) #Obtenemos la longitud patron
    for i in range (0, longitud_patron): #Recorremos el patron
    #Gardamos el caracter donde se econtro una coincidencia en un sufijo
        Lista[len(aux)] = EncontrarPosicionSufijo(patron[longitud_patron - i - 1], aux, patron)
        aux = patron[longitud_patron - 1 - i] + aux
        #print("Caracter guardado en: [{}] = '{}'".format(aux,Lista[i]))
    return Lista

def BusquedaPatron(texto,patron):
    Sufijo_Bueno = CrearMovimientoSufijo(patron)
    Caracter_Malo = CrearTablaCaracteresErroneos(patron)
    i = 0
    while (i < len(texto) - len(patron) + 1):
        j = len(patron)
        while ( j > 0 and patron[j-1] == texto[i + j - 1]):
            j -= 1
        if( j > 0):
            MovimientoCaracterMalo = Caracter_Malo.get(texto[i+j-1], len(patron))
            #print("Movimiento Carater Erroneo: \n {}".format(Caracter_Malo.get(texto[i+j-1], len(patron))))
            MovimientoSufijoBueno = Sufijo_Bueno[len(patron) - j]
            if(MovimientoCaracterMalo > MovimientoSufijoBueno):
                i += MovimientoCaracterMalo
                #print("Nos movemos {} caracteres".format(i))
            else:
                i += MovimientoSufijoBueno
                #print("Nos movemos {} caracteres".format(i))
        else:
            return i
    return -1

def main():
    print("Busqueda de patrones por medio de Boyer-Moore\n")
    texto = input("Escribir el texto: ")
    patron = input("Escribir el patron: ")
    resultado = BusquedaPatron(texto,patron)
    if(resultado > 0):
        print("El texto '{}' contiene al patron '{}' en la posicion[{}]:".format(texto, patron, resultado,))
        print("{}[{}]{}".format(texto[:resultado],texto[resultado:resultado+len(patron)],texto[resultado+len(patron):]))
    else:
        print("Patron no encontrado en el texto.")
main()
