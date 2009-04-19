/*
** putchar.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 00:51:50 2008 jeremy cochoy
** Last update Sun Apr 19 21:55:59 2009 jeremy cochoy
*/

#include "klib.h"

int	putchar(int c)
{
  switch (c)
    {
    case '\n':
      tty_x = 0;
      tty_y++;
      break;
    case '\t':
      putchar(' ');
      putchar(' ');
      putchar(' ');
      putchar(' ');
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
  return (c);
}
