/*
** idt.h for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Fri Feb  6 06:42:44 2009 jeremy cochoy
** Last update Mon Apr 20 00:03:15 2009 jeremy cochoy
*/

#ifndef IDT_H_
# define IDT_H_

#include "types.h"

#define INT_GATE	0x8E00
#define TASK_GATE	0xE500

#define IDT_SIZE	0xFF

/*
** IDT Segment
*/
typedef struct			s_idt_seg
{
  u16		offset_0to15;
  u16		select;
  u16		type;
  u16		offset_16to31;
} __attribute__ ((packed))	t_idt_seg;

/*
** IDT register
*/
typedef struct			s_idt_reg
{
  u16		limit;
  t_idt_seg	*base;
} __attribute__ ((packed))	t_idt_reg;

void	setIdtSeg(t_idt_seg *seg, u32 offset, u16 select, u16 type);
void	getIdtSeg(t_idt_seg *seg, u32 *offset, u16 *select, u16 *type);
void	initIdt(void);
void	refreshIdt(void);

#endif /* !IDT_H_ */
