.global main

.section .data
.fmtstring:
    .asciz "\n%d green bottles hanging on the wall,\n%d green bottles hanging on the wall,\nand if 1 green bottle should accidentally fall,\nthere'd be %d green bottles hanging on the wall.\n"

.section .text
main:
    // rbx is callee-saved (main is called by the C runtime)
    pushq %rbx
    // i = 10
    movl $10, %ebx
.loop:
    // printf(fmtstring, i, i, i - 10)
    movl $.fmtstring, %edi
    movl %ebx, %esi
    movl %esi, %edx
    subl $1, %ebx
    movl %ebx, %ecx
    call printf
    // loop if i == 0
    testl %ebx, %ebx
    jne .loop

    // return 0
    xorl %eax, %eax
    popq %rbx
    ret
