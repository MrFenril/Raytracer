/*
** my_getnbr.c for my_get_nbr in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue Jan  6 15:48:41 2015 Sébastien Rigolat
** Last update Tue Jan  6 15:50:08 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_getnbr(char *nbr)
{
  int		i;
  int		cmp;
  int		nb;

  i = 0;
  cmp = 0;
  nb = 0;
  if (nbr == NULL || my_strlen(nbr) < 0)
    return (0);
  while (nbr[i] != 0 && (nbr[i] == '-' || nbr[i] == '+'))
    {
      if (nbr[i++] == '-')
	cmp = (cmp + 1) % 2;
    }
  while (nbr[i] != 0 && (nbr[i] >= DEC_MIN && nbr[i] <= DEC_MAX))
    {
      if (cmp == 0 && (INT_OVER_P  - (nb * 10) - (nbr[i] - 48)) >= 0)
	nb = nb * 10 + ((nbr[i] - 48));
      else if (cmp == 1 && (INT_OVER_N - (nb * 10) + (nbr[i] - 48)) <= 0)
	nb = nb * 10 - ((nbr[i] - 48));
      else
	return (0);
      ++i;
    }
  return (nb);
}
