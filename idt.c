/*
** idt.c for kos in /home/cochoy_j/svn/kos/trunk
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Apr 19 22:20:52 2009 jeremy cochoy
** Last update Mon Apr 20 00:04:29 2009 jeremy cochoy
*/

#include "sysio.h"
#include "idt.h"
#include "int.h"

t_idt_reg	idt_reg = {0, 0};
t_idt_seg	*kidt = (t_idt_seg*)0x800;

void	setIdtSeg(t_idt_seg *seg, u32 offset, u16 select, u16 type)
{
  seg->offset_0to15 = 0xFFFF & offset;
  seg->offset_16to31 = (0xFFFF0000 & offset) >> 16;
  seg->select = select;
  seg->type = type;
}

void	getIdtSeg(t_idt_seg *seg, u32 *offset, u16 *select, u16 *type)
{
  *offset = seg->offset_0to15 | (seg->offset_16to31 << 16);
  *select = seg->select;
  *type = seg->type;
}

void	refresIdt(void)
{
  asm volatile ("lidtl (idt_reg)");
}

void	initIdt(void)
{
  int	i;

  i = 0;
  while (i < IDT_SIZE)
    {
      setIdtSeg(kidt + i, (u32)asm_int_default, 0x08, INT_GATE);
      i++;
    }
  refresIdt();
}
