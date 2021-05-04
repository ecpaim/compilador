.text 
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$0, %ecx 
	movl	%ecx,-0(%rbp)
	addq	$-16, %rsp
	movl	$0, %ebx 
	movl	%ebx,-4(%rbp)
.L4: 
	movl	-4(%rbp), %r8d
	movl	$6, %r9d 
	cmpl	%r9d, %r8d 
	setl	%al 
	cbtw
	cwtl
	movl	%eax, %r10d 
	cmpl	$1,%r10d 
	je	.L5 
	jne	.L6 
.L5: 
	movl	-0(%rbp), %r11d
	movl	$1, %r12d 
	addl	%r12d, %r11d
	movl	%r11d,-0(%rbp)
	movl	-0(%rbp), %r13d
	movl	$2, %r14d 
	cmpl	%r14d, %r13d 
	sete	%al 
	cbtw
	cwtl
	movl	%eax, %r15d 
	cmpl	$1,%r15d 
	je	.L1 
	jne	.L2 
.L1: 
	movl	$2, %ecx 
	movl	%ecx, %eax
	jmp	.Lend 
	jmp	.L3 
.L2: 
.L3: 
	movl	-4(%rbp), %ebx
	movl	$1, %r8d 
	addl	%r8d, %ebx
	movl	%ebx,-4(%rbp)
	jmp	.L4 
.L6: 
	movl	-0(%rbp), %r9d
	movl	%r9d, %eax
	jmp	.Lend 
.Lend: 
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 