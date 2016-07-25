/*
** intersection.c for rtv1 in /home/rigola_s/test/test_rtv1/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue Feb 10 11:18:39 2015 Sébastien Rigolat
** Last update Sat Jun  6 20:51:31 2015 Sébastien Rigolat
*/

#include "main.h"

double		inter_plan(t_vect3f V, double z)
{
  double	k;

  if (V.z == 0.00001)
    return (FAR);
  k = - (z / V.z);
  if (k > 0.00001)
    return (k);
  return (FAR);
}

double		inter_objs(t_delta delta)
{
  double	k1;
  double	k2;

  if (delta.delta <= 0.00001)
    return (FAR);
  delta.a *= 2;
  delta.b = -delta.b;
  delta.delta = sqrt(delta.delta);
  k1 = (delta.b - delta.delta) / delta.a;
  k2 = (delta.b + delta.delta) / delta.a;
  if (k1 < 0.00001 && k2 < 0.00001)
    return (FAR);
  return (((k1 < 0.00001 )? k2 : k1));
}
