#Intercambiar entre 1 para ascendente y 0 para descendente
##Bifurcacion que no puse en la linea 49
##ble $t7, $t8, while2
.text
.globl main
main:
lw $s1, size #s1 = 6
addi $t0,$zero,0 #$t0 = 0

la $a0, array
lw $a1, size #a1=6
jal sort

li $v0,4
la $a0,solution
syscall 

la $t0,array 
add $t1,$zero,1 #t1 = 0	
print:
lw $a0,0($t0) #a0 = &t0 
li $v0,1
syscall #Imprime  elemento &t0
li $v0,4
la $a0,space #cout<<" ";
syscall
addi $t0,$t0,4 #aumenrta la direccion en 1
addi $t1,$t1,1 #t1++
ble $t1,$s1, print#-> t<6

li $v0,10
syscall

sort: 
	addi $t0,$zero,1 
	#bgtz
	while1:
	addi $t0,$t0,1 #t++ 
	bge $t0,$a1,endsort #while 2,3,4,5,6 < 6; 
	sub $t1,$a1,$t0 #t1 =4
	addi $t2, $zero, 0
	
	while2:
	bgt $t2,$t1,while1 #1,2,3,4,5,6 < = 6, se sale del 2do bucle
	
	mul $t4,$t2,4 #0,4,8,12,16
	addi $t3,$t4,+4 #t3+a0=table[j-1] ->20 
	add $t7,$t4,$a0 #t7=table[j] ->table(24)
	add $t8,$t3,$a0 #t8=table[j-1] -> table(20)
	lw $t5,0($t7) #->$t5 = &table(24) 
	lw $t6,0($t8) #->$t6 = &table(20)
	addi $t2,$t2, 1 #j-- 5,4,3,2,1,0
	ble $t5,$t6,while2  #->   table(24) > table(20) vuelve a correr el bucle

	sw $t5,0($t8)
	sw $t6,0($t7)
	j while2

	endsort:
	jr $ra

.data
array: .word 24,6,0,3,1,7
size: .word 6
space: .asciiz " "
solution: .asciiz "\nSorted Array-> "
