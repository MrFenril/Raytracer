/*
** filters_next.c for rtracer in /home/homes_d/rendu/MUL_2014_rtracer
** 
** Made by David HOMES
** Login   <homes_d@epitech.net>
** 
** Started on  Thu Jun  4 19:59:44 2015 David HOMES
** Last update Sun Jun  7 17:05:37 2015 David HOMES
*/

#include "main.h"

int		filter_lsd(int color)
{
  static int	count = 0;
  static int	i = 0;
  int		r;
  int		g;
  int		b;
  double	moy;

  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  moy = (r * 0.5 + g * 0.6 + b * 0.3);
  if (color == BACKGROUND && ++count % WIN_X == 0)
    ++i;
  else if (color != BACKGROUND && color == BLACK)
    {
      b = (101 * ++i) % 255;
      g = (128 * ++i) % 255;
      r = (162 * ++i) % 255;
      return (get_color(b, g, r));
    }
  b = (color == BACKGROUND ? (i * 101) % 255 : ((int)moy * 101) % 255);
  g = (color == BACKGROUND ? (i * 128) % 255 : ((int)moy * 128) % 255);
  r = (color == BACKGROUND ? (i * 162) % 255 : ((int)moy * 162) % 255);
  return (get_color(b, g, r));
}

int		filter_hope(int color)
{
  static int	count = 0;
  int		r;
  int		g;
  int		b;

  ++count;
  if (count == WIN_X * WIN_Y)
    count = 0;
  if ((count < (20 * WIN_X) || count > ((WIN_Y - 60) * WIN_X)) ||
      (count % WIN_X < 20 || count % WIN_X > WIN_X - 20))
    return (0xFBE4A7);
  b = (color >> 0) & 0xFF;
  g = (color >> 8) & 0x00FF;
  r = (color >> 16) & 0x0000FF;
  if (color == BACKGROUND)
    return (0x7BA4AE);
  if (color == BLACK)
    return (0x00334C);
  ((b < 300 && g < 300 && r < 300) ? color = 0xFBE4A7 : 0);
  ((b < 150 && g < 150 && r < 150) ? color = 0x7BA4AE : 0);
  ((b < 100 && g < 100 && r < 100) ? color = 0xD61A21 : 0);
  ((b < 50 && g < 50 && r < 50) ? color = 0x00334C : 0);
  return (color);
}

int		filter_pixel(int color)
{
  static int	count = 0;
  static int	save = -1;
  static int	i = 0;

  if (save == -1)
    save = color;
  ++count;
  if (count == WIN_X)
    {
      count = 0;
      ++i;
    }
  if (i % 40 == 0 || count % 40 == 1)
    {
      save = color;
      return (BLACK);
    }
  return (save);
}
