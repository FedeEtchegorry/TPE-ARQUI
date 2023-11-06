


GLOBAL _cli
GLOBAL _sti
GLOBAL picMasterMask
GLOBAL picSlaveMask
GLOBAL haltcpu
GLOBAL _hlt
GLOBAL saveState
GLOBAL register_saviour
global play_sound
global nosound

GLOBAL _irq00Handler
GLOBAL _irq01Handler
GLOBAL _irq02Handler
GLOBAL _irq03Handler
GLOBAL _irq04Handler
GLOBAL _irq05Handler
GLOBAL _irq60Handler

GLOBAL _exception0Handler

EXTERN irqDispatcher
EXTERN int_80
EXTERN exceptionDispatcher

SECTION .text

%macro pushState 0
	push rax
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15
%endmacro



%macro popState 0
	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	pop rax
%endmacro

saveState:
	pushState
	dState
	popState
	ret

%macro irqHandlerMaster 1
	pushState

	mov rdi, %1 ; pasaje de parametro
	
	call irqDispatcher
	
	; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al

	popState
	iretq
%endmacro



%macro exceptionHandler 1
	pushState

	mov rdi, %1 ; pasaje de parametro
	call exceptionDispatcher

	popState
	iretq
%endmacro


_hlt:
	sti
	hlt
	ret

_cli:
	cli
	ret


_sti:
	sti
	ret

picMasterMask:
	push rbp
    mov rbp, rsp
    mov ax, di
    out	21h,al
    pop rbp
    retn

picSlaveMask:
	push    rbp
    mov     rbp, rsp
    mov     ax, di  ; ax = mascara de 16 bits
    out	0A1h,al
    pop     rbp
    retn


;8254 Timer (Timer Tick)
_irq00Handler:
	irqHandlerMaster 0		; acá ya llama al contador sumando ticks

;Keyboard
_irq01Handler:
	irqHandlerMaster 1

;Cascade pic never called
_irq02Handler:
	irqHandlerMaster 2

;Serial Port 2 and 4
_irq03Handler:
	irqHandlerMaster 3

;Serial Port 1 and 3
_irq04Handler:
	irqHandlerMaster 4

;USB
_irq05Handler:
	irqHandlerMaster 5

;syscalls
_irq60Handler: 
		; push rax ;<- valor de retorno
	push rbx
	push rcx
	push rdx
	push rbp
	push rdi
	push rsi
	push r8
	push r9
	push r10
	push r11
	push r12
	push r13
	push r14
	push r15

; Argumentos de las syscalls:
	push rax
	push rbx
	push rcx
	push rdx
	push rsi
	push rdi

; Argumentos por convencion de C en 64 bits:	
	pop r9
	pop r8
	pop rcx
	pop rdx
	pop rsi
	pop rdi
	call int_80
	
	push rax
	; signal pic EOI (End of Interrupt)
	mov al, 20h
	out 20h, al

	pop rax

	pop r15
	pop r14
	pop r13
	pop r12
	pop r11
	pop r10
	pop r9
	pop r8
	pop rsi
	pop rdi
	pop rbp
	pop rdx
	pop rcx
	pop rbx
	; pop rax
	iretq
	


;Zero Division Exception
_exception0Handler:
	exceptionHandler 0
	

haltcpu:
	cli
	hlt
	ret

register_saviour:
    mov [register_array],     rax
    mov [register_array+8],   rbx
    mov [register_array+16],  rcx
    mov [register_array+24],  rdx
    mov [register_array+32],  rsi
    mov [register_array+40],  rdi
    mov [register_array+48],  rbp
    mov [register_array+56],  rsp
    mov [register_array+64],  r8
    mov [register_array+72],  r9
    mov [register_array+80],  r10
    mov [register_array+88],  r11
    mov [register_array+96],  r12
    mov [register_array+104], r13
    mov [register_array+112], r14
    mov [register_array+120], r15
    mov rax, register_array
    ret

play_sound:
;;cargo la frecuencia
    mov     ax, 0xB6
    out     0x43, al         ; pone PIT en frecuencia deseada
    mov     ax, 1193180      ; carga la cte que usa para dividir
    mov     edx, 0            ; inicializa el divisor
    div     rdi
    mov     ax, di
    ;;mov     al, ah           ; pone el bit bajo en el divisor
    out     0x42, al         ; pone el bit bajo en el pit
    mov     al, ah           ; pone el bit alto en el divisor
    out     0x42, al         ;  pone el bit alto en el pit

;;prendo el speaker
    in      al, 0x61         ;;lee el valor del puerto
    mov     cl, al
    or      cl, 3
    cmp     al, cl
    jz      exit
    mov     al, cl
    out     0x61, al         ;;sobreescribo el puerto con la nueva configuracion
exit:
    ret

; Function to silence the sound
nosound:
    in      al, 0x61         ; guardo la info del puerto
    and     al, 0xFC         ; hago un and para apagarlo
    out     0x61, al         ; sobreescribo
    ret



SECTION .bss
	aux: resq 1
	register_array resq 16
