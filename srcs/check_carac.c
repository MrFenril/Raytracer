/*
** check_carac.c for check_carac in /home/rigola_s/TMP/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Fri Jun  5 22:07:23 2015 Sébastien Rigolat
** Last update Sun Jun  7 12:59:43 2015 Sébastien Rigolat
*/

#include "main.h"

int		check_hexa(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      if (!isxdigit(str[i++]))
	return (0);
    }
  return (1);
}

int		check_carac(const char **carac, char *str)
{
  int		i;

  i = 0;
  while (carac[i])
    {
      if (!my_strcmp(str, carac[i]))
	return (1);
      ++i;
    }
  return (0);
}

int		get_eye_carac(t_vect3f *eye, char **tab)
{
  if (size_tab(tab) < 4)
    {
      fprintf(stderr, "\e[1;31mCoords missing for EYE\n\e[0;m");
      return (0);
    }
  if ((eye->x = strtod(tab[1], NULL)) == HUGE_VALF
      || eye->x == HUGE_VALL
      || (eye->y = strtod(tab[2], NULL)) == HUGE_VALF
      || eye->y == HUGE_VALL
      || (eye->z = strtod(tab[3], NULL)) == HUGE_VALF
      || eye->z == HUGE_VALL)
    {
      fprintf(stderr, "\e[1;31mEye is to far.\n\e[0;m");
      return (0);
    }
  return (1);
}
