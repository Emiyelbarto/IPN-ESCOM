import math

# La condicion necesaria y suficiente para que un entero positivo "r1" tenga inverso multiplicativo
# modulo r0 es la siguiente: mcd(r0, r1) = 1

# r0 = q1 * r1 + r2
# r1 = q2 * r2 + r3
# mcd(r0,r1) = rm
# rm-2 = qm-1 rm-1 + rm
# rm-1 = qm rm
q1 = 1
r0 = int(input("Introducir r0\n"))
r1 = int(input("Introducir r1\n"))
while(r0 < r1):
    r1 = int(input("r1 debe de ser mayor a r0, introducir otro número\n"))
inicial = r1
mcd = r0
r2 = r0 - r1
i = 0
while(r0 > 0):
    print("r{} = {} * {} + {}", r0, q1, r1, r2)
    i = i + 1
    r0 = (q1) * r1 + r2
    r1

if(r0 == 1):
    print("El número {} tiene inverso comun divisor con {}".format(inicial, mcd))
else:
    print("El número {} no tiene inverso comun divisor con {}".format(inicial, mcd))
