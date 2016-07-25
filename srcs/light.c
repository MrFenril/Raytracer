/*
** light.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue May 26 13:48:42 2015 Sébastien Rigolat
** Last update Sun Jun  7 22:58:22 2015 valentin michel
*/

#include "main.h"

t_vect3f	calc_vision(t_vect3f eye, t_vect3f V_eye, double k)
{
  t_vect3f	P;

  P.x = eye.x + (k * V_eye.x);
  P.y = eye.y + (k * V_eye.y);
  P.z = eye.z + (k * V_eye.z);
  return (P);
}

double		calc_cosa(t_vect3f N, t_vect3f L, t_elem *spot, t_elem *elem)
{
  calc_rotate(&N, elem->rot, 0);
  my_normalize(&N);
  my_normalize(&L);
  return ((L.x * N.x) + (L.y * N.y) + (L.z * N.z) * spot->i);
}

int		add_light(t_mlx *win, t_elem *elem, t_elem *first, int color)
{
  int	       	*col;
  double	a;
  t_vect	v;
  t_elem	*tmp;

  if (!win->spot)
    return (elem->color);
  tmp = win->spot;
  if (!(col = malloc(sizeof(int) * list_size(&tmp))))
    return (-1);
  v.P = calc_vision(win->eye, win->V_eye, elem->k);
  while (tmp)
    {
      color = elem->color;
      a = calc_cosa(v.N = init_pos_t_vect(&v.L,
					  tmp, v.P, elem), v.L, tmp, elem);
      if (add_shadow(&v.P, &v.L, first, elem))
	color = draw_shadow(list_size(&tmp));
      else
	color = (a <= 0.001 ? BLACK
		 : get_shining_color(tmp, elem, color, a));
      fill_color(color, col, list_size(&win->spot));
      tmp = tmp->next;
    }
  return (coloring(col, list_size(&win->spot)));
}
