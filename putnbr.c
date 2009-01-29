/*
** putnbr.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 00:47:54 2008 jeremy cochoy
** Last update Tue Dec 23 18:35:02 2008 jeremy cochoy
*/

#include "klib.h"

int	putnbr(int n)
{
  if (n < 0)
    {
      if (putchar('-') < 0)
	return (-1);
      n = -n;
    }
  if (n >= 10)
    return (putnbr(n / 10) && putchar(n % 10 + '0'));
  else
    return (putchar(n + '0'));
}
