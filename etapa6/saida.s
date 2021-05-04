.text 
	.comm	var,4,4
	.comm	var2,4,4
	.comm	var3,4,4
	.comm	var4,4,4
	.globl	f 
	.type	f, @function 
f:
.Lf: 
	pushq	%rbp
	movq	%rsp, %rbp
	addq	$-0, %rsp
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
	movl	$5, %ebx 
	movl	%ebx,var(%rip) 
	movl	var(%rip), %r8d
	movl	%r8d, %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
	.size	main, .-main
	.section	.note.GNU-stack,"",@progbits 