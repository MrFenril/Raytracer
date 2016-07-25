/*
** anti_aliasing.c for rtracer in /home/floch_a/test/tmp/MUL_2014_rtracer
**
** Made by adrien floch
** Login   <floch_a@epitech.net>
**
** Started on  Wed May 27 22:54:47 2015 adrien floch
** Last update Sun Jun  7 22:42:46 2015 adrien floch
*/

#include "main.h"

int		real_color(int *anti_a)
{
  int		nb;
  int		col_r;
  int		col_g;
  int		col_b;

  col_r = 0;
  col_g = 0;
  col_b = 0;
  nb = 0;
  while (nb < ANTI_A)
    {
      col_r = col_r + (anti_a[nb] & 0xFF);
      col_g = col_g + ((anti_a[nb] >> 8) & 0xFF);
      col_b = col_b + ((anti_a[nb] >> 16) & 0xFF);
      nb++;
    }
  col_r = col_r / ANTI_A;
  col_g = col_g / ANTI_A;
  col_b = col_b / ANTI_A;
  return (get_color(col_r, col_g, col_b));
}

void		anti_aliasing(int color, int *anti_a)
{
  static int	nb = 0;

  anti_a[nb] = color;
  nb++;
  if (nb > (ANTI_A - 1))
    nb = 0;
}

void		init_eye_aa(t_mlx *win, double x_aa, double y_aa, t_elem *elem)
{
  win->eye_t.x = 100;
  win->eye_t.y = ((WIN_X / 2) - x_aa);
  win->eye_t.z = ((WIN_Y / 2) - y_aa);
  win->V_eye.x = (win->eye_t.x - win->eye.x);
  win->V_eye.y = (win->eye_t.y - win->eye.y);
  win->V_eye.z = (win->eye_t.z - win->eye.z);
  calc_items(win, &elem);
}

void		fill_img_with_aa(t_mlx *win, t_elem *elem, int y, int x)
{
  double	y_aa;
  double	x_aa;
  int		anti_a[ANTI_A];

  while (++y < WIN_Y)
    {
      x = -1;
      while (++x < WIN_X)
	{
	  y_aa = y;
	  while (y_aa < y + 1)
	    {
	      x_aa = x;
	      while (x_aa < x + 1)
		{
		  init_eye_aa(win, x_aa, y_aa, elem);
		  anti_aliasing(draw_objs(win, elem), anti_a);
		  x_aa = x_aa + (1.0 / AA);
		}
	      y_aa = y_aa + (1.0 / AA);
	    }
	  ppti(win, x, y, real_color(anti_a));
	}
      gere_expose(win);
    }
}
