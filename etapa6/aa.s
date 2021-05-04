.text 
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$5, %ecx 
	movl	$2, %ebx 
	imul	%ecx, %ebx
	subl	%ebx, %ecx
	movl	%ecx,-0(%rbp)
	movl	-0(%rbp), %r8d
	movl	%r8d, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits