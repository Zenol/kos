/*
** memset.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 17:19:08 2008 jeremy cochoy
** Last update Sun Apr 19 21:50:28 2009 jeremy cochoy
*/

#include "klib.h"

void	*memset(void *ptr, int c, int len)
{
  int	pos;

  pos = 0;
  while (pos < len)
    {
      ((char*)ptr)[pos] = (char)c;
      pos++;
    }
  return (ptr);
}
