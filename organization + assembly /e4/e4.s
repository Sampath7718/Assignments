

#############################################
#    csci223 e4
#
#
#  Name Eli Allen
#
#############################################

.globl main

main:

   # This function prologue code writes a backup copy
   # of the frame pointer (%rbp) to the stack
   # so it can be restored on function exit.
   
	pushq	%rbp
	movq	%rsp, %rbp
	
	
	# is argc 7? if so, then go to the start label.
	# otherwise, print a usage message and exit.
	
	cmpl	$7, %edi
	je	start

	movl	$USAGE, %edi
	call	puts
	movl	$1, %edi
	call	exit
	
	
start:	

	movq  $A0, %r12   #a0 is an array of 3 ints
	movq  $A1, %rbx   #a1 is an array of 3 ints
	
	
	
	# Buildargs is a function that puts the command line
	# values into a0 and a1. It needs arguments passed to it
	# using registers %rdi, %rsi, and %rdx

	movq	%rsi, %rdx  #argv is passed to main() in %rsi, but that
	                  # register is needed for the third argument 
	                  # of buildargs
	                  
	movq  %r12, %rdi  #a0
	movq  %rbx, %rsi  #a1
	
	call	buildargs
	
#   WRITEME: 	At this point, %r12 and %rbx are each pointers to two arrays
#   of 3 ints apiece, a0 and a1.  Your job is to write assembly language code
#   in the space below that evaluates the following expression, putting the
#   result in register %esi (the 32 bit form of register %rsi):
#   
#    (a1[0]-a0[0]) * (a1[0]-a0[0]) + 
#    (a1[1]-a0[1]) * (a1[1]-a0[1]) + 
#    (a1[2]-a0[2]) * (a1[2]-a0[2])
#   
#    
#   It is possible to do this using 11 instructions. You need to use extra
#   registers, of course. Since  you are not calling any functions, you have a
#   lot of choices. %r12 and %rbx are already occupied, but you could use
#   %r13d through %r15d (32 bit forms of %r13 through r15) safely, and also
#   %eax, %ecx, %edx and of course %esi, since that is where the result will
#   be stored.
	
	###########
	
	# Your code here
	movl $0, %esi
	movl (%rbx), %eax
	subl (%r12), %eax
	imull %eax, %eax
	movl 4(%rbx), %ecx
	subl 4(%r12), %ecx
	imull %ecx, %ecx
	movl 8(%rbx), %edx
	subl 8(%r12), %edx
	imull %edx, %edx
	movl %eax, %esi
	addl %ecx, %esi
	addl %edx, %esi
	
	#########
	movq    $0, %rax
	movl	$DIFFSTRING, %edi
	call	printf

   movl  $0, %eax # return value of main
   
   
   # clean up the stack, restore old frame pointer
   leave
   
   #return to caller (operating system, in this case)
    ret
	


########################
# Compiler Generated. You can ignore this.
	
	.p2align 4,,15
.globl buildargs
	.type	buildargs, @function
buildargs:
.LFB29:
	pushq	%r13
.LCFI0:
	xorl	%ecx, %ecx
	movq	%rsi, %r13
	xorl	%esi, %esi
	pushq	%r12
.LCFI1:
	movq	%rdi, %r12
	pushq	%rbx
.LCFI2:
	movq	8(%rdx), %rdi
	movq	%rdx, %rbx
	movl	$10, %edx
	call	__strtol_internal
	movq	16(%rbx), %rdi
	movl	%eax, (%r12)
	xorl	%ecx, %ecx
	movl	$10, %edx
	xorl	%esi, %esi
	call	__strtol_internal
	movq	24(%rbx), %rdi
	movl	%eax, 4(%r12)
	xorl	%ecx, %ecx
	movl	$10, %edx
	xorl	%esi, %esi
	call	__strtol_internal
	movq	32(%rbx), %rdi
	movl	%eax, 8(%r12)
	xorl	%ecx, %ecx
	movl	$10, %edx
	xorl	%esi, %esi
	call	__strtol_internal
	movq	40(%rbx), %rdi
	movl	%eax, (%r13)
	xorl	%ecx, %ecx
	movl	$10, %edx
	xorl	%esi, %esi
	call	__strtol_internal
	movq	48(%rbx), %rdi
	movl	%eax, 4(%r13)
	xorl	%ecx, %ecx
	movl	$10, %edx
	xorl	%esi, %esi
	call	__strtol_internal
	popq	%rbx
	popq	%r12
	movl	%eax, 8(%r13)
	popq	%r13
	ret
	
	
	
.LFE29:
	.size	buildargs, .-buildargs
	.section	.rodata.str1.1
DIFFSTRING:
	.string	"difference = %d\n"
	
USAGE:
	.string	"Usage: e4 r0 g0 b0 r1 g1 b1"
	

.section .data
A0:
   .int 0
   .int 0
   .int 0
   
.section .data
A1:
   .int 0
   .int 0
   .int 0

   

