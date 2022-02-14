def binarizar(decimal):
    binario = ''
    while decimal // 2 != 0:
        binario += str(decimal % 2)
        decimal = decimal // 2
    return (binario + str(decimal))[::-1]

numero = int(input("Ingrese el numero base: "))
k = int(input("Ingrese k: "))
modulo = int(input("Ingrese el modulo: "))

print(f"k = {k}")
i = 0

while i<=k:
  dato_anterior = pow(numero,pow(2,i))
  print(f"{numero}^({pow(2,i)}) mod {modulo} = {dato_anterior%modulo} mod{modulo}")
  i+=1
