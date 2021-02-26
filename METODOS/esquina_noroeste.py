
def getValores(nombre, valores):
    if (valores == None):
        while True:
            try:
                n = int(input(f"Introducir el numero de {nombre}\n"))
                break
            except:
                print('Introducir un numero')
        lista = []

        for x in range(n):
            nom = input(f'Escribir el {nombre} {x + 1}\n')
            lista.append(nom)

        print(f'{nombre}: {lista}')
        return lista
    
    else:
        lista = []
        for x in range(len(valores)):
            while True:
                try:
                    n = int(input(f'Escribir el valor de la {nombre} para {valores[x]}\n'))
                    lista.append(n)
                    break
                except:
                    print('Introducir un numero')
        print(f'{nombre}: {lista}')
        return lista

def printValores(valores):
    for x in range (len(valores[1]) + 2):
        if x == 0:
            print(f'\nOrigenes / Destinos', end="\t")
            for y in range(len(valores[0])):
                print(f'{valores[0][y]}', end="\t")
            print(f'Oferta')
        elif x == (len(valores[1]) + 1):
            print(f'Demanda', end="\t")
            # for y in range()
        else:
            print(f'{valores[1][x-1]}\t', end="\t")
            for y in range(len(valores[4])):
                print(f'{valores[4][y]}', end="\t")
            print(f'{valores[3][x-1]}',end="\n")
        


def getPrecios(origenes, destinos):
    precios = []
    print(f'origenes: {origenes}')
    print(f'destinos: {destinos}')
    for x in range(len(destinos)):
        for y in range(len(origenes)):
            while True:
                try:
                    precio = int(input(f'Escribir el precio de {origenes[y]} a {destinos[x]}\n'))
                    precios.append(precio)
                    break
                except:
                    print('Introducir un numero')
    return precios


def getInputs():
    valores = []
    destinos = getValores('destinos', None)
    origenes = getValores('origenes', None)
    demanda = getValores('demanda', destinos)
    oferta = getValores('oferta', origenes)
    precios = getPrecios(origenes, destinos)
    valores.append(destinos) #Valores0
    valores.append(origenes) #Valores1
    valores.append(demanda) #Valores2
    valores.append(oferta) #Valores3
    valores.append(precios) #Valores4
    return valores

def esquinaNoroeste(valores):
    noroeste = valores

def main():
    print("Metodo de la esquina noroeste")
    # print('', end = '\t')
    # print('\t\tDestino')
    # print('\n\nSilo')
    valores = getInputs()
    printValores(valores)

if __name__ == "__main__":
    main()
