	.file	"mystrlenrec.c"
	.text
	.globl	StrLenRec
	.type	StrLenRec, @function
StrLenRec:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$8, %esp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L2
	movl	12(%ebp), %eax
	subl	$1, %eax
	jmp	.L3
.L2:
	addl	$1, 12(%ebp)
	subl	$8, %esp
	pushl	12(%ebp)
	pushl	8(%ebp)
	call	StrLenRec
	addl	$16, %esp
	movl	%eax, 12(%ebp)
	movl	12(%ebp), %eax
.L3:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	StrLenRec, .-StrLenRec
	.globl	MyStrLenRec
	.type	MyStrLenRec, @function
MyStrLenRec:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$24, %esp
	movl	$0, -12(%ebp)
	cmpl	$0, 8(%ebp)
	jne	.L5
	movl	$0, %eax
	jmp	.L6
.L5:
	subl	$8, %esp
	pushl	-12(%ebp)
	pushl	8(%ebp)
	call	StrLenRec
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
.L6:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	MyStrLenRec, .-MyStrLenRec
	.globl	MyStrLenIter
	.type	MyStrLenIter, @function
MyStrLenIter:
.LFB2:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	movl	$0, -4(%ebp)
	cmpl	$0, 8(%ebp)
	jne	.L10
	movl	$0, %eax
	jmp	.L9
.L11:
	addl	$1, -4(%ebp)
.L10:
	movl	-4(%ebp), %edx
	movl	8(%ebp), %eax
	addl	%edx, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	.L11
	movl	-4(%ebp), %eax
	subl	$1, %eax
.L9:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE2:
	.size	MyStrLenIter, .-MyStrLenIter
	.section	.rodata
.LC0:
	.string	"Enter a string"
.LC1:
	.string	"strlength Rec = %d\n"
.LC2:
	.string	"strlength Iter = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x7c,0x6
	subl	$148, %esp
	movl	%gs:20, %eax
	movl	%eax, -12(%ebp)
	xorl	%eax, %eax
	movl	$0, -144(%ebp)
	subl	$12, %esp
	pushl	$.LC0
	call	puts
	addl	$16, %esp
	movl	stdin, %eax
	subl	$4, %esp
	pushl	%eax
	pushl	$128
	leal	-140(%ebp), %eax
	pushl	%eax
	call	fgets
	addl	$16, %esp
	subl	$12, %esp
	leal	-140(%ebp), %eax
	pushl	%eax
	call	puts
	addl	$16, %esp
	subl	$12, %esp
	leal	-140(%ebp), %eax
	pushl	%eax
	call	MyStrLenRec
	addl	$16, %esp
	movl	%eax, -144(%ebp)
	subl	$8, %esp
	pushl	-144(%ebp)
	pushl	$.LC1
	call	printf
	addl	$16, %esp
	subl	$12, %esp
	leal	-140(%ebp), %eax
	pushl	%eax
	call	MyStrLenIter
	addl	$16, %esp
	movl	%eax, -144(%ebp)
	subl	$8, %esp
	pushl	-144(%ebp)
	pushl	$.LC2
	call	printf
	addl	$16, %esp
	movl	$1, %eax
	movl	-12(%ebp), %edx
	xorl	%gs:20, %edx
	je	.L14
	call	__stack_chk_fail
.L14:
	movl	-4(%ebp), %ecx
	.cfi_def_cfa 1, 0
	leave
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
