/*
** my_putnbr.c for my_put_nbr in /home/rigola_s/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed Jan 14 14:37:41 2015 Sébastien Rigolat
** Last update Fri Jan 30 18:51:16 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_putnbr(int nbr, int fd)
{
  int		cmp;

  cmp = 0;
  if (nbr < 0)
    {
      my_putchar('-', fd);
      if (nbr == INT_OVER_N)
	{
	  nbr = (nbr + 1) * (-1);
	  cmp = 1;
	}
      else
	nbr = nbr * (-1);
    }
  if (nbr >= 10 && my_putnbr((nbr / 10), fd) < 0)
    return (-1);
  nbr = (nbr % 10) + cmp;
  my_putchar(nbr + 48, fd);
  return (0);
}
