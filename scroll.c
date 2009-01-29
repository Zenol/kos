/*
** scroll.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 17:21:38 2008 jeremy cochoy
** Last update Tue Dec 23 18:23:50 2008 jeremy cochoy
*/

#include "klib.h"

void	scroll(int l)
{
  char	*src;
  char	*dst;

  if (l > 25 || l < 0)
    l = 25;
  dst = (char*)tty_m;
  src = (char*)(tty_m + l * 80 * 2);
  while (src < (char*)(MEM_TXT + 80 * 2 * 25))
    {
      *dst = *src;
      src++;
      dst++;
    }
  while (dst < (char*)(MEM_TXT + 80 * 2 * 25))
    *(dst++) = 0;
  tty_y -= l;
  if (tty_y < 0)
    tty_y = 0;
  tty_x = 0;
}
