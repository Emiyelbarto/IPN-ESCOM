def verifyIntInput(str):
    while True:
        try:
            val = input(f'{str}\n')
            val = int(val)
            break
        except:
            print('Error al introducir datos')
    return val


def inputTeclado():
    data = input('Introducir la cadena a evaluar en el automata\n')
    return data


def nombreArchivo(fileNum):
    print(f'Abriendo archivo {fileNum}')
    nomFile = 'AFN' + str(fileNum) + '.txt'
    return nomFile


def dataInput():
    data = inputTeclado()
    print(f'Cadena a evaluar: {data}')
    return data


def verifyLenguaje(cad, automata):
    print('Se verificara el lenguaje introducido', end=": ")
    error = 0
    lenguaje = automata[1]
    for char in cad:
        if char in lenguaje:
            # print(f'Caracter "{char}" valido')
            error = error
        else:
            print(f'Caracter "{char}" no valido')
            error = 1

    if error == 0:
        return True

    return False


def contarLineasArchivo(data):
    count = 0
    for line in data:
        count += 1 
    return count


def crearAutomata():
    automata= []
    sel = verifyIntInput(
        'Escoger archivo desde el cual se escogera el automata:\n1.-AFN1\n2.-AFN2')
    nomFile = nombreArchivo(sel)
    delta = []
    for i, line in enumerate(open(nomFile)):
        #Conseguimos estados
        if(i == 0):
            aux = line[:-1]
            estados = aux.split(',')
        elif(i == 1):
            aux = line[:-1]
            lenguaje = aux.split(',')
        elif(i == 2):
            aux = line[:-1]
            inicial = aux.split(',')
        elif(i == 3):
            aux = line[:-1]
            final = aux.split(',')
        else:
            if('\n' in line):
                aux = line[:-1]
                delta.append(aux.split(','))
    automata.append(estados)
    automata.append(lenguaje)
    automata.append(inicial)
    automata.append(final)
    automata.append(delta)
    print(f'Automata: {automata}')
    return automata

def recorrerAutomata(cadena, automata):
    print(f'Se recorrera el automata con la cadena "{cadena}"')
    transicion = []
    deltas = automata[4]
    state = automata[2][0]
    res = []
    delta_aux = []
    for char in cadena:
        # print(f'Recorro automata con caracter: {char}')
        for delta in deltas:
            if(delta[0] == state):
                if(char in delta):
                    # print(f'delta valido {delta} con caracter {char} valido')
                    state_aux = 'q' + str(delta[2])
                    if(state_aux in delta_aux):
                        state_aux = ''
                    else:
                        delta_aux.append(state_aux)
                    if(state != delta[2]):
                        # print(f'Siguiente estado: {delta[2]}')
                        state = delta[2]
                        break
                    
    print(f'Estado final: {delta_aux}')

def main():
    automata = crearAutomata()
    cadena = dataInput()
    while(verifyLenguaje(cadena, automata) == False):
        cadena = dataInput()
    print('El lenguaje introducido es valido')
    recorrerAutomata(cadena,automata)


if __name__ == '__main__':
    main()
