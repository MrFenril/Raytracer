/*
** main.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed May  6 16:43:54 2015 Sébastien Rigolat
** Last update Wed Mar 30 18:51:13 2016 Rigolat Sébastien
*/

#include "main.h"

void		calc_items(t_mlx *win, t_elem **elem)
{
  t_elem	*tmp;
  static void	(*f_ptr[4])(t_mlx , t_elem **) =
    {
      calc_plan,
      calc_sphere,
      calc_cone,
      calc_cylindre,
    };

  tmp = *elem;
  while (tmp != NULL)
    {
      f_ptr[tmp->ID](*win, &tmp);
      tmp = tmp->next;
    }
}

int		fill_img(t_mlx *win, t_elem *elem)
{
  int		y;
  int		x;

  y = 0;
  while (y < WIN_Y)
    {
      x = 0;
      while (x < WIN_X)
  	{
	  win->eye_t.x = 100;
	  win->eye_t.y = ((WIN_X / 2) - x);
	  win->eye_t.z = ((WIN_Y / 2) - y);
	  win->V_eye.x = (win->eye_t.x - win->eye.x);
	  win->V_eye.y = (win->eye_t.y - win->eye.y);
	  win->V_eye.z = (win->eye_t.z - win->eye.z);
  	  calc_items(win, &elem);
  	  ppti(win, x, y, draw_objs(win, elem));
  	  ++x;
  	}
      gere_expose(win);
      ++y;
    }
  return (1);
}

int		init_win(t_mlx *win)
{
  win->eye.x = 0;
  win->eye.y = 0;
  win->eye.z = 0;
  win->eye_rot.x = 0;
  win->eye_rot.y = 0;
  win->eye_rot.z = 0;
  win->spot = NULL;
  if (!(win->mlx = mlx_init())
      || !(win->win = mlx_new_window(win->mlx, WIN_X, WIN_Y, "rt"))
      || !(win->img = mlx_new_image(win->mlx, WIN_X, WIN_Y))
      || !(win->data =
	   mlx_get_data_addr(win->img, &win->bpp,
			     &win->sizeline, &win->endian)))
    {
      my_putstr("\e[1;31mMlx error->\n\e[0;m", 2);
      return (0);
    }
  if ((win->tmp = malloc(sizeof(char) * (WIN_X * WIN_Y * 4))) == NULL)
    return (my_putstr(MALLOC_E, 2));
  return (1);
}

int		main(int ac, char **av)
{
  t_mlx		win;
  t_elem	*elem;

  if (ac < 2)
    {
      if (!init_win(&win)
	  || !(elem = get_file("conf_files/with_ligth", &win)))
	return (-1);
    }
  else if (ac == 2)
    {
      if (!init_win(&win)
	  || !(elem = get_file(av[1], &win)))
	return (-1);
    }
  fill_img_with_aa(&win, elem, -1, -1);
  win.tmp = memcpy(win.tmp, win.data, (WIN_X * WIN_Y * 4));
  mlx_key_hook(win.win, gere_key, &win);
  mlx_expose_hook(win.win, gere_expose, NULL);
  mlx_loop(win.mlx);
  return (0);
}
