

#############################################
#    csci223 e5
#
#
#  Name Eli Allen
#
#############################################

.globl main
	
main:

   pushq %rbp
   movq  %rsp, %rbp
   
   movq  $ARRAY, %rdi
   movq  $LENGTH, %rsi
   
   call countThrees
   
   movq $format, %rdi
   movq %rax, %rsi
   movq $0, %rax

   call printf
   
   movl  $0, %eax # return value of main
   
   # clean up the stack, restore old frame pointer
   leave
   
   #return to caller (operating system, in this case)
    ret
	
	


##########
# WRITEME: Write a function that counts the number of
# occurrences of the number 3 in an array of integers.
# This function, named countThrees(), takes two arguments.
# The first argument is a pointer to an int array, and
# the second argument is an int that indicates the 
# the length of the array.  Your function should return
# the number of 3s found using %eax.

countThrees:

   # This function prologue code writes a backup copy
   # of the frame pointer (%rbp) to the stack
   # so it can be restored on function exit.
 
	pushq	%rbp
	movq	%rsp, %rbp

################
	# Your code here

	movl $0, %eax
	movq $0, %rdx #counter
START:
	cmpq %rsi, %rdx
	jg DONE
	incq %rdx
	addl $4, %edi
	cmpl $3,-4(%edi) 
	jne START
       incl %eax
	jmp START 

	


###############
DONE:
	
   # clean up the stack, restore old frame pointer
   leave
   
   #return to caller 
   ret



	.section	.rodata
format:
	.string	"There are %d threes\n"

