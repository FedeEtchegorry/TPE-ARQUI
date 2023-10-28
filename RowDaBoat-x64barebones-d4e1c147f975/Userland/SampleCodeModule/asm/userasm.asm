GLOBAL print
GLOBAL getChar

extern strLength
section .text
	
; void print(unsigned * char string)
print:
	push rbp
	mov rbp, rsp
    
    push rax
    push rbx
    push rcx
    push rdx

    mov rax, 0x99
    int 0x80        ; vacío el buffer por si las moscas

    call strLength  ; rdi = @string
    mov rdx, rax

    mov rax, 0x03   ; sysRead:
    mov rcx, rdi    ;   @string
                    ;
    int 0x80        ; 

    mov rax, 0x04   ; sysWrite:
    mov rbx, 0x01   ;
                    ; rdx = @count
    int 0x80        ;

    pop rdx
    pop rcx
    pop rbx
    pop rax

	mov rsp, rbp
	pop rbp
	ret

; unsigned char getChar()
getChar:

    push rbp
    mov rbp, rsp

    mov rax, 0x04
    mov rbx, 0xA0
    int 0x80
    
    mov rsp, rbp
    pop rbp
    
    ret
