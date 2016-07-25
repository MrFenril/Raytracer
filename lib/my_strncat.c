/*
** my_strncat.c for corewar in /home/rigola_s/test/CPE_2014_corewar/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Fri Mar 13 12:57:04 2015 Sébastien Rigolat
** Last update Sun Apr 12 15:54:25 2015 adrien floch
*/

#include "main.h"

char	*my_strncat(char *dest, char *src, char signe)
{
  int	i;
  int	j;
  char	*tab;

  i = 0;
  j = 0;
  if ((tab = malloc(sizeof(char) * 12 + 1)) == NULL)
    return (NULL);
  while (src[i] != signe && src[i + 1] != 's')
    {
      tab[i] = src[i];
      i++;
    }
  while (dest[j] != '\0')
    {
      tab[i] = dest[j];
      j++;
      i++;
    }
  tab[i] = '\0';
  return (tab);
}
