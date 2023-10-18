
GLOBAL keyboard_handler

section .text

keyboard_handler:

    push rbp
    mov rbp, rsp

    xor rax, rax
    in al, 0x60

    mov rsp, rbp
    pop rbp
    ret