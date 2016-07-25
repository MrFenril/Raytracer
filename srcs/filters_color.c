/*
** filters.c for rtracer in /home/homes_d/rendu/MUL_2014_rtracer
**
** Made by David HOMES
** Login   <homes_d@epitech.net>
**
** Started on  Thu Jun  4 19:55:14 2015 David HOMES
** Last update Sun Jun  7 16:50:36 2015 David HOMES
*/

#include "main.h"

int		filter_neg(int color)
{
  return (~color);
}

int		filter_grey(int color)
{
  int		r;
  int		g;
  int		b;
  double	moy;

  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  moy = (r * 0.3 + g * 0.4 + b * 0.2);
  return (get_color(moy, moy, moy));
}

int		filter_sepia(int color)
{
  int		r;
  int		g;
  int		b;
  double	moy;

  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  moy = (r * 0.5 + g * 0.6 + b * 0.3);
  b = (moy * 101) / 255;
  g = (moy * 128) / 255;
  r = (moy * 162) / 255;
  return (get_color(b, g, r));
}

int		filter_water(int color)
{
  int		r;
  int		g;
  int		b;
  double	moy;

  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  moy = (r * 0.3 + g * 0.6 + b * 0.5);
  r = (moy * 101) / 255;
  g = (moy * 128) / 255;
  b = (moy * 162) / 255;
  return (get_color(b + 50, g + 50, 0 + 50));
}

int		filter_noise(int color)
{
  static int	i = 0;
  int		r;
  int		g;
  int		b;

  ++i;
  srand(i);
  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  b += rand() * i % 255;
  g += rand() * i % 255;
  r += rand() * i % 255;
  return (get_color(b, g, r));
}
