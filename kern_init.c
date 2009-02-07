/*
** kernel_init.c for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Fri Feb  6 07:03:09 2009 jeremy cochoy
** Last update Fri Feb  6 07:03:12 2009 jeremy cochoy
*/

#include "kern.h"

void	gdt_reload(void)
{
  pushGdtSeg(0, 0, 0, 0);
  pushGdtSeg(0x0, 0xFFFFFF, 0x9B, 0x0D); /* CODE */
  pushGdtSeg(0x0, 0xFFFFFF, 0x93, 0x0D); /* DATA */
  pushGdtSeg(0x0, 0x0, 0x97, 0x0D); /* STACK */
  refreshGdt();
}
