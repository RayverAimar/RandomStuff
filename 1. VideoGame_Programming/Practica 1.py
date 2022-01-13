print ("Hello world")

#Pregunta 1: Crear las variables

a = 54
b = 32.0
c = "Hola, que tal?"

print (("La variable a es de tipo:"),type (a))
print (("La variable b es de tipo:"),type (b))
print (("La variable c es de tipo:"),type (c))

#Pregunta: Crear una variable con entero cualquier y b que sea el doble de a

a = int (input("Ingresa un valor para a: "))
b= 2*a 
print (b)

#Pregunta 3: Crear una variable que contiene un entero cualquiera y duplicar su contenido

a = int (input ("Ingresa un valor para a: "))
a *= 2
print (a)

#Pregunta 4: Intercambiar el valor de dos variables
a = int (input ("Ingresa un valor para a: "))
b = int (input ("Ingresa un valor para b: "))

d = a
a = b
b = d

print ("a: ", a)
print ("b: ", d)

#Pregunta 5:

a = int (input ("Ingrese un valor para a: "))
b = int (input ("Ingresa un valor para b: "))
c = a // b
r = a - b*c
print (c)
print (r)

#Pregunta 6:

a = int (input ("Ingrese un valor para a: "))
b = int (input ("Ingresa un valor para b: "))

print (("La proposición 'a==b' es"), a==b)
print (("La proposic ión 'a!=b' es"), a!=b)
print (("La proposición 'a<b' es"), a<b)
print (("La proposición 'a>b' es"), a>b)
print (("La proposición 'a>b' es"), a<=b)
print (("La proposición 'a>b' es"), a>=b)

#Pregunta 7:
a = int (input ("Ingrese un valor para a: "))

print (( "\n'a*a' es igual a: {} \n'a**2' es igual a: {} \npor lo tanto 'a*a==a**2' es :".format(a*a, a**2)), a*a == a**2)

#Pregunta 8:

a = edad
'''
El programa se detiene puesto que la variable edad no está definida
como para que se inserte en la variable a
'''


