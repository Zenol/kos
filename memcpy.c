/*
** memcpy.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 17:59:55 2008 jeremy cochoy
** Last update Thu Jan 15 03:45:27 2009 jeremy cochoy
*/

void	memcpy(char *src, char *dst, int len)
{
  while (len)
    {
      *src = *dst;
      src++;
      dst++;
      len--;
    }
}
