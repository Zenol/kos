/*
** klib.h for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sat Dec 20 22:35:27 2008 jeremy cochoy
** Last update Sun Apr 19 21:55:54 2009 jeremy cochoy
*/

#ifndef KLIB_H_
# define KLIB_H_

# define	MEM_TXT	0xB8000
# define	MEM_VGA	0xA0000

# ifndef TRUE
#  define	TRUE	1
# endif /* !TRUE */
# ifndef FALSE
#  define	FALSE	0
# endif /* !FALSE */

int	print(char *str);
int	putstr(char *str);
int	putchar(int c);
int	putnbr(int n);
void	scroll(int l);
void	clear(void);
void	ksleep(unsigned int t);

void	*memcpy(void *dst, void *src, int len);
void	*memset(void *ptr, int c, int len);

#include "klib_sys.h"
#include "color.h"

#endif
