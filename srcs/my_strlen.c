/*
** my_strlen.c for  in /home/michel_v/rendu/Piscine_C_J04
**
** Made by Valentin Michel
** Login   <michel_v@epitech.net>
**
** Started on  Thu Oct  2 09:53:52 2014 Valentin Michel
** Last update Sun Jun  7 13:00:02 2015 valentin michel
*/

#include "main.h"

int		my_strlen(char *str)
{
  int		i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int		my_str_len(const char *str)
{
  int		i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    ++i;
  return (i);
}
