/*
** my_printf.c for my_printf in /home/rigola_s/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed Jan 14 13:45:05 2015 Sébastien Rigolat
** Last update Thu May  7 16:26:34 2015 Sébastien Rigolat
*/

#include "main.h"

void		exec_func(int i, va_list ap, int fd)
{
  void		(*f[3])(va_list, int);

  f[0] = &my_putchara;
  f[1] = &my_putstring;
  f[2] = my_nbr;
  (*f[i])(ap, fd);
}

int		get_token(char flag, va_list ap, int fd)
{
  char		*token;
  int		i;

  token = "csde";
  i = 0;
  while (token[i])
    {
      if (token[i] == flag
	  && token[i] == 'e')
	fd = 2;
      else if (token[i] == flag)
	exec_func(i, ap, fd);
      ++i;
    }
  return (fd);
}

int		my_printf(const char *format, ...)
{
  int		i;
  int		fd;
  va_list	ap;

  i = 0;
  if (!format)
    return (0);
  va_start(ap, format);
  fd = 1;
  while (format[i])
    {
      if (format[i] == '%')
	{
	  fd = get_token(format[i + 1], ap, fd);
	  i += 2;
	}
      else
	my_putchar(format[i++], fd);
    }
  return (0);
}
