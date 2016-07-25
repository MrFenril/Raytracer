/*
** draw_objs.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue May 26 00:28:27 2015 Sébastien Rigolat
** Last update Sun Jun  7 22:59:16 2015 valentin michel
*/

#include "main.h"

t_elem		*get_nearest_inter(t_elem *elem)
{
  t_elem	*save;
  t_elem	*tmp;
  double	tmp_k;

  save = elem;
  tmp = elem;
  tmp_k = elem->k;
  while (tmp)
    {
      if (tmp->k < tmp_k)
	{
	  save = tmp;
	  tmp_k = tmp->k;
	}
      tmp = tmp->next;
    }
  return (save);
}

int		draw_objs(t_mlx *win, t_elem *elem)
{
  t_elem	*nearest;

  nearest = get_nearest_inter(elem);
  if (nearest->k == FAR)
    return (BACKGROUND);
  return (add_light(win, nearest, elem, 0));
}
