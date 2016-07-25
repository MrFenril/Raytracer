/*
** filters_tv.c for rtracer in /home/homes_d/rendu/MUL_2014_rtracer
** 
** Made by David HOMES
** Login   <homes_d@epitech.net>
** 
** Started on  Fri Jun  5 05:43:54 2015 David HOMES
** Last update Fri Jun  5 07:41:35 2015 David HOMES
*/

#include "main.h"

int		filter_line_h(int color)
{
  static int	i = 0;
  static int	count = 0;

  count++;
  if (count == WIN_X)
    {
      count = 0;
      ++i;
    }
  if (i % 4 == 2 || i % 4 == 3)
    return (BLACK);
  return (color);
}

int		filter_line_v(int color)
{
  static int	i = -1;

  ++i;
  if (i % 4 == 2 || i % 4 == 3)
    return (BLACK);
  return (color);
}

int		filter_canal(int color)
{
  static int	count = 0;
  static int	save = -1;
  static int	i = 0;

  if (save == -1)
    save = color;
  ++count;
  if (count == WIN_X)
    {
      count = 15;
      ++i;
    }
  if (i % 40 == 20 || count % 40 == 20)
    save = color;
  return (save);
}

int		filter_oldtv(int color)
{
  return (filter_grey(filter_line_h(filter_noise(filter_canal(color)))));
}
