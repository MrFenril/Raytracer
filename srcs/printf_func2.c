/*
** func2.c for  in /home/michel_v/PSU_2014_my_printf
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Wed Nov 12 18:04:48 2014 Valentin Michel
** Last update Sun Jun  7 12:59:22 2015 valentin michel
*/

#include "main.h"

void		my_put_unsigned_b(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (my_put_unsignednbr_base(fd, i, BINARY) < 0)
    return;
}
