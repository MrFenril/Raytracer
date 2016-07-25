/*
** my_strdup.c for my_strdup in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:33:04 2015 Sébastien Rigolat
** Last update Mon May 18 23:17:35 2015 Sébastien Rigolat
*/

#include "main.h"

char		*my_strdup(char *src, int flag)
{
  int		i;
  char		*dest;

  i = 0;
  if (!src
      || !(dest = malloc(sizeof(char) * (my_strlen(src) + 1))))
    return (NULL);
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  if (flag == FREE_SRC)
    free(src);
  return (dest);
}
