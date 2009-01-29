/*
** color.c for kos in /work/kos
** 
** Made by jeremy cochoy
** Login   <cochoy_j@epitech.net>
** 
** Started on  Thu Jan 15 02:52:08 2009 jeremy cochoy
** Last update Thu Jan 15 02:57:28 2009 jeremy cochoy
*/

#include "klib_sys.h"
#include "color.h"

void		setColor(char color, char intn, char background, char cli)
{
  t_tty_color	c;

  c.color = color;
  c.intn = intn;
  c.background = background;
  c.cli = cli;
  tty_c = *(char*)(&c);
}

void	getColor(char *color, char *intn, char *background, char *cli)
{
  t_tty_color	*c;

  c = (t_tty_color*)(&tty_c);
  *color = c->color;
  *intn = c->intn;
  *background = c->background;
  *cli = c->cli;
}
