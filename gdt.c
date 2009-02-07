/*
** gdt.c for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Feb  3 02:08:52 2009 jeremy cochoy
** Last update Fri Feb  6 06:55:35 2009 jeremy cochoy
*/

#include "gdt.h"

t_gdt_reg	gdt_reg = {0, 0};
t_gdt_seg	*kgdt = (t_gdt_seg*)0x00;
u8		kgdt_idx = 0;

void	setGdtSeg(t_gdt_seg *seg, u32 base, u32 limit, u8 acces, u8 other)
{
  seg->lim_0to15 = (limit & 0xFFFF);
  seg->lim_16to19 = (limit & 0x0F0000) >> 16;
  seg->base_0to15 = (base & 0xFFFF);
  seg->base_16to23 = (base & 0xFF0000) >> 16;
  seg->base_24to31 = (base & 0xFF000000) >> 24;  
  seg->acces = acces;
  seg->other = (other & 0x0F);
}

void	getGdtSeg(t_gdt_seg *seg, u32 *base, u32 *limit, u8 *acces, u8 *other)
{
  *limit = seg->lim_0to15;
  *limit |= seg->lim_16to19 << 16;
  *base = seg->base_0to15;
  *base |= seg->base_16to23 << 16;
  *base |= seg->base_24to31 << 24;
  *acces = seg->acces;
  *other = seg->other;
}

void	pushGdtSeg(u32 base, u32 limit, u8 acces, u8 other)
{
  setGdtSeg(&kgdt[kgdt_idx], base, limit, acces, other);
  kgdt_idx++;
  gdt_reg.limit = 8 * kgdt_idx;
}

void	popGdt(u32 *base, u32 *limit, u8 *acces, u8 *other)
{
  getGdtSeg(&kgdt[kgdt_idx], base, limit, acces, other);
  kgdt_idx--;
  gdt_reg.limit = 8 * kgdt_idx;
}

void	refreshGdt(void)
{
  gdt_reg.limit = sizeof(t_gdt_seg) * kgdt_idx;
  gdt_reg.base = kgdt;

  /* reload GDT */
  asm("lgdt (gdt_reg)");

  /* change registers */
  asm("movw $0x10, %ax   \n \
       movw %ax, %ds     \n \
       movw %ax, %es     \n \
       movw %ax, %fs     \n \
       movw %ax, %gs     \n \
       ljmp $0x08, $next \n \
       next:             \n");
}
