/*
** save.c for  in /home/michel_v/MUL_2014_rtracer/bonus/save
**
** Made by valentin michel
** Login   <michel_v@epitech.net>
**
** Started on  Thu Jun  4 18:03:19 2015 valentin michel
** Last update Sun Jun  7 16:26:42 2015 valentin michel
*/

#include "main.h"

int		save_ppm(char *data)
{
  int		x;
  int		y;
  FILE		*save;

  if ((save = fopen("img.ppm", "w+")) == NULL)
    return (my_fdprintf(2, "fopen failed.\n"));
  fprintf(save, "P6\n%d\n%d\n255\n", WIN_X, WIN_Y);
  y = 0;
  while (y < WIN_Y)
    {
      x = 0;
      while (x < WIN_X)
	{
	  fprintf(save, "%c%c%c", data[((x * 4) + (y * 4 * WIN_X)) + 2],
		  data[((x * 4) + (y * 4 * WIN_X)) + 1],
		  data[(x * 4) + (y * 4 * WIN_X)]);
	  ++x;
	}
      ++y;
    }
  return (fclose(save));
}

int		save_img(t_mlx *win)
{
  char		*data;

  printf("%X -- %d", WIN_X, WIN_X);
  if (!(data = mlx_get_data_addr(win->img, &win->bpp,
				 &win->sizeline, &win->endian))
      || save_ppm(data) == -1)
    return (-1);
  return (0);
}
