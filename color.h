/*
** color.h for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Thu Jan 15 02:47:09 2009 jeremy cochoy
** Last update Thu Jan 15 03:03:26 2009 jeremy cochoy
*/

#ifndef COLOR_H_
# define COLOR_H_

# define	BLACK	0x0
# define	BLUE	0x1
# define	GREEN	0x2
# define	CYAN	0x3
# define	RED	0x4
# define	PURPLE	0x5
# define	YELLOW	0x6
# define	WHITE	0x7

typedef struct	s_tty_color
{
  char		color : 3;
  char		intn : 1;
  char		background : 3;
  char		cli : 1;
}		t_tty_color;

/*
** Change write color
*/
void	setColor(char color, char intn, char background, char cli);

/*
** Get write color
*/
void	getColor(char *color, char *intn, char *background, char *cli);

#endif /* !COLOR */
