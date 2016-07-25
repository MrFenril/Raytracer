/*
** calc_delta.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu May 28 18:51:07 2015 Sébastien Rigolat
** Last update Sun Jun  7 21:03:54 2015 adrien floch
*/

#include "main.h"

void		init_vect(t_vect3f *P, t_vect3f *V, t_elem *item)
{
  if (item->ID != E_SPHERE)
    calc_rotate(V, item->rot, 0);
  translate_calc(P, item->pos, 0);
}

double		delta_sphere(t_vect3f P, t_vect3f V, t_elem *elem)
{
  t_delta	delta;

  init_vect(&P, &V, elem);
  delta.a = pow(V.x, 2) + pow(V.y, 2)
    + pow(V.z, 2);
  delta.b = 2 * ((P.x * V.x)
		 + (P.y * V.y)
		 + (P.z * V.z));
  delta.c = pow(P.x, 2)
    + pow(P.y, 2)
    + pow(P.z, 2)
    - pow(elem->R, 2);
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  return (inter_objs(delta));
}

double		delta_cylindre(t_vect3f P, t_vect3f V, t_elem *elem)
{
  t_delta	delta;

  init_vect(&P, &V, elem);
  delta.a = pow(V.x, 2) + pow(V.y, 2);
  delta.b = 2 * ((P.x * V.x)
		 + (P.y * V.y));
  delta.c = pow(P.x, 2)
    + pow(P.y, 2)
    - pow(elem->R, 2);
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  return (inter_objs(delta));
}

double		delta_cone(t_vect3f P, t_vect3f V, t_elem *elem)
{
  t_delta	delta;
  double	tang;

  init_vect(&P, &V, elem);
  tang = tan(elem->R * (M_PI / 180));
  delta.a = (pow(V.x, 2)
	     + pow(V.y, 2)
	     - pow(V.z, 2)) / tang;
  delta.b = 2 * ((P.x * V.x)
		 + (P.y * V.y)
		 - (P.z * V.z)) / tang;
  delta.c = (pow(P.x, 2)
	     + pow(P.y, 2)
	     - pow(P.z, 2)) / tang;
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  return (inter_objs(delta));
}

double		delta_plan(t_vect3f P, t_vect3f V, t_elem *elem)
{
  init_vect(&P, &V, elem);
  return (inter_plan(V, P.z));
}
