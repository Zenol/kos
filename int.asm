;;
;; int.asm for kos in /home/cochoy_j/svn/kos/trunk
;; 
;; Made by jeremy cochoy
;; Login   <cochoy_j@epitech.net>
;; 
;; Started on  Sun Apr 19 23:56:20 2009 jeremy cochoy
;; Last update Mon Apr 20 00:14:13 2009 jeremy cochoy
;;

[EXTERN int_default]
[GLOBAL asm_int_default]

asm_int_default:
	call	int_default
	mov	al, 0x20
	out	0x20, al
	iret
