[BITS 16]
[ORG 0x0]

%define KERN_SEG_START	0x100
%define NB_BLOCKS	42

	jmp mbr
%include "putstr.asm"
mbr:

; copy drive number
	mov [bootdrive], dl

; set segment starting at 0x07C0
	mov ax, 0x07C0
	mov ds, ax
	mov es, ax
	mov ax, 0x8000
	mov ss, ax
	mov sp, 0xF000

; display a msg
	mov si, load_msg
	call putstr

; load kernel
	xor ax, ax
	int 0x13
	
	push es			; Context
	
	mov ax, KERN_SEG_START
	mov es, ax		; Copy addr seg
	mov bx, 0		; Copy addr off
	
	mov ah, 2		; Copy datas
	mov al, NB_BLOCKS	; Nb blocks
	mov ch, 0		; low cylinder number
	mov cl, 2		; sector number (1=mbr)
	mov dh, 0		; head number
	mov dl, [bootdrive]	; drive number

	int 0x13

	pop es			; Context

; calc gdt len
	mov ax, gdt_end
	mov bx, gdt
	sub ax, bx
	mov word [gdt_ptr_limit], ax

; calc gdt addr
	xor eax, eax
	xor ebx, ebx
	mov ax, ds
	mov ecx, eax
	shl ecx, 4		; * 16
	mov bx, gdt
	add ecx, ebx
	mov dword [gdt_ptr_base], ecx

; unable interuptions
	cli

; load gdt
	lgdt [gdt_ptr]

; real mode
	mov eax, cr0
	or ax, 1		; PE = 1 (CR0)
	mov cr0, eax

; near jump
	jmp next
next:

; init data seg
	mov ax, 0x10
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

	mov ss, ax		; stack
	mov esp, 0x9F000

; jmp kernel
	jmp dword 0x8:0x1000

load_msg:
dd	'Loading Kernel', 0

	;; Drive Number
bootdrive	dd	0

; -------------------------   GDT   -------------------------
gdt:
	;; null
	db	0, 0, 0, 0, 0, 0, 0, 0
gdt_cs:
	;; cs
	db	0xFF, 0xFF, 0x0, 0x0, 0x0, 10011011b, 11011111b, 0x0
gdt_ds:
	;; ds
	db	0xFF, 0xFF, 0x0, 0x0, 0x0, 10010011b, 11011111b, 0x0
gdt_end:

; ------------------------- GDT ptr -------------------------
gdt_ptr:
	;; len
gdt_ptr_limit	dw	0
	;; addr
gdt_ptr_base	dd	0

times 510-($-$$) db 144
dw 0xAA55