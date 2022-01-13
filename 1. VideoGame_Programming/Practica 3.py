#1er Problema Listar los numeros del 0 al 100 excluido
lista =[]
i = 0
while i<100:
    lista.append(i)
    i+=1
print (lista)
#2do Problema Listar los numeros del 1 al 100 excluido por paso de 2
lista =[]
i = 1
while i<100:
    lista.append(i)
    i+=2
print (lista)

#3er Programa para imprimir los pares de una lista definida
i = int(input("Escribe un numero: "))
lista = []
a = 0
while a <= i:
    lista.append(a)
    a+=2
print (lista)
#4to Programa para hallar el factorial
i = int(input("Escribe un numero: "))
a=1
while i>0:
    a*=i
    i-=1
print (a)    

#5to programa que busca el elemento mayor de una lista
a = int (input("Ingresa el tamaño de la lista: "))
o= 0
lista =[]
while o<a:
    i = int (input("Ingresa un numero para la lista: "))
    lista.append(i)
    o+=1
numero = 0
i=0
while i<a:
    if lista[i] >= numero:
        numero = lista[i]
    i+=1
print ("El numero mayor es:",numero)

#6to Programa para imprimir los 100 primeros numeros primos
print("Los 100 primeros numeros primos son: ")
numero=1
while numero<=100:
    cd = 0
    i=1
    while i <= numero:
        if numero%i==0:
            cd = cd + 1
        i=i+1
    if cd == 2:
        print(numero)
    numero+=1

#7mo Programa para dibujar un rombo con 121
n = int(input("Ingresa un numero: "))
a = n
i = 1
p= n
while i<=n: #Para saber cuantas lineas
    j = 1
    while j<=n-i: #Para los espacios antes de escribir
        print (" ",end="") 
        j+=1
    k = 1
    while k<=(n-p)+1: #Para imprimir los primeros numeros hasta n 
        print (k,end="")
        m=k
        k+=1
    while m-1>0: #Para imprimir los restantes
        print (m-1,end="")
        m-=1
    print ("")
    i+=1
    p-=1
    
i = 1
while i<=n-1:
    j = 0
    while j<=n-a:
        print (" ",end="")
        j+=1
    k = 1
    while k<=n-i:
        print (k,end="")
        m=k
        k+=1
    while m-1>0:
        print(m-1,end="")
        m-=1
    print ("")
    i+=1
    a-=1

#8vo Programa crear un rombo en turtle
from turtle import *
a = int(input("Escribe un valor para n: "))
i = 0
y = 0
x = 0
p=0
while i <= a:
    penup()
    goto(y-5,p)
    pendown()
    goto(x+5,p)
    i+=1
    y-=5
    x+=5
    p-=5
i= 0
while i <= a-1:
    penup()
    goto(y+5,p)
    pendown()
    goto(x-5,p)
    i+=1
    y+=5
    x-=5
    p-=5
done()
