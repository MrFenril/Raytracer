/*
** my_puterror.c for rtracer in /Users/jfaucher/Rendu/Epitech/Igraph/MUL_2014_rtracer/lib
**
** Made by jordan faucher
** Login   <jfaucher@epitech.net>
**
** Started on  Sat May 23 20:09:39 2015 jordan faucher
** Last update Thu May 28 00:18:50 2015 adrien floch
*/

#include "main.h"

int	my_puterror(char *str)
{
  if (!str || write(2, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}
