/*
** memcpy.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 17:59:55 2008 jeremy cochoy
** Last update Sun Apr 19 21:55:00 2009 jeremy cochoy
*/

#include "klib.h"

void	*memcpy(void *dst, void *src, int len)
{
  char	*dst_c;
  char	*src_c;

  dst_c = dst;
  src_c = src;
  while (len)
    {
      *src_c = *dst_c;
      dst_c++;
      src_c++;
      len--;
    }
  return (dst);
}
