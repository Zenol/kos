[BITS 16]
[ORG 0x0]

		jmp kern
%include "putstr.asm"
kern:
	mov ax, 0x100
	mov ds, ax
	mov es, ax

	mov si, alive_msg
	call putstr
	mov si, alive_msg
	call putstr
	mov ax, 0xB800
	mov es, ax
	mov bx, 0
	mov ax, 'a'
	mov word [es:bx], ax
	inc bx
	mov ax, 'z'
	mov word [es:bx], ax
	inc bx
	mov ax, 'b'
	mov word [es:bx], ax
	inc bx
	mov ax, 'b'
	mov word [es:bx], ax

alive:	
	jmp alive


	
alive_msg	dd	"I'm Alive!!!", 0
