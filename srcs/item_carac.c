/*
** item_carac.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu May  7 00:05:22 2015 Sébastien Rigolat
** Last update Sun Jun  7 13:20:30 2015 Sébastien Rigolat
*/

#include "main.h"

int		item_coord(t_elem *elem, char **tab)
{
  if (size_tab(tab) < 4)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Coords missing\n\e[0;m", 2);
      return (0);
    }
  if ((elem->pos.x = strtod(tab[1], NULL)) == HUGE_VALF
      || elem->pos.x == HUGE_VALL
      || (elem->pos.y = strtod(tab[2], NULL)) == HUGE_VALF
      || elem->pos.y == HUGE_VALL
      || (elem->pos.z = strtod(tab[3], NULL)) == HUGE_VALF
      || elem->pos.z == HUGE_VALL)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("\e[1;31mItem is to far.\n\e[0;m", 2);
      return (0);
    }
  return (1);
}

int		item_ray(t_elem *elem, char **tab)
{
  if (size_tab(tab) < 2)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("ray missing for item.\n\e[0;m", 2);
      return (0);
    }
  if ((elem->R = strtod(tab[1], NULL)) == HUGE_VALF
      || elem->R == HUGE_VALL)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Item is too big.\n\e[0;m", 2);
      return (0);
    }
  return (1);
}

int		item_color(t_elem *elem, char **tab)
{
  if (size_tab(tab) < 2 || !check_hexa(tab[1]))
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Color is missing or invalid\n\e[0;m", 2);
      return (0);
    }
  if ((elem->color = (int)strtol(tab[1], NULL, 16)) > 0xFFFFFF
       || elem->color < 0)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      return (my_printf("%eUnknown color : [%s].\n\e[0;m", tab[1]));
    }
  return (1);
}

int		item_effect(t_elem *elem, char **tab)
{
  if (size_tab(tab) < 4)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      return (my_printf("%eEffect is missing\n\e[0;m"));
    }
  if ((elem->b = strtod(tab[1], NULL)) == HUGE_VALF
      || elem->b == HUGE_VALL
      || (elem->t = strtod(tab[2], NULL)) == HUGE_VALF
      || elem->t == HUGE_VALL
      || (elem->r = strtod(tab[3], NULL)) == HUGE_VALF
      || elem->r == HUGE_VALL)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Effect is to invalid.\n\e[0;m", 2);
      return (0);
    }
  return (1);
}

int		item_intensity(t_elem *elem, char **tab)
{
  if (size_tab(tab) == 1)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Itensity is missing for SPOT \n[0;m", 2);
      return (0);
    }
  if ((elem->i = strtod(tab[1], NULL)) == HUGE_VALF
      || elem->i == HUGE_VALL)
    {
      my_putstr("\e[1;31m\n-------------------------------\n", 2);
      my_putstr("Intensity is too big.\n\e[0;m", 2);
      return (0);
    }
    return (1);
}
