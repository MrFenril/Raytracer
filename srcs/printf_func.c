/*
** func.c for  in /home/michel_v/PSU_2014_my_printf
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Tue Nov 11 20:02:06 2014 Valentin Michel
** Last update Sun Jun  7 12:59:57 2015 valentin michel
*/

#include "main.h"

void		my_put_d(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_putnbr_base(fd, i, DECIMAL) < 0)
    return;
}

void		my_put_unsigned_o(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_put_unsignednbr_base(fd, i, OCTALE) < 0)
    return;
}

void		my_put_unsigned_d(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_put_unsignednbr_base(fd, i, DECIMAL) < 0)
    return;
}

void		my_put_hexalow(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_put_unsignednbr_base(fd, i, HEXALOW) < 0)
    return;
}

void		my_put_hexaupp(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_put_unsignednbr_base(fd, i, HEXAUPP) < 0)
    return;
}
