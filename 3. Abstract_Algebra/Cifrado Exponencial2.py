def binarizar(decimal):
    binario = ''
    while decimal // 2 != 0:
        binario += str(decimal % 2)
        decimal = decimal // 2
    return (binario + str(decimal))[::-1]

numero = int(input("Ingrese el numero base: "))
exponente = int(input("Ingrese el exponente: "))
modulo = int(input("Ingrese el modulo: "))

char_binario = binarizar(exponente)
print(f"{exponente} = {char_binario}")
k = len(char_binario) -1
print(f"k = {k}")
i = 0

while i<=k:
  dato_anterior = pow(numero,pow(2,i))
  print(f"{numero}^({pow(2,i)}) mod {modulo} = {dato_anterior%modulo} mod{modulo}")
  i+=1
print(f"\n{exponente} = ", end="")
for posicion, digito_string in enumerate(char_binario[::-1]):
  digito = int(digito_string)
  if digito == 1:
    print(f"2^{posicion} + ", end = "")
print(f"\n{numero}^{exponente} = ",end="")
resultado = 0
for posicion, digito_string in enumerate(char_binario[::-1]):
  digito = int(digito_string)
  if digito == 1:
    print(f"{numero}^{2 ** posicion} * ", end = "")
