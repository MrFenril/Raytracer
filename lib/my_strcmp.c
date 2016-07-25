/*
** my_strcmp.c for my_strcmp in /home/rigola_s/rendu/MUL_2014_rtv1/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Mar  2 12:48:16 2015 Sébastien Rigolat
** Last update Tue May 19 17:03:28 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_strcmp(char *s1, const char *s2)
{
  int		i;

  i = 0;
  if ((!s1 && s2)
      || (s1 && !s2))
    return (-1);
  else if (!s1 && !s2)
    return (0);
  while (s2[i] && s1[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  return (s1[i] - s2[i]);
}
