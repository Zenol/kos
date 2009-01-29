/*
** ksleep.c for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Tue Dec 23 18:36:51 2008 jeremy cochoy
** Last update Tue Dec 23 18:42:26 2008 jeremy cochoy
*/

void	ksleep(unsigned int t)
{
  t *= 10000;
  while (t)
    t--;
}
