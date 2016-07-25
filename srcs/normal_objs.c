/*
** normal_objs.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Wed May 27 22:20:09 2015 Sébastien Rigolat
** Last update Sat Jun  6 20:58:17 2015 Sébastien Rigolat
*/

#include "main.h"

t_vect3f	normale_plan(t_elem *elem, t_vect3f P)
{
  P.x = 0;
  P.y = 0;
  P.z = 100 - elem->pos.z;
  return (P);
}

t_vect3f	normale_cylindre(t_elem *elem, t_vect3f P)
{
  P.x = P.x - elem->pos.x;
  P.y = P.y - elem->pos.y;
  P.z = 0;
  return (P);
}

t_vect3f	normale_cone(t_elem *elem, t_vect3f P)
{
  double	tang;

  tang = tan(elem->R * (M_PI / 180));
  if (fabs(tang) <= 0.0001)
    tang = 1;
  tang = -pow(tang, 2);
  P.x = P.x - elem->pos.x;
  P.y = P.y - elem->pos.y;
  P.z = (P.z - elem->pos.z) / tang;
  return (P);
}

t_vect3f	normale_sphere(t_elem *elem, t_vect3f P)
{
  P.x = P.x - elem->pos.x;
  P.y = P.y - elem->pos.y;
  P.z = P.z - elem->pos.z;
  return (P);
}

t_vect3f	getNormale_N(t_elem *elem, t_vect3f P)
{
  if (elem->ID == E_CONE)
    return (normale_cone(elem, P));
  else if (elem->ID == E_CYLINDRE)
    return (normale_cylindre(elem, P));
  else if (elem->ID == E_PLAN)
    return (normale_plan(elem, P));
  else if (elem->ID == E_SPHERE)
    return (normale_sphere(elem, P));
  return (P);
}
