	.text 
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-32, %rsp
	movl	16(%rbp), %eax 
	movl	%eax,-24(%rbp)
	movl	24(%rbp), %eax 
	movl	%eax,-28(%rbp)
	movl	-28(%rbp), %ecx
	movl	-24(%rbp), %ebx
	imul	%ebx, %ecx
	movl	%ecx, %eax
	jmp	.L0 
.L0: 
	leave
	ret
	.size	f, .-f
	.globl	mult 
	.type	mult, @function 
mult:
.Lmult: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-64, %rsp
	movl	16(%rbp), %eax 
	movl	%eax,-32(%rbp)
	movl	24(%rbp), %eax 
	movl	%eax,-36(%rbp)
	movl	32(%rbp), %eax 
	movl	%eax,-40(%rbp)
	movl	40(%rbp), %eax 
	movl	%eax,-44(%rbp)
	addq	$-16, %rsp
	addq	$-16, %rsp
	addq	$-16, %rsp
	addq	$-16, %rsp
	movl	-44(%rbp), %r8d
	subq	$8, %rsp 
	movl	%r8d,(%rsp)
	movl	-40(%rbp), %r9d
	subq	$8, %rsp 
	movl	%r9d,(%rsp)
	call	f 
	movl	%eax, %r10d 
	movl	%r10d,-56(%rbp)
	movl	-36(%rbp), %r11d
	subq	$8, %rsp 
	movl	%r11d,(%rsp)
	movl	-32(%rbp), %r12d
	subq	$8, %rsp 
	movl	%r12d,(%rsp)
	call	f 
	movl	%eax, %r13d 
	movl	%r13d,-60(%rbp)
	movl	-56(%rbp), %r14d
	movl	-60(%rbp), %r15d
	addl	%r15d, %r14d
	movl	%r14d,-48(%rbp)
	movl	-48(%rbp), %ecx
	movl	$1, %ebx 
	addl	%ebx, %ecx
	movl	%ecx,-52(%rbp)
	movl	-52(%rbp), %r8d
	movl	%r8d, %eax
	jmp	.L1 
.L1: 
	leave
	ret
	.size	mult, .-mult
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	addq	$-16, %rsp
	addq	$-16, %rsp
	addq	$-16, %rsp
	movl	$2018, %r9d 
	movl	%r9d,-0(%rbp)
	movl	$2, %r10d 
	movl	%r10d,-8(%rbp)
	movl	$2, %r11d 
	movl	%r11d,-12(%rbp)
	movl	-8(%rbp), %r12d
	movl	$3, %r13d 
	imul	%r13d, %r12d
	subq	$8, %rsp 
	movl	%r12d,(%rsp)
	movl	-8(%rbp), %r14d
	movl	$3, %r15d 
	imul	%r15d, %r14d
	subq	$8, %rsp 
	movl	%r14d,(%rsp)
	movl	-12(%rbp), %ecx
	movl	$2, %ebx 
	imul	%ebx, %ecx
	subq	$8, %rsp 
	movl	%ecx,(%rsp)
	movl	-12(%rbp), %r8d
	movl	$2, %r9d 
	imul	%r9d, %r8d
	subq	$8, %rsp 
	movl	%r8d,(%rsp)
	call	mult 
	movl	%eax, %r10d 
	movl	%r10d,-4(%rbp)
	movl	-4(%rbp), %r11d
	movl	%r11d, %eax
	jmp	.Lend 
.Lend: 
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
