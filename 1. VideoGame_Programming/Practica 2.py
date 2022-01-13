#Pregunta 1

try:
    nombre = input ("Ingrese su nombre: ")
    assert nombre.isalpha()
except:
    print ("Tu nombre no debe contener caracteres")

try:
    edad = int (input ("Ingrese su edad: "))
    assert 0<edad<=115
    
except ValueError:
    print ("Verifica que tu edad está en números.")
except AssertionError:
    print ("Verifica tu edad. Debe comprender entre 1 y 116")

#Pregunta 2
numero = int(input ("Ingresa un numero: "))
if (numero%3 != 0):
    print ("El número no es múltiplo de 3")
else:
    print ("El número es múltiplo de 3")
    
#Pregunta 3
numero = 0
for i in range (3):
    a = int(input("Ingrese un dígito: "))
    if a >= numero:
        numero = a
print ("El numero mayor es:",numero)

#Pregunta 4
try:
    age = int(input("Ingresa tu edad: "))
    if 0<age<=12:
        print ("Eres un niño :)")
    elif age<19:
        print ("Eres un adolescente :)")
    elif age<65:
        print ("Eres un adulto :(")
    elif age<115:
        print ("Eres un anciano :(")
    else:
        print ("Edad incorrecta")
except ValueError:
    print("Edad incorrecta")

#Pregunta 5
from turtle import *

dibujo = (input("Escoge un num entre: \nCuadrado = 1 \nTriangulo = 2 \nCirculo = 3 \nRombo = 4 \nHexagono = 5 \n"))

if (dibujo=="1"):
    forward(100)
    left(90)
    forward(100)
    left(90)
    forward(100)
    left(90)
    forward(100)
    done()
elif (dibujo == "2"):
    left (120)
    forward (50)
    left(120)
    forward (50)
    left (120)
    forward (50)
    done()
elif (dibujo == "3"):
    circle(50)
    done()
elif (dibujo == "4"):
    pendown()
    left(135)
    forward(100)
    left(90)
    forward(100)
    left(90)
    forward(100)
    left(90)
    forward(100)
    done()
else:
    forward(100)
    right(60)
    forward(100)
    right(60)
    forward(100)
    right(60)
    forward(100)
    right(60)
    forward(100)
    right(60)
    forward(100)
    done()

#Pregunta 6
try:
    x = int(input("valor para x: "))
    a = 1/x
    print (a)
except ZeroDivisionError:
    print ("Error al dividir entre 0")
    
    
 
