/*
** my_strlen.c for my_strlen in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:32:01 2015 Sébastien Rigolat
** Last update Mon Jan  5 18:06:10 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!str)
    return (0);
  while (str[i])
    ++i;
  return (i);
}
