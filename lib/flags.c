/*
** flags.c for my_printf in /home/rigola_s/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed Jan 14 14:32:31 2015 Sébastien Rigolat
** Last update Fri Jan 30 19:13:03 2015 Sébastien Rigolat
*/

#include "main.h"

void		my_nbr(va_list ap, int fd)
{
  int		nb;

  nb = va_arg(ap, int);
  my_putnbr(nb, fd);
}

void		my_putstring(va_list ap, int fd)
{
  char		*str;

  str = va_arg(ap, char *);
  my_putstr(str, fd);
}

void		my_putchara(va_list ap, int fd)
{
  char		c;

  c = va_arg(ap, int);
  my_putchar(c, fd);
}
