/*
** putchar.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 00:51:50 2008 jeremy cochoy
** Last update Tue Dec 23 18:34:06 2008 jeremy cochoy
*/

#include "klib.h"

int	putchar(char c)
{
  switch (c)
    {
    case '\n':
      tty_x = 0;
      tty_y++;
      break;
    case '\r':
      tty_x = 0;
      break;
    default:
      tty_m[tty_x * 2 + tty_y * 80 * 2] = c;
      tty_m[tty_x * 2 + tty_y * 80 * 2 + 1] = tty_c;
      tty_x++;
    }
  if (tty_x >= 80)
    {
      tty_x = 0;
      tty_y++;
    }
  if (tty_y >= 25)
    scroll(3);
  return (1);
}
