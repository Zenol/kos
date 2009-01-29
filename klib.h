/*
** klib.h for klib in /nfs/export/work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Sat Dec 20 22:35:27 2008 jeremy cochoy
** Last update Thu Jan 15 03:04:41 2009 jeremy cochoy
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

extern int	print(char *str);
extern int	putstr(char *str);
extern int	putchar(char c);
extern int	putnbr(int n);
extern void	scroll(int l);
extern void	ksleep(unsigned int t);

void	memcpy(void *src, void *dst, int len);
void	memset(void *ptr, int len, char c);

#include "klib_sys.h"
#include "color.h"

#endif
