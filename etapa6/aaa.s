	.text 
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$16, %rsp
	movq	%rsp, %rsp 
	movl	$2, %ecx 
	movl	%ecx, %eax
	jmp	L0 
L0: 
	popq	%rbp
	ret
	.size	f, .-f
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$0, %rsp
	movq	%rsp, %rsp 
	call	f 
	movl	%eax, %ecx 
	movl	%ecx, %eax
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
