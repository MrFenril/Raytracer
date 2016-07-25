/*
** my_putchar.c for my_putchar in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:24:30 2015 Sébastien Rigolat
** Last update Fri Jan 30 18:50:41 2015 Sébastien Rigolat
*/

#include "main.h"

int		my_putchar(char c, int fd)
{
  if (write(fd, &c, 1) == -1)
    return (-1);
  return (0);
}
