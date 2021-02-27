import sys
ABAJO=0
ARRIBA=1
VACIO=0
NO_VACIO=1
ESTATUS_ABAJO=0
ESTATUS_ARRIBA=0
TIEMPO_ARRIBA=0.0
TIEMPO_ABAJO=0.0
UBICACION_PLATAFORMA=ABAJO
###
#Las variables ABAJO y ARRIBA indican la posición en la que se encuentra la plataforma.
#La variable PlataformaVacia indica si la plataforma tiene o no un carro encima.
#
###
def main():
    AGENTE_ESTACIONAMIENTO_REACTIVO_SIMPLE(ABAJO,ESTATUS_ARRIBA,ESTATUS_ABAJO,TIEMPO_ARRIBA,TIEMPO_ABAJO)

def estacionarVehiculo(statusArriba,statusAbajo,TiempoArriba,TiempoAbajo,tiempo_actual):
    global ABAJO,ARRIBA,VACIO,NO_VACIO,ESTATUS_ABAJO,ESTATUS_ARRIBA,TIEMPO_ARRIBA,TIEMPO_ABAJO,UBICACION_PLATAFORMA
    if(ESTATUS_ABAJO==NO_VACIO and ESTATUS_ARRIBA==NO_VACIO):
        print("NO SE PUEDE ESTACIONAR, LOS LUGARES ESTAN LLENOS")
        return
    if(UBICACION_PLATAFORMA==ABAJO and statusArriba==VACIO):##ESTADO INICIAL.
        print("ESTACIONANDO VEHICULO EN LA PARTE DE ARRIBA")
        ESTATUS_ARRIBA=NO_VACIO
        TIEMPO_ARRIBA=tiempo_actual
    else:
        if(UBICACION_PLATAFORMA==ABAJO and TiempoArriba>tiempo_actual):##INDICA QUE LA PLATAFORMA ESTA ABAJO PERO YA TIENE UN CARRO SOBRE ELLA
            print("Levantando la  plataforma")
            print("Estacionando vehículo en la parte de abajo")
            UBICACION_PLATAFORMA=ARRIBA
            TIEMPO_ABAJO=tiempo_actual
            ESTATUS_ABAJO=NO_VACIO
        else:
            print ("No se puede estacionar porque el Tiempo del de arriba es menor que el de abajo")

def liberarVehiculo(statusArriba,statusAbajo,TiempoArriba,TiempoAbajo,posicion):
    #posicion=1 Arriba
    #posicion=2 Abajo
    Arriba=1
    Abajo=2
    global ABAJO,ARRIBA,VACIO,NO_VACIO,ESTATUS_ABAJO,ESTATUS_ARRIBA,TIEMPO_ARRIBA,TIEMPO_ABAJO,UBICACION_PLATAFORMA
    print("Iniciando la liberación de un vehículo")
    if(UBICACION_PLATAFORMA==ARRIBA):
        if(posicion==Arriba):
            if(ESTATUS_ABAJO==NO_VACIO):
                print("NO SE PUEDE LIBERAR, HAY UN CARRO ABAJO")
            else:
                print("BAJANDO LA PLATAFORMA")
                print("LIBERANDO EL AUTO DE ARRIBA")
                ESTATUS_ARRIBA=VACIO
                UBICACION_PLATAFORMA=ABAJO
                TIEMPO_ARRIBA=0.0
        else:##d
            if(ESTATUS_ABAJO==NO_VACIO):
                print("LIBERANDO CARRO DE ABAJO")
                ESTATUS_ABAJO=VACIO
                TIEMPO_ABAJO=0.0
                UBICACION_PLATAFORMA=0
    else:
        if(posicion==Arriba):
            if(ESTATUS_ARRIBA==VACIO):
                print("No HAY CARRO ARRIBA")
            else:
                print("BAJANDO LA PLATAFORMA")
                print("LIBERANDO AUTO DE ARRIBA")
                TIEMPO_ARRIBA=0.0
                ESTATUS_ARRIBA=VACIO
                ESTATUS_ABAJO=VACIO
                UBICACION_PLATAFORMA=ABAJO
        else:
            print("No hay carro abajo")
    print("Terminando la liberación de un vehículo")

def AGENTE_ESTACIONAMIENTO_REACTIVO_SIMPLE(ubicacion,statusArriba,statusAbajo,TiempoArriba,TiempoAbajo):
    print("Iniciando Agente")
    while True :
        option=chooseOption()
        if(option==1):
            tiempo=getTiempo()
            estacionarVehiculo(ESTATUS_ARRIBA,ESTATUS_ABAJO,TIEMPO_ARRIBA,TIEMPO_ABAJO,tiempo)
        else:
            option2=chooseOptionLiberar()
            liberarVehiculo(ESTATUS_ARRIBA,ESTATUS_ABAJO,TIEMPO_ARRIBA,TIEMPO_ABAJO,option2)
        print ("******************************************************************************")
    print("Terminando Agente")

def getTiempo():
    tiempo=float(input("Ingresa el Tiempo que ocuparas el lugar:"))
    return tiempo

def chooseOption():
    try:
        print("(1) Estacionar Auto")
        print("(2) Sacar auto")
        option=int(input('Input:'))
    except ValueError:
        print ("Not a number")
    except KeyboardInterrupt:
        sys.exit()
    return option

def chooseOptionLiberar():
    try:
        print("¿Qué acción deseas realizar?")
        print("(1) Arriba ")
        print("(2) Abajo")
        option=int(input('Input:'))
    except ValueError:
        print ("Not a number")
    except KeyboardInterrupt:
        sys.exit()
    return option

if __name__ == "__main__":
    main()