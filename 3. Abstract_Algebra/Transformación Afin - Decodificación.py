def funEE(a,b):
    variable = a
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
    print(f"Inverso de {variable} es: {s}")
    print(f"Inverso de {variable} mod27 es: {s%27}\n")

    if s<0:
      s+= 27
    t=vk
    mcd=b 
    return s

alpha="ABCDEFGHIJKLMNÑOPQRSTUVWXYZ"
str_in=input("Ingrese el texto cifrado: ")
print("\n")
a=int(input("Valor  a = "))
b=int(input("Valor  b = "))
print("\n")
print(f"Expresion -> P = a^-1(C - b)mod27 \nP ={a}^-1(C - {b})mod27\n\n")
n=len(str_in)
str_out=""
s1 = funEE(a,27)
print("Texto cifrado: \n")
for i in range(n):
    c=str_in[i]
    loc=alpha.find(c)
    print(f"{c} = {loc}")
print("\nTexto Plano:\n")
for i in range(n):
    c=str_in[i]
    loc=alpha.find(c)
    newloc=(s1*(loc-b))%27
    CIF=alpha[newloc]
    str_out +=alpha[newloc]
    print(f"P = ({s1}*({loc} - {b}))mod27 -> ({s1*(loc-b)})mod 27 = {newloc} mod27 -> {CIF}")
print("") 
print ("Texto descifrado : ",str_out)
