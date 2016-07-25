/*
** my_printf.h for  in /home/michel_v/PSU_2014_my_printf
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Mon Nov 10 17:34:38 2014 Valentin Michel
** Last update Sun Jun  7 12:59:52 2015 valentin michel
*/

#ifndef FDPRINTF_H_
# define FDPRINTF_H_

# include <stdarg.h>

# define BINARY		"01"
# define OCTALE		"01234567"
# define DECIMAL	"0123456789"
# define HEXALOW	"0123456789abcdef"
# define HEXAUPP	"0123456789ABCDEF"

int		my_str_len(const char *);

/*
** my_str.c
*/

void		my_put_ap_char(int, va_list);
void		my_put_ap_str(int, va_list);
void		my_put_adress(int, va_list);
int		my_putnbr_base(int, int, const char *);
int		my_put_unsignednbr_base(int, unsigned int, const char *);

/*
** printf.c
*/

int		use_option(int, va_list, int);
void		check_option(int, const char *, va_list, int);
int		my_fdprintf(int, const char *, ...);

/*
** func.c
*/

void		my_put_d(int, va_list);
void		my_put_unsigned_o(int, va_list);
void		my_put_unsigned_d(int, va_list);
void		my_put_hexalow(int, va_list);
void		my_put_hexaupp(int, va_list);

/*
** func2.c
*/

void		my_put_unsigned_b(int, va_list);

#endif /* !FDPRINTF_H_ */
