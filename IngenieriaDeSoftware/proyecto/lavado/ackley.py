#File example_ga.py
#Example of GA
#Dr. Jorge Luis Rosas Trigueros
#Last change: 12feb19


from Tkinter import *
import math
import random
#Chromosomes are 16 bits long
L_chromosome=16

#Lower and upper limits of search space
a=-2.768
b= 2.768
crossover_point=L_chromosome/2


def random_chromosome():
    chromosome=[]
    for i in range(0,L_chromosome):
        if random.random()<0.1:
            chromosome.append(0)
        else:
            chromosome.append(1)

    return chromosome

#Number of chromosomes
N_chromosomes=20
#probability of mutation
prob_m=0.5

F0=[]
fitness_values=[]

for i in range(0,N_chromosomes):
    F0.append(random_chromosome())
    fitness_values.append(0)

#binary codification
def decode_chromosome(chromosome):
    global a,b
    L_chromosome = len(chromosome)
    N_chains=2**L_chromosome
    value=0
    for p in range(L_chromosome):
        value+=(2**p)*chromosome[-1-p]

    return a+(b-a)*float(value)/(N_chains-1) #in Python3, conversion to float is not needed



def f(x):
    a = 20
    b = 0.2
    d = len(x)
    #return 0.05*x*x-4*math.cos(x)

    exp_1 = math.exp( (-b) * math.sqrt( (0.5) * sum(map(lambda xi: xi*xi, x)) ) )
    exp_2 = math.exp( (0.5) * sum(map(lambda xi: math.cos(2*math.pi*xi), x)) )
    return (-a) * exp_1 - (exp_2) + a + math.exp(1)

def evaluate_chromosomes():
    global F0
    global L_chromosome
    for p in range(N_chromosomes):
        v1=decode_chromosome(F0[p][:L_chromosome/2])
        v2=decode_chromosome(F0[p][L_chromosome/2:])
        fitness_values[p]=f((v1,v2))
        #print("f("+str(v1)+","+str(v2)+")="+str(fitness_values[p]))
        

def compare_chromosomes(chromosome1,chromosome2):
    global L_chromosome
    vc11=decode_chromosome(chromosome1[:L_chromosome/2]) 
    vc12=decode_chromosome(chromosome1[L_chromosome/2:])
    vc21=decode_chromosome(chromosome2[:L_chromosome/2])
    vc22=decode_chromosome(chromosome2[L_chromosome/2:])
    fvc1=f((vc11,vc12))
    fvc2=f((vc21,vc22))
    if fvc1 > fvc2:
        return 1
    elif fvc1 == fvc2:
        return 0
    else: #fvg1<fvg2
        return -1


suma=float(N_chromosomes*(N_chromosomes+1))/2.

Lwheel=N_chromosomes*10

def create_wheel():
    global F0,fitness_values

    maxv=max(fitness_values)
    acc=0
    for p in range(N_chromosomes):

        acc+=maxv-fitness_values[p]

    fraction=[]
    for p in range(N_chromosomes):
        fraction.append( float(maxv-fitness_values[p])/acc)
        if fraction[-1]<=1.0/Lwheel:
            fraction[-1]=1.0/Lwheel
    fraction[0]-=(sum(fraction)-1.0)/2
    fraction[1]-=(sum(fraction)-1.0)/2

    wheel=[]

    pc=0

    for f in fraction:
        Np=int(f*Lwheel)
        for i in range(Np):
            wheel.append(pc)
        pc+=1

    return wheel
        
F1=F0[:]

def nextgeneration():
 
    w.delete(ALL)
    F0.sort(cmp=compare_chromosomes)
    x1=decode_chromosome(F0[0][:L_chromosome/2])
    x2=decode_chromosome(F0[0][L_chromosome/2:])
    print( "Best solution so far:" )
    print( "f("+str(x1)+","+str(x2)+")= "+
           str(f((x1,x2))) )
                                                                    
    #elitism, the two best chromosomes go directly to the next generation
    F1[0]=F0[0]
    F1[1]=F0[1]
    for i in range(0,(N_chromosomes-2)/2):
        roulette=create_wheel()
        #Two parents are selected
        p1=random.choice(roulette)
        p2=random.choice(roulette)
        #Two descendants are generated
        o1=F0[p1][0:crossover_point]
        o1.extend(F0[p2][crossover_point:L_chromosome])
        o2=F0[p2][0:crossover_point]
        o2.extend(F0[p1][crossover_point:L_chromosome])
        #Each descendant is mutated with probability prob_m
        if random.random() < prob_m:
            o1[int(round(random.random()*(L_chromosome-1)))]^=1
        if random.random() < prob_m:
            o2[int(round(random.random()*(L_chromosome-1)))]^=1
        #The descendants are added to F1
        F1[2+2*i]=o1
        F1[3+2*i]=o2

    #graph_f()
    graph_population(F0,w,s,s,xo,yo,'red')
    graph_population(F1,w,s,s*0.5,xo,yo,'green')
    #The new generation replaces the old one
    F0[:]=F1[:]



#visualization
master = Tk()

xmax=400
ymax=400

xo=200
yo=200

s=10

w = Canvas(master, width=xmax, height=ymax)
w.pack()

            
button1 = Button(master, text="Next Generation", command=nextgeneration)
button1.pack()

N=100


def graph_f():
    xini=-20.
    xfin=20.

    dx=(xfin-xini)/N

    xold=xini
    yold=f(xold)
    for i in range(1,N):
        xnew=xini+i*dx
        ynew=f(xnew)
        w.create_line(xo+xold*s,yo-yold*s,xo+xnew*s,yo-ynew*s)
        xold=xnew
        yold=ynew

def graph_population(F,mycanvas,escalax,escalay,xcentro,ycentro,color):
    for chromosome in F:
        x=decode_chromosome(chromosome)
        mycanvas.create_line(xcentro+x*escalax,ycentro-10*escalay,xcentro+x*escalax, ycentro+10*escalay,fill=color)


#graph_f()
graph_population(F0,w,s,s,xo,yo,'red')
F0.sort(cmp=compare_chromosomes)
evaluate_chromosomes()



mainloop()
