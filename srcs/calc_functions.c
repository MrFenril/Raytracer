/*
** calc_functions.c<2> for calc_function in /home/rigola_s/test/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Sun May 24 14:31:35 2015 Sébastien Rigolat
** Last update Wed Jun 10 13:20:59 2015 Sébastien Rigolat
*/

#include "main.h"

void		init_eye(t_mlx *win, t_elem *item)
{
  if (item->ID != E_SPHERE)
    calc_rotate(&win->V_eye, item->rot, 0);
  translate_calc(&win->eye, item->pos, 0);
}

void		translate_calc(t_vect3f *item, t_vect3f pos, int flag)
{
  if (flag == 1)
    {
      item->x += pos.x;
      item->y += pos.y;
      item->z += pos.z;
    }
  else
    {
      item->x += (pos.x * -1);
      item->y += (pos.y * -1);
      item->z += (pos.z * -1);
    }
}

void		my_normalize(t_vect3f *V)
{
  double	inv_normal;

  inv_normal = 1.0 / sqrt(pow(V->x, 2) + pow(V->y, 2) + pow(V->z, 2));
  V->x *= inv_normal;
  V->y *= inv_normal;
  V->z *= inv_normal;
}
