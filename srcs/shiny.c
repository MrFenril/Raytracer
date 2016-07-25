/*
** shiny.c for  in /home/michel_v/MUL_2014_rtracer
**
** Made by valentin michel
** Login   <michel_v@epitech.net>
**
** Started on  Mon Jun  1 13:12:47 2015 valentin michel
** Last update Sun Jun  7 23:04:28 2015 valentin michel
*/

#include "main.h"

t_vect3f	init_pos_t_vect(t_vect3f *L, t_elem *tmp,
				t_vect3f P, t_elem *elem)
{
  t_vect3f	N;

  (*L).x = tmp->pos.x - P.x;
  (*L).y = tmp->pos.y - P.y;
  (*L).z = tmp->pos.z - P.z;
  N = getNormale_N(elem, P);
  return (N);
}

int		get_shining_color(t_elem *tmp, t_elem *elem,
				  int color, double a)
{
  return (get_color(a * (((color & 0xFF) * (1 - elem->b))
			 + ((tmp->color & 0xFF) * elem->b)),
		    a * ((((color >> 8) & 0xFF) * (1 - elem->b))
			 + (((tmp->color >> 8) & 0xFF)
			    * elem->b)),
		    a * ((((color >> 16) & 0xFF) * (1 - elem->b))
			 + (((tmp->color >> 16) & 0xFF)
			    * elem->b))));
}
