.text 
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$2, %ecx 
	movl	%ecx, %eax
	jmp	.L0 
.L0: 
	leave
	ret
	.size	f, .-f
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$6, %ebx 
	movl	$2, %r8d 
	movl	%ebx, %eax
	cltd
	movq	$0, %rdx
	idivl	%r8d
	movl	%eax,-0(%rbp)
	movl	-0(%rbp), %r9d
	movl	%r9d, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
	