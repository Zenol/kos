/*
** idt.h for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Fri Feb  6 06:42:44 2009 jeremy cochoy
** Last update Fri Feb  6 06:59:41 2009 jeremy cochoy
*/

#ifndef IDT_H_
# define IDT_H_

#include "types.h"

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
typedef struct			s_gdt_reg
{
  u16		limit;
  t_gdt_seg	*base;
} __attribute__ ((packed))	t_gdt_reg;

void	setIdtSeg(t_idt_seg *seg, u32 offset, u16 select, u16 type);
void	getIdtSeg(t_idt_seg *seg, u32 *offset, u16 *select, u16 *type);
void	pushIdtSeg(u32 offset, u16 select, u16 type);
void	popIdt(u32 *offset, u16 *select, u16 type);
void	refreshIdt(void);

#endif /* !IDT_H_ */
