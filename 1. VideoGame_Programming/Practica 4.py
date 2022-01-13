#1er Problema Suma de una lista
def suma(lista):
    sumatoria = 0
    for i in range(0,len(lista)):
        sumatoria += lista[i]
    return sumatoria
print (suma([1,2,6,12,7,121,126]))

#2do Problema Retorno del resultado de una funcion
def f(x):
    return 2*(x**2) + 4*x + 3
x = int(input("Ingresa un valor para x: "))
print("El resultado de la función es:",f(x))

#3er Problema dibujar la curva
from turtle import*
pu()
goto(-400,0)
pd()
goto(400,0)

pu()
goto(0,-400)
pd()
goto(0,400)

zoomx = 8
zoomy = 8
x=-3
xfinal=3
pu()
goto(x*zoomx,(2*(x**2) + 4*x + 3)*zoomy)
pd()
i = 0
partes = 100
aumento = (xfinal-x)/partes
while i<partes:
    goto(x*zoomx,(2*(x**2) + 4*x + 3)*zoomy)
    i+=1
    x+=aumento

#3er Problema Dominio de -3 a 3
def dominio():
    for x in range(-3,4):
        print(2*(x**2) + 4*x + 3, end=" ")
dominio()
print ()
#4to Problema Suma de vectores
def sumadevectores(l1,l2):
  resultante = []
  if len(l1)!=len(l2):
    return resultante
  for i in range(0,len(l1)):
    resultante.append(l1[i]+l2[i])
  return resultante
print("La suma de vectores es: ", sumadevectores([71,21,6],[6,5,1]))

#5to Problema 
lista2 = [1,2,5,6,17,126,9]
print("La lista inicial es:",lista2)
def listaalreves(lista1):
    lista=[]
    i = len(lista1)-1
    while i>=0:
        lista.append(lista1[i])
        i-=1
    return lista
print("La lista la revés es:",listaalreves(lista2))

#6to Programa Funcion de una colision
from math import *
def colision(e1,e2):
    distancia = sqrt((e2[0]-e1[0])**2 + (e2[1]-e1[1])**2)
    if distancia>e2[2]+e1[2]:
        return False
    else:
         return True
print(colision([1,2,6],[2,5,2]))
#7mo Programa Colision de bolas
from turtle import *
from math import *
def cuadro():
    pu()
    goto(-100,-100)
    pd()
    for i in range (0,4):    
        forward(100*2)
        left(90)
def choquelimite(e1):
    if e1[0]<-100+e1[2]or e1[0]>100-e1[2]:
        return True
    if e1[1]<-100+e1[2]or e1[1]>100-e1[2]:
        return True
    return False    
def colision(e1,e2):
    distancia = sqrt((e2[0]-e1[0])**2 + (e2[1]-e1[1])**2)
    if distancia>e2[2]+e1[2]:
        return False
    else:
        return True  
tracer(0,0)
hideturtle()

e1 = [-50,-50,20]
e2 = [50,70,10]
v1 = [0.1,0.2]
v2 = [0.2, 0.3]
final = False
while not final:
    clear()
    cuadro()
    if colision(e1,e2):
        final = True
    if choquelimite(e1):
        final = True
    if choquelimite(e2):
        final = True

    pu()
    goto(e1[0],e1[1]-e1[2])
    pd()
    circle(e1[2]) #Primer esfera
    pu()
    goto(e2[0],e2[1]-e2[2])
    pd()
    circle(e2[2]) #Segunda esfera

    e2[0] += v2[0]
    e2[1] += v2[1]  
    e1[0] += v1[0]
    e1[1] += v1[1]
    update()
