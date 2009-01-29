	;; putstr : Kernel - Mode
putstr:
	;; Save context
	push ax
	push bx
	;; Start display
	.dsp
	lodsb			;mov al, [ds:si] & inc si
	cmp al, 0
	jz .end
	mov ah, 0x0E
	mov bx, 0x07
	int 0x10
	jmp .dsp
	.end
	;; Restor context
	pop ax
	pop bx
	ret
