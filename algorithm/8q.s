	.file	"8q.c"
	.comm	queen,32,32
	.globl	sum
	.bss
	.align 4
	.type	sum, @object
	.size	sum, 4
sum:
	.zero	4
	.section	.rodata
.LC0:
	.string	"(%d %d) "
	.text
	.globl	show
	.type	show, @function
show:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	.L2
.L3:
	movl	-12(%ebp), %eax
	movl	queen(,%eax,4), %edx
	movl	$.LC0, %eax
	movl	%edx, 8(%esp)
	movl	-12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	addl	$1, -12(%ebp)
.L2:
	cmpl	$7, -12(%ebp)
	jle	.L3
	movl	$10, (%esp)
	call	putchar
	movl	sum, %eax
	addl	$1, %eax
	movl	%eax, sum
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	show, .-show
	.globl	check
	.type	check, @function
check:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	subl	$16, %esp
	movl	$0, -8(%ebp)
	jmp	.L5
	.cfi_offset 3, -12
.L9:
	movl	-8(%ebp), %eax
	movl	queen(,%eax,4), %edx
	movl	8(%ebp), %eax
	movl	queen(,%eax,4), %eax
	cmpl	%eax, %edx
	je	.L6
	movl	8(%ebp), %eax
	movl	queen(,%eax,4), %edx
	movl	-8(%ebp), %eax
	movl	queen(,%eax,4), %eax
	movl	%edx, %ecx
	subl	%eax, %ecx
	movl	%ecx, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	xorl	%edx, %eax
	subl	%edx, %eax
	movl	-8(%ebp), %edx
	movl	8(%ebp), %ecx
	movl	%ecx, %ebx
	subl	%edx, %ebx
	movl	%ebx, %edx
	cmpl	%edx, %eax
	jne	.L7
.L6:
	movl	$1, %eax
	jmp	.L8
.L7:
	addl	$1, -8(%ebp)
.L5:
	movl	-8(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L9
	movl	$0, %eax
.L8:
	addl	$16, %esp
	popl	%ebx
	.cfi_restore 3
	popl	%ebp
	.cfi_def_cfa 4, 4
	.cfi_restore 5
	ret
	.cfi_endproc
.LFE1:
	.size	check, .-check
	.globl	put
	.type	put, @function
put:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	.L11
.L14:
	movl	8(%ebp), %eax
	movl	-12(%ebp), %edx
	movl	%edx, queen(,%eax,4)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	check
	testl	%eax, %eax
	jne	.L12
	cmpl	$7, 8(%ebp)
	jne	.L13
	call	show
	jmp	.L12
.L13:
	movl	8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, (%esp)
	call	put
.L12:
	addl	$1, -12(%ebp)
.L11:
	cmpl	$7, -12(%ebp)
	jle	.L14
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	put, .-put
	.section	.rodata
.LC1:
	.string	"%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	$0, (%esp)
	call	put
	movl	sum, %edx
	movl	$.LC1, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.1-9ubuntu3) 4.6.1"
	.section	.note.GNU-stack,"",@progbits
