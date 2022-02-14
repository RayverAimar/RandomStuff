from math import gcd
def binarizar(decimal):
    binario = ''
    while decimal // 2 != 0:
        binario += str(decimal % 2)
        decimal = decimal // 2
    return (binario + str(decimal))[::-1]
def funEE(a,b):
    variable = a
    variable_b = b
    aa=a
    bb=b
    u_1=1
    v_1=0
    u0=0
    v0=1
    import math
    aa = a
    bb = b
    while (a%b)!= 0:
            qk=math.floor(a/b)
            uk=u_1-qk*u0  
            vk=v_1-qk*v0  
            rk=aa*uk+bb*vk
            m=b
            a=m
            b=rk
            u_1=u0
            u0=uk
            v_1=v0
            v0=vk
    s=uk  
    if s<0:
      s+= variable_b
    t=vk
    mcd=b 
    return s

alpha="0123456789-ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"

str_in = (input("Introduzca el mensaje a cifrar: "))
print("")
p=int(input("Valor  p = "))
q=int(input("Valor  q = "))
e=int(input("Valor  e = "))
print("")
n = p*q
fi_n = (p-1) * (q-1)
print(f"n = p * q =({p})*({q}) = {n}")
print(f"fi_n = (p - 1)*(q - 1) = ({p} - 1)*({q} - 1) = {fi_n}")
rango = len(str_in)
print("\nTexto cifrado: \n")
for i in range(rango):
    letra=str_in[i]
    loc=alpha.find(letra)
    print(f"{letra} = {loc}")
print("\nTexto Plano:\n")
i=2
while i < fi_n:
  if gcd(fi_n,i) == 1:
    e = i
    break
  i+=1 
print(f"Establecemos que e = {e} para lo que se verifica")
print(f"mcd(e,fi_n) = 1")
print(f"mcd({e},{fi_n}) = {gcd(e,fi_n)}")
iterador = 0
print("\nDel texto plano tenemos: \n")
for i in range(rango):
    letra=str_in[i]
    loc=alpha.find(letra)
    print(f"a[{iterador}] = {loc}")
    iterador+=1
print("\nCiframos el mensaje: \n")
print(f"b = a^e(mod n)       ->       b = a^{e}(mod n)\n")
resultado = ""
iterador = 0
cifrado = []
indispensable = 0
for i in range(rango):
    letra=str_in[i]
    loc=alpha.find(letra)
    print(f"b[{iterador}] = a[{iterador}]^{e} = {loc}^{e} mod{n} = {(loc**e)%n} mod{n}")
    resultado += str((loc**e)%n)
    cifrado.append((loc**e)%n)
    iterador+=1
    indispensable = iterador
  
d = funEE(e,fi_n)
v = funEE(fi_n,e)
print("")
print(f"El mensaje cifrado es {resultado}\n")
print("Descifrar el mensaje a= b^d (modn)")
print(f"\nd = ?\n")
print(f"e*d + fi_n*v = 1          e*s + fi_n*t = 1")
print(f"\n{e}*d + {fi_n}*v = 1           {e}*s + {fi_n}*t = 1\n")
print(f"                          {e}*({d}) + {fi_n}*({v}) = 1")
print("d es el inverso de e modulo fi_n, ed = 1 mod fi_n\n")
print(f"d = {d}")
print(f"\na=b^{d} (mod n)")
iterador = 0
for i in range(rango):
    loc=alpha.find(letra)
    print(f"a[{iterador}] = b[{iterador}]^{d} mod n = {cifrado[iterador]}^{d} mod{n}")
    iterador+=1
char_binario = binarizar(d)
k = len(char_binario) - 1
print(f"\n{d} = {char_binario}")
print(f"k = {k}\n77 = ", end = "")
for posicion, digito_string in enumerate(char_binario[::-1]):
  digito = int(digito_string)
  print(f"{digito} * 2^{posicion} + ", end = "")
print("\n77 = ",end = "")
for posicion, digito_string in enumerate(char_binario[::-1]):
  digito = int(digito_string)
  if digito == 1:
    print(f"{digito} * 2^{posicion} + ", end = "")

i = 0
print(indispensable)
while i < indispensable:
  print(f"\n\nPara a[{i}]\n")
  print(f"{cifrado[i]}^{d} = {cifrado[i]}^(",end="")
  for posicion, digito_string in enumerate(char_binario[::-1]):
    digito = int(digito_string)
    if digito == 1:
      print(f"2^{posicion} + ", end = "")
  print(f") = {cifrado[i]}^(",end="")
  for posicion, digito_string in enumerate(char_binario[::-1]):
    digito = int(digito_string)
    if digito == 1:
      print(f"{pow(2,posicion)} + ", end = "")
  print(f") = ",end="")
  for posicion, digito_string in enumerate(char_binario[::-1]):
    digito = int(digito_string)
    if digito == 1:
      print(f"{cifrado[i]}^{pow(2,posicion)} * ", end = "")
  iterador = 0
  print("\n")
  while iterador<=k:
    dato_anterior = pow(cifrado[i],pow(2,iterador))
    print(f"{cifrado[i]}^({pow(2,iterador)}) mod {n} = {dato_anterior%n} mod{n}")
    iterador+=1
  print(f"\n{cifrado[i]}^{d} = ",end = "")
  for posicion, digito_string in enumerate(char_binario[::-1]):
    digito = int(digito_string)
    if digito == 1:
      print(f"{cifrado[i]}^{pow(2,posicion)} * ", end = "")
  i+=1
  
