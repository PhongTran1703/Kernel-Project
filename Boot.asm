BITS 32

section .multiboot
align 4
    dd 0x1BADB002
    dd 0x0
    dd -(0x1BADB002)

section .text
global start
extern main

start:
    cli
    mov esp, stack_space
    call main

.hang:
    cli
    hlt
    jmp .hang

section .bss
    resb 16384
stack_space:
