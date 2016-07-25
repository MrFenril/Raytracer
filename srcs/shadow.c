/*
** shadow.c for shadow in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu May 28 18:40:32 2015 Sébastien Rigolat
** Last update Sun Jun  7 23:10:09 2015 valentin michel
*/

#include "main.h"

int		draw_shadow(int nb_spot)
{
  if (nb_spot == 0)
    return (BLACK);
  return (BLACK / nb_spot);
}

double		calc_delta(t_vect3f *P, t_vect3f *L, t_elem *tmp)
{
  if (tmp->ID == E_SPHERE)
    return (delta_sphere(*P, *L, tmp));
  else if (tmp->ID == E_CYLINDRE)
    return (delta_cylindre(*P, *L, tmp));
  else if (tmp->ID == E_CONE)
    return (delta_cone(*P, *L, tmp));
  return (inter_plan(*P, L->z));
}

int		add_shadow(t_vect3f *P, t_vect3f *L,
			   t_elem *elem, t_elem *current)
{
  t_elem	*tmp;
  double	k;

  tmp = elem;
  while (tmp)
    {
      if (tmp != current && (k = calc_delta(P, L, tmp)) > 0.0001 && k < 1.0)
	return (1);
      tmp = tmp->next;
    }
  return (0);
}
