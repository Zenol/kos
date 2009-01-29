#include <unistd.h>
#include "types.h"

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

typedef struct	s_gdt_reg
{
  u16		limit;
  t_gdt_seg	*base;
}		t_gdt_reg;

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

void	kinit(void)
{
  pushGdtSeg(0, 0, 0, 0);
}

void	popGdt(u32 *base, u32 *limit, u8 *acces, u8 *other)
{
  getGdtSeg(&kgdt[kgdt_idx], base, limit, acces, other);
  kgdt_idx--;
  gdt_reg.limit = 8 * kgdt_idx;
}

int	main(void)
{
  t_gdt_seg	seg;

  setGdtSeg(&seg, 0x0, 0x0FFFF, 0x9B, 0x0);

  write(1, &seg, sizeof(t_gdt_seg));

  int base;
  int limit;
  char acces;
  short int other;

  getGdtSeg(&seg, &base, &limit, &acces, &other);

  printf("%x, %x, %x, %x", base, limit, (int)acces, other);

  return (0);
}
