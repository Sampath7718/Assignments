#############################################
#    csci223 e6
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
   
    pushq   %rbp
    movq    %rsp, %rbp
    
    
    # is argc 7? if so, then go to the start label.
    # otherwise, print a usage message and exit.
    
    cmpl    $7, %edi
    je  start

    movl    $USAGE, %edi
    call    puts
    movl    $1, %edi
    call    exit
    
    
start:  

    movq  $A0, %r12   #a0 is an array of 3 ints
    movq  $A1, %rbx   #a1 is an array of 3 ints
    
    
    
    # Buildargs is a function that puts the command line
    # values into a0 and a1. It needs arguments passed to it
    # using registers %rdi, %rsi, and %rdx

    movq    %rsi, %rdx  #argv is passed to main() in %rsi, but that
                      # register is needed for the third argument 
                      # of buildargs
                      
    movq  %r12, %rdi  #a0
    movq  %rbx, %rsi  #a1
    
    call    buildargs

##########################    
#   WRITEME: %r12 contains a0, a pointer to an array of 3 ints, and %rbx
#   contains a1, a similar pointer.  We need to call the function named
#   difference(), which you will have written below. However, difference()
#   expects a0 and a1 to be in %rdi and %rsi. In the space below, you will
#   have to move arguments to the appropriate registers, and then call
#   difference(). After the call, the return value of difference() is in %eax.
#   However, this same value is about to be given to printf() as the second
#   argument. So, you need to move %eax to %esi immediately after difference()
#   returns.
    
###########

   # Your code here
    movq %r12, %rdi
    movq %rbx, %rsi
    call difference
    movl %eax, %esi
    
#########
    movq $0, %rax
    movl    $DIFFSTRING, %edi
    call    printf

   movl  $0, %eax # return value of main
   
   # clean up the stack, restore old frame pointer
   leave
   
   #return to caller (operating system, in this case)
    ret



##########################
#   WRITEME: You need to write a function called difference() that takes two
#   pointer arguments, a0 and a1. They are expected to be in %rdi and %rdi.
#   The function should evaluate the same expression as in e4. In C, the
#   function code would be:
#   
#   int difference(int a0[], int a1[]){
#   
#   
#     return 
#      (a1[0]-a0[0]) * (a1[0]-a0[0]) + 
#      (a1[1]-a0[1]) * (a1[1]-a0[1]) + 
#      (a1[2]-a0[2]) * (a1[2]-a0[2]);
#   }
#
#   Unlike e4, the result should now be placed in %eax, since this register
#   always holds the return value for functions.
#   
#   Obviously, it would save time to copy your code from e4 to e5, but you may
#   need to make adjustments with regard to register usage to get your code
#   working inside a function. Please consult the function call handout for a
#   function call example.

difference:

# Your code here
       movl $0, %eax
	movl (%rsi), %r8d
	subl (%rdi), %r8d
	imull %r8d, %r8d
	movl 4(%rsi), %ecx
	subl 4(%rdi), %ecx
	imull %ecx, %ecx
	movl 8(%rsi), %edx
	subl 8(%rdi), %edx
	imull %edx, %edx
	movl %r8d, %eax
	addl %ecx, %eax
	addl %edx, %eax







########################
# Compiler Generated.
    
    .p2align 4,,15
.globl buildargs
    .type   buildargs, @function
buildargs:
.LFB29:
    pushq   %r13
.LCFI0:
    xorl    %ecx, %ecx
    movq    %rsi, %r13
    xorl    %esi, %esi
    pushq   %r12
.LCFI1:
    movq    %rdi, %r12
    pushq   %rbx
.LCFI2:
    movq    8(%rdx), %rdi
    movq    %rdx, %rbx
    movl    $10, %edx
    call    __strtol_internal
    movq    16(%rbx), %rdi
    movl    %eax, (%r12)
    xorl    %ecx, %ecx
    movl    $10, %edx
    xorl    %esi, %esi
    call    __strtol_internal
    movq    24(%rbx), %rdi
    movl    %eax, 4(%r12)
    xorl    %ecx, %ecx
    movl    $10, %edx
    xorl    %esi, %esi
    call    __strtol_internal
    movq    32(%rbx), %rdi
    movl    %eax, 8(%r12)
    xorl    %ecx, %ecx
    movl    $10, %edx
    xorl    %esi, %esi
    call    __strtol_internal
    movq    40(%rbx), %rdi
    movl    %eax, (%r13)
    xorl    %ecx, %ecx
    movl    $10, %edx
    xorl    %esi, %esi
    call    __strtol_internal
    movq    48(%rbx), %rdi
    movl    %eax, 4(%r13)
    xorl    %ecx, %ecx
    movl    $10, %edx
    xorl    %esi, %esi
    call    __strtol_internal
    popq    %rbx
    popq    %r12
    movl    %eax, 8(%r13)
    popq    %r13
    ret
    
    
    
.LFE29:
    .size   buildargs, .-buildargs
    .section    .rodata.str1.1
DIFFSTRING:
    .string "difference = %d\n"
    
USAGE:
    .string "Usage: e4 r0 g0 b0 r1 g1 b1"
    

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

   
