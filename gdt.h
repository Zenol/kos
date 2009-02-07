/*
** gdt.h for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Feb  3 02:06:50 2009 jeremy cochoy
** Last update Fri Feb  6 06:59:54 2009 jeremy cochoy
*/

#ifndef GDT_H_
# define GDT_H_

#include "types.h"

/*
** GDT Segment
*/
typedef struct			s_gdt_seg
{
  u16		lim_0to15;
  u16		base_0to15;
  u8		base_16to23;
  u8		acces;
  u8		lim_16to19 : 4;
  u8		other : 4;
  u8		base_24to31;
} __attribute__ ((packed))	t_gdt_seg;

/*
** GDT register
*/
typedef struct			s_gdt_reg
{
  u16		limit;
  t_gdt_seg	*base;
} __attribute__ ((packed))	t_gdt_reg;

void	setGdtSeg(t_gdt_seg *seg, u32 base, u32 limit, u8 acces, u8 other);
void	getGdtSeg(t_gdt_seg *seg, u32 *base, u32 *limit, u8 *acces, u8 *other);
void	pushGdtSeg(u32 base, u32 limit, u8 acces, u8 other);
void	popGdt(u32 *base, u32 *limit, u8 *acces, u8 *other);
void	refreshGdt(void);

#endif /* !GDT_H_ */
