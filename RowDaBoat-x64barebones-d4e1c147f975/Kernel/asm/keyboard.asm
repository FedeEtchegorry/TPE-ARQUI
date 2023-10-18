
GLOBAL keyboard_handler

section .text

keyboard_handler:

    push rbp
    mov rbp, rsp

    mov rax, 0
      	in al, 64h
    	test al, 0x01
    	jz .exit
        in al, 60h
    	jmp .leave
    .exit:
        mov rax, 0
    .leave
    mov rsp, rbp
    pop rbp
    ret