/*
** print.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 00:06:12 2008 jeremy cochoy
** Last update Tue Dec 23 18:29:58 2008 jeremy cochoy
*/

int	print(char *str)
{
  int	len;
  int	pos;

  len = 0;
  while (str[len])
    len++;
  pos = 0;
  while (pos < len)
    putchar(str[pos++]);
  return (len);
}
