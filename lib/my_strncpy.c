/*
** my_strncpy.c for  in /home/fauche_j/rendu/Piscine_C_J06/ex_02
**
** Made by jordan faucher
** Login   <fauche_j@epitech.net>
**
** Started on  Mon Oct  6 09:38:09 2014 jordan faucher
** Last update Sat May 23 20:05:29 2015 jordan faucher
*/

#include "my.h"

char	*my_strncpy(char *dest, char *src, int n)
{
  int	index;

  index = 0;
  while (src[index] != 0)
    {
      if (index < n)
	{
	  dest[index] = src[index];
	}
      else
	{
	  dest[n] = src[index];
	}
      index = index + 1;
    }
  dest[n] = '\0';
  return (dest);
}
