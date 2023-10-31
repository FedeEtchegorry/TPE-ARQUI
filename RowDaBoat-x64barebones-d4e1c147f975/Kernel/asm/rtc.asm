GLOBAL timeParam
GLOBAL getHours
GLOBAL getMinutes


section .text

timeParam:                  ;;en rax se tendria que poner el parámetro del tiempo que quiero
    push rbp
    mov rbp, rsp

    mov rax, rdi
    out 70h, al
    xor rax, rax
    in al, 71h



    mov rsp, rbp
    pop rbp
    ret

getSeconds:
    mov al, 0h
    out 70h, al
	xor rax, rax
	in al, 71h
    ret

getMinutes:
    mov al, 2h
    out 70h, al
    in al, 71h
    ret

getHours:
    mov al, 4h
    out 70h, al
    in al, 71h
    ret

getDay:
    mov al, 7h
    out 70h, al
    in al, 71h
    ret
getMonth:
    mov al, 8h
    out 70h, al
    in al, 71h
    ret
getYear:
    mov al, 9h
    out 70h, al
    in al, 71h
    ret