/*
** sysio.h for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Fri Feb  6 04:58:52 2009 jeremy cochoy
** Last update Fri Feb  6 06:34:51 2009 jeremy cochoy
*/

#ifndef SYSIO_H_
# define SYSIO_H_

/* Stop interupts */
# define	cli	asm volatile ("cli"::)

/* Start interupts */
# define	sti	asm volatile ("sti"::)

/* Write 1byte on a port */
# define	outb(port, value)		\
		asm volatile ("outb %%al, %%dx"	\
		:: "d" (port), "a" (value))

/* Write 1byte and wait 1clock */
# define	outbp(port, value)				\
		asm volatile ("outb %%al, %%dx; jmp l; l:"	\
		:: "d" (port), "a" (value)

/* Read 1byte from a port */
# define	inb(port) ({			\
		unsigned char _res;		\
		asm volatile ("inb %%dx, %%al"	\
		: "=a" (_res) : "d" (port));	\
		_res;				\
		})

#endif /* !SYSIO_H_ */
