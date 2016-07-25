/*
** color_treatment.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Sat Jun  6 23:35:38 2015 Sébastien Rigolat
** Last update Sat Jun  6 23:36:13 2015 Sébastien Rigolat
*/

#include "main.h"

int		get_color(int r, int g, int b)
{
  if (r > 255)
    r = 255;
  if (g > 255)
    g = 255;
  if (b > 255)
    b = 255;
  return ((b * (256 * 256)) + (g * 256) + r);
}

int             coloring(int *col, int i)
{
  int           nb;
  int           col_r;
  int           col_g;
  int           col_b;

  col_r = 0;
  col_g = 0;
  col_b = 0;
  nb = 0;
  while (nb < i)
    {
      col_r = col_r + (col[nb] & 0xFF);
      col_g = col_g + ((col[nb] >> 8) & 0xFF);
      col_b = col_b + ((col[nb] >> 16) & 0xFF);
      nb++;
    }
  col_r = col_r / i;
  col_g = col_g / i;
  col_b = col_b / i;
  return (get_color(col_r, col_g, col_b));
}

void		fill_color(int color, int *col, int i)
{
  static int	nb = 0;

  col[nb] = color;
  nb++;
  if (nb == i)
    nb = 0;
}
