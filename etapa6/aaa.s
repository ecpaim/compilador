	.text 
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
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
	call	f 
	movl	%eax, %edx 
	movl	%edx,-0(%rbp)
	movl	-0(%rbp), %ebx
	movl	%ebx, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
