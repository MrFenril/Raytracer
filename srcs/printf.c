/*
** printf.c for  in /home/michel_v/PSU_2014_my_printf
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Mon Nov 10 15:04:39 2014 Valentin Michel
** Last update Sun Jun  7 12:59:09 2015 valentin michel
*/

/*
** A gere : cdiouxX%bsS
*/

#include "main.h"

int		use_option(int fd, va_list ap, int i)
{
  void		(*tab[10])();

  if (ap == NULL || i < 0)
    return (-1);
  tab[0] = &my_put_ap_char;
  tab[1] = &my_put_d;
  tab[2] = &my_put_d;
  tab[3] = &my_put_unsigned_o;
  tab[4] = &my_put_unsigned_d;
  tab[5] = &my_put_hexalow;
  tab[6] = &my_put_hexaupp;
  tab[7] = &my_put_unsigned_b;
  tab[8] = &my_put_ap_str;
  tab[9] = &my_put_adress;
  (*tab[i])(fd, ap);
  return (0);
}

void		check_option(int fd, const char *str, va_list ap, int j)
{
  int		i;
  char		*flag;

  if (str == NULL || my_str_len(str) < 0
      || ap == NULL || j < 0)
    return;
  i = 0;
  flag = "cdiouxXbsp";
  while (flag[i] != 0)
    {
      if (flag[i] == str[j] && use_option(fd, ap, i) <= 0)
	return;
      ++i;
    }
}

int		my_fdprintf(int fd, const char *str, ...)
{
  int		i;
  va_list	ap;

  if (str == NULL || my_str_len(str) < 0)
    return (-1);
  va_start(ap, str);
  i = 0;
  while (str[i] != 0)
    {
      if ((str[i] == '%') && (str[i + 1] != '%'))
	check_option(fd, str, ap, i++ + 1);
      else if (str[i] == '%' && (str[i + 1] == '%'))
	{
	  if (write(fd, &str[i + 1], 1) < 0)
	    return (-1);
	}
      else if (write(fd, &str[i], 1) < 0)
	return (-1);
      ++i;
    }
  va_end(ap);
  return (0);
}
