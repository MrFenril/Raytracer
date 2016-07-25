/*
** my.h for my.h in /home/rigola_s/rendu/CPE_2014_bsq/include
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:27:51 2015 Sébastien Rigolat
** Last update Sat May 23 20:10:52 2015 jordan faucher
*/

#ifndef MY_H_
# define MY_H_

# define INT_OVER_P	2147483647
# define INT_OVER_N	-2147483648
# define DEC_MIN	48
# define DEC_MAX	57
# define FREE_SRC	1

char		**my_str_to_wordtab(char *str, char separator);
int		get_length(char *str, char separator);
int		my_strcmp(char *s1, const char *s2);
char		*my_strcpy(char *dest, char *src);
char		*my_strdup(char *src, int flag);
int		my_putstr(char *str, int fd);
int		size_word(char *str, int i);
int		my_putchar(char c, int fd);
int		my_putnbr(int nb, int fd);
int		size_tab(char **tab);
int		my_strlen(char *str);
int		my_getnbr(char *nbr);
int		my_puterror(char *str);
void		free_tab(char **tab);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_strncat(char *dest, char *str, char signe);

#endif /* !MY_H_ */
