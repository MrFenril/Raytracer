/*
** my_putstr.c for my_putstr in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:26:25 2015 Sébastien Rigolat
** Last update Mon Jan  5 18:08:48 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_putstr(char *str, int fd)
{
  if (!str
      || write(fd, str, my_strlen(str)) == -1)
    return (-1);
  return (0);
}
