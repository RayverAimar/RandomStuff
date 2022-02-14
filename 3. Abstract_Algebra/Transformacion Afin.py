alpha="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
str_in=input("Ingrese el texto: ")
print("\n")
a=int(input("Valor  a = "))
b=int(input("Valor  b = "))
print("\n")
print(f"Expresion -> C = (aP + b)mod27 \nC =({a}P + {b})mod27\n\n")
n=len(str_in)
str_out=""
print("Texto Plano: \n")
for i in range(n):
    c=str_in[i]
    loc=alpha.find(c)
    print(f"{c} = {loc}")
print("\nTexto Cifrado:\n")
for i in range(n):
    c=str_in[i]
    loc=alpha.find(c)
    newloc=(a*loc+b)%27
    CIF=alpha[newloc]
    str_out +=alpha[newloc]
    print(f"C = ({a}*{loc} + {b})mod27 -> ({a*loc+b})mod 27 = {(a*loc+b)%27} mod27 -> {CIF}")
print("") 
print ("Texto cifrado : ",str_out)
