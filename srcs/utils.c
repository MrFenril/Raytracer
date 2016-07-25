/*
** utils.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu May  7 01:14:51 2015 Sébastien Rigolat
** Last update Sun Jun  7 13:28:43 2015 valentin michel
*/

#include "main.h"

int		ppti(t_mlx *win, int x, int y, int color)
{
  if (win->data != NULL && win->bpp == 32)
    {
      win->data[(x * 4) + (y * 4 * WIN_X)] = color & 0xFF;
      win->data[(x * 4) + (y * 4 * WIN_X) + 1] = (color >> 8) & 0xFF;
      win->data[(x * 4) + (y * 4 * WIN_X) + 2] = (color >> 16) & 0xFF;
      win->data[(x * 4) + (y * 4 * WIN_X) + 3] = (color >> 24) & 0xFF;
      return (0);
    }
  fprintf(stderr, "\e[1;31mData : NULL or invalid bpp.\n");
  return (0);
}

int		gere_expose(t_mlx *win)
{
  mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
  return (0);
}

int		gere_key(int key, t_mlx __attribute__((unused))*win)
{
  int		i;

  if (key == XK_Escape)
    exit(EXIT_SUCCESS);
  else if ((i = is_filter(key)) >= 0)
    func_filters(i, win);
  else if (key == 's')
    save_img(win);
  return (0);
}

void		free_tools(char *str, char **tab)
{
  if (tab)
    free_tab(tab);
  if (str)
    free(str);
}
