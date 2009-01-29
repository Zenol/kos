/*
** strlen.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sun Dec 21 00:47:01 2008 jeremy cochoy
** Last update Sun Dec 21 00:47:26 2008 jeremy cochoy
*/

int	strlen(char *str)
{
  int	len;

  len = 0;
  while (str[len])
    len++;
  return (len);
}
