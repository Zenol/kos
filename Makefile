##
## Makefile for kos in /nfs/export/work/kos
## 
## Made by jeremy cochoy
## Login   <cochoy_j@epitech.net>
## 
## Started on  Sat Dec 20 18:11:32 2008 jeremy cochoy
## Last update Fri Feb  6 07:04:25 2009 jeremy cochoy
##

LIBSRC	=	print.c		\
		memset.c	\
		memcpy.c	\
		strlen.c	\
		scroll.c	\
		putchar.c	\
		putnbr.c	\
		tty.c		\
		ksleep.c	\
		color.c		\
		gdt.c		\


LIBOBJ	=	$(LIBSRC:.c=.o)

floppy:	kern.c kern_init.c
	nasm -f bin mbr.asm -o mbr.bin
	gcc -c kern_init.c -o kern_init.o
	gcc -c kern.c -o kern.o
	ld --oformat binary -Ttext 1000 kern.o kern_init.o $(LIBOBJ) -o kern.bin
	cat mbr.bin kern.bin /dev/zero | dd of=floppy bs=512 count=2880

.c.o:
	gcc -Wall -c $< -o $@

.lib:	$(LIBOBJ)
	@echo 'done' > .lib

lib:	.lib

clean:
	rm -f mbr.bin kern.bin floppy

re:	clean floppy

.PHONY:	clean re lib