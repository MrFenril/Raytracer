/*
** my_printf.h for my_printf in /home/rigola_s/include
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed Jan 14 14:46:37 2015 Sébastien Rigolat
** Last update Fri Jan 30 19:16:57 2015 Sébastien Rigolat
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include "main.h"

int		get_token(char flag, va_list ap, int fd);
void		exec_func(int i, va_list ap, int fd);
int		my_printf(const char *format, ...);
void		my_putstring(va_list ap, int fd);
void		my_putchara(va_list ap, int fd);
void		my_nbr(va_list ap, int fd);

#endif /* !MY_PRINTF_H_ */
