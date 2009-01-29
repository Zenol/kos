/*
** memset.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 17:19:08 2008 jeremy cochoy
** Last update Thu Jan 15 03:45:42 2009 jeremy cochoy
*/

void	memset(char *ptr, int len, char c)
{
  int	pos;

  pos = 0;
  while (pos < len)
    {
      ptr[pos] = c;
      pos++;
    }
}
