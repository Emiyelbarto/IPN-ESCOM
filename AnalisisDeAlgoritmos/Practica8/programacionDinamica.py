#Autores: Jose Emiliano Perez Garduno, Diaz Gomez Alfredo Tonatiiuh

def VerificaArchivo(file):
	if (file.mode != 'r'):
		print("Error al abrir archivo.")
		sys.exit()

def NumLines(file):
	VerificaArchivo(file)
	for i,l in enumerate(file):
		pass
	return i+1

def ObtenerValoresArchivo(FileLocation,Valores):
	archivo = open(FileLocation,'r')
	line = archivo.readline()
	x = 0
	while line:	
		data = [y.strip() for y in line.split(',')]
		Valores[x] = int(data[1])
		line = archivo.readline()
		x += 1
	return Valores

def ObtenerGigabytesArchivo(FileLocation,GigaBytes):
	archivo = open(FileLocation,'r')
	line = archivo.readline()
	x = 0
	while line:	
		data = [y.strip() for y in line.split(',')]
		GigaBytes[x] = int(data[0])
		line = archivo.readline()
		x += 1
	return GigaBytes

FileLocation = 'datos.csv'
file = open(FileLocation,'r')
VerificaArchivo(file)
lines = NumLines(file)
Valores = [None] * lines
GigaByte = [None] * lines
informacion = [None] * lines
Valores = ObtenerValoresArchivo(FileLocation,Valores)
GigaByte = ObtenerGigabytesArchivo(FileLocation,GigaByte)
x = len(Valores)
y = 0
while(x > 0):
	informacion[y] = x
	x = x - 1
	y += 1
print(Valores)
print(GigaByte)
informacion = sorted(zip(Valores,GigaByte,informacion), key=lambda x: x[0], reverse=True)
print(type(informacion))
#print(informacion)


#informacion = [(5,3,1), (3,2,2), (1,4,3)] #(Peso, Valor, DirNum)

#print(informacion)

#informacion.sort(key=lambda tup:tup[0])

#informacion = sorted(informacion, key=lambda tup:tup[0], reverse=True)
print("(Tamanio, Valor, Numero de directorio)")
print(informacion)

tamanio = int(input("Ingresa el tamanio disponible: "))

cont = 0
contFilas = 0
tablaEstados = []

valMayor = 0
tupleMayor = tuple

for i in informacion:
    #print("Dir info: ", i)
    tablaEstados.append([])
    #print(" ")
    for j in range(1,tamanio+1):
        #print("Valor j: ",j)
        if contFilas == 0:
            if i[0] <= j:
                #print("Si cabe")
                tablaEstados[contFilas].append((i[1], i[0], [i[2]])) #(Valor, Peso total, [ListaDirectorios])
            else:
                tablaEstados[contFilas].append((0,0,[0]))
        
        else:
            if i[0] <= j:
                tablaEstados[contFilas].append((i[1], i[0], [i[2]]))

                if tablaEstados[contFilas-1][j-1][0] > tablaEstados[contFilas][j-1][0]:
                    tablaEstados[contFilas][j-1] = tablaEstados[contFilas-1][j-1]
                    #print("Arriba mayor")
                
                if tablaEstados[contFilas-1][j-1][1] + i[0] <= j:
                    #print("Aun cabe")
                    nuevaLista = tablaEstados[contFilas-1][j-1][2]
                    nuevaLista.append(i[2])
                    #print("Nueva lista: ", nuevaLista)
                    nuevaTupla = (tablaEstados[contFilas-1][j-1][0] + i[1], tablaEstados[contFilas-1][j-1][1] + i[0], nuevaLista)
                    tablaEstados[contFilas][j-1] = nuevaTupla

            else:
                tablaEstados[contFilas].append((0,0,[0])) 

        if tablaEstados[contFilas][j-1][0] > valMayor:
            valMayor = tablaEstados[contFilas][j-1][0]
            tupleMayor = tablaEstados[contFilas][j-1]

        #print("Superior: ", tablaEstados[contFilas-1])
        cont+=1
    contFilas+=1

print()
#for e in tablaEstados:
 #   print(e)
print("Valor: ", tupleMayor[0])
print("Tamanio usado: ", tupleMayor[1])
print("Directorios usados: ", tupleMayor[2])

#print("Informacion resultante: ", tupleMayor)

