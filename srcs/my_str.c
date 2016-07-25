/*
** my_putnbr_base.c for  in /home/michel_v/PSU_2014_my_printf
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Mon Nov 10 17:31:19 2014 Valentin Michel
** Last update Sun Jun  7 12:59:15 2015 valentin michel
*/

#include "main.h"

void		my_put_ap_char(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (write(fd, &i, 1) < 0)
    return;
}

void		my_put_ap_str(int fd, va_list ap)
{
  const char	*str;

  if (ap == NULL)
    return;
  str = va_arg(ap, const char *);
  if (write(fd, str, my_str_len(str)) < 0)
    return;
}

void		my_put_adress(int fd, va_list ap)
{
  int		i;

  if (ap == NULL)
    return;
  i = va_arg(ap, int);
  if (write(fd, "0x", 2) < 0)
    return;
  if ( my_putnbr_base(fd, i, HEXALOW) < 0)
    return;
}
int		my_putnbr_base(int fd, int nb, const char *base)
{
  int		neg;
  int		size_base;

  if (base == NULL || my_str_len(base) < 0)
    return (-1);
  neg = 0;
  if ((size_base = my_str_len(base)) < 0)
    return (-1);
  if (nb < 0)
    {
      if (write(1, "-", 1) < 0)
	return (-1);
      nb = (nb + 1) * (-1);
      neg = 1;
    }
  if (nb >= size_base && my_putnbr_base(fd, nb / size_base, base) < 0)
    return (-1);
  nb = (nb % size_base) + neg;
  if (write(fd, &base[nb], 1) < 0)
    return (-1);
  return (0);
}

int		my_put_unsignednbr_base(int fd, unsigned int nb,
					const char *base)
{
  unsigned int	size_base;

  if (base == NULL || my_str_len(base) < 0)
    return (-1);
  size_base = (unsigned)(my_str_len(base));
  if (nb >= size_base && my_put_unsignednbr_base(fd, nb / size_base, base) < 0)
    return (-1);
  nb = (nb % size_base);
  if (write(fd, &base[nb], 1) < 0)
    return (-1);
  return (0);
}
