#Recursividad
#1er Ejercicio
def sumatoria(n):
    if n == 1:
        return 1
    else:
        return n + sumatoria(n-1)       
print(sumatoria(5))

#1er Ejercicio
def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n-1)       
print(factorial(5))

#1er Ejercicio
def potencia(a,b):
    if b == 1:
        return a
    else:
        return a * potencia(a,b-1)
print (potencia(2,3))

#1er Ejercicio
def maximo(lista):
    if len(lista) == 1:
        return lista[0]
    else:  
        maximal = maximo(lista[1:])
    if maximal>lista[0]:
        return maximal
    else:
        return lista[0]
print(maximo([1,5,6,8,13,9]))

#1er Ejercicio
def serie(n):
    if n==1:
        return 1
    else:
        return n+serie(n-1)
        
#1er Ejercicio
def palindrome(palabra):
    if len(palabra) == 1:
        return True
    if palabra[0] != palabra[-1]:
        return False
    return palindrome(palabra[1:-1])

print(palindrome("sometatemos"))


