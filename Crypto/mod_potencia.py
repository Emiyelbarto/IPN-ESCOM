from decimal import Decimal
mult = int(input("Introducir el numero a multiplicar\n"))
num = int(input("Introducir el número a calcular el módulo\n"))
potencia = int(input("Introducir la potencia a la que se elevara el num\n"))
modular = int(input("Introducir el módulo\n"))

elevado = num ** potencia

res = (elevado * mult) % modular

decimal = '%.2E' % Decimal(elevado)

print("{} mod {} = {}, donde {}^{} = {}".format(num,modular,res,num,potencia,decimal))