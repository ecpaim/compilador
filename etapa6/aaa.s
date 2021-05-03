	.text 
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$3, %ecx 
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
	call	f 
	movl	%eax, %ecx 
	movl	%ecx, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
	