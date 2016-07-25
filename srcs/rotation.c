/*
** rotation.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue May 12 14:53:17 2015 Sébastien Rigolat
** Last update Sun Jun  7 12:22:25 2015 Sébastien Rigolat
*/

#include "main.h"

int		item_rotation(t_elem *elem, char **tab)
{
  if (size_tab(tab) < 4)
    return (my_putstr("\e[1;31mNot enough parameters for rotation\n\e[0;m"
		      , 2));
  if (((elem->rot.x = atoi(tab[1])) > 360 || elem->rot.x < -360)
      || ((elem->rot.y = atoi(tab[2])) > 360 || elem->rot.y < -360)
      || ((elem->rot.z = atoi(tab[3])) > 360 || elem->rot.z < -360))
    {
      my_putstr("\e[1;31mInvalid rotation\n\e[0;m"
		, 2);
      return (0);
    }
  return (1);
}

void		rotate_z(double *x, double *y, double angle)
{
  double	tmp;

  tmp = *x;
  *x = (*x * cos(angle * (M_PI / 180))) - (*y * sin(angle * (M_PI / 180)));
  *y = (tmp * sin(angle * (M_PI / 180))) + (*y * cos(angle * (M_PI / 180)));
}

void		rotate_y(double *x, double *z, double angle)
{
  double	tmp;

  tmp = *x;
  *x = (*x * cos(angle * (M_PI / 180))) + (*z * sin(angle * (M_PI / 180)));
  *z = (tmp * sin(angle * (M_PI / 180))) + (*z * cos(angle * (M_PI / 180)));
}

void		rotate_x(double *y, double *z, double angle)
{
  double	tmp;

  tmp = *y;
  *y = (*y * cos(angle * (M_PI / 180))) - (*z * sin(angle * (M_PI / 180)));
  *z = (tmp * sin(angle * (M_PI / 180))) + (*z * cos(angle * (M_PI / 180)));
}

void		calc_rotate(t_vect3f *rot, t_vect3f angle, int flag)
{
  if (flag == 1)
    {
      rotate_x(&rot->y, &rot->z, angle.x);
      rotate_y(&rot->x, &rot->z, angle.y);
      rotate_z(&rot->x, &rot->y, angle.z);
    }
  else
    {
      rotate_x(&rot->y, &rot->z, -angle.x);
      rotate_y(&rot->x, &rot->z, -angle.y);
      rotate_z(&rot->x, &rot->y, -angle.z);
    }
}
