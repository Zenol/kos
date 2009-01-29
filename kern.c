/*
** kern.c for kos in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 01:04:39 2008 jeremy cochoy
** Last update Thu Jan 15 03:04:56 2009 jeremy cochoy
*/

#include "klib.h"

int	main(void);

void	_start(void)
{
  main();
}

extern char tty_c;
int	main(void)
{
  int	i;
  int	cnt;

  setColor(RED, TRUE, BLACK, 0);
  tty_x += 12;
  tty_y += 3;
  print("Hello world\n");
  tty_c = 32;
  cnt = 0;
  while(1)
    {
      tty_c ^= 42;
      putnbr(cnt++);
      putchar('\r');
      ksleep(1000);
    }
}
