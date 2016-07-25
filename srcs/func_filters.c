/*
** func_filters.c for rtracer in /home/homes_d/MUL_2014_rtracer
**
** Made by David HOMES
** Login   <homes_d@epitech.net>
**
** Started on  Sat Jun  6 00:16:48 2015 David HOMES
** Last update Sun Jun  7 23:02:21 2015 David HOMES
*/

#include "main.h"

int		is_filter(int key)
{
  int	i;

  i = -1;
  (key == XK_twosuperior ? i = 0 : 0);
  (key == XK_ampersand ? i = 1 : 0);
  (key == XK_eacute ? i = 2 : 0);
  (key == XK_quotedbl ? i = 3 : 0);
  (key == XK_apostrophe ? i = 4 : 0);
  (key == XK_parenleft ? i = 5 : 0);
  (key == XK_minus ? i = 6 : 0);
  (key == XK_egrave ? i = 7 : 0);
  (key == XK_underscore ? i = 8 : 0);
  (key == XK_ccedilla ? i = 9 : 0);
  (key == XK_agrave ? i = 10 : 0);
  return (i);
}

int	datacolor(char *data, int x, int y)
{
  int	color;

  color = get_color(data[(x * 4) + (y * 4 * WIN_X) + 0] & 0xFF,
		    data[(x * 4) + (y * 4 * WIN_X) + 1] & 0xFF,
		    data[(x * 4) + (y * 4 * WIN_X) + 2] & 0xFF);
  return (color);
}

int	set_filter(t_mlx *win, int filter, int (*fptr[10])(int))
{
  int	y;
  int	x;
  int	color;

  y = 0;
  while (y < WIN_Y)
    {
      x = 0;
      while (x < WIN_X)
	{
	  if (filter == 0 || filter == 10)
	    color = datacolor(win->tmp, x, y);
	  else
	    color = fptr[filter](datacolor(win->tmp, x, y));
	  ppti(win, x, y, color);
	  ++x;
	}
      ++y;
    }
  gere_expose(win);
  return (0);
}

int		func_filters(int filter, t_mlx *win)
{
  static int	old = -1;
  static int	(*fptr[10])(int color) =
    {
      NULL,
      &filter_grey,
      &filter_neg,
      &filter_sepia,
      &filter_water,
      &filter_canal,
      &filter_hope,
      &filter_pixel,
      &filter_lsd,
      &filter_noise
    };

  if (filter != old)
    set_filter(win, old = filter, fptr);
  else
    set_filter(win, old = 0, fptr);
  return (0);
}
