.text 
	.globl	main 
	.type	main, @function 
main:
.Lmain: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-16, %rsp
	movl	$5, %ecx 
	movl	%ecx,-0(%rbp)
	movl	-0(%rbp), %ebx
	movl	$0, %r8d 
	cmpl	%r8d, %ebx 
	setl	%al 
	cbtw
	cwtl
	movl	%eax, %r9d 
	cmpl	$1,%r9d 
	je	.L1 
	jne	.L2 
.L1: 
	movl	$11, %r10d 
	movl	%r10d, %eax
	jmp	.L3 
.L2: 
	movl	$2, %r11d 
	movl	%r11d, %eax
.L3: 
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 
