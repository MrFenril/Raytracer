/*
** objs.c for rtv1 in /home/rigola_s/test/test_rtv1/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue Feb 10 11:20:49 2015 Sébastien Rigolat
** Last update Sun Jun  7 19:29:03 2015 adrien floch
*/

#include "main.h"

void		init_objs(t_elem **elem)
{
  (*elem)->pos.x = 0;
  (*elem)->pos.y = 0;
  (*elem)->pos.z = 0;
  (*elem)->rot.x = 0;
  (*elem)->rot.y = 0;
  (*elem)->rot.z = 0;
  (*elem)->R = 0;
  (*elem)->color = 0;
  (*elem)->b = 0;
  (*elem)->r = 0;
  (*elem)->t = 0;
  (*elem)->i = 0;
}

void		calc_sphere(t_mlx win, t_elem **elem)
{
  t_delta	delta;

  init_eye(&win, *elem);
  delta.a = pow(win.V_eye.x, 2) + pow(win.V_eye.y, 2)
    + pow(win.V_eye.z, 2);
  delta.b = 2 * ((win.eye.x * win.V_eye.x)
		 + (win.eye.y * win.V_eye.y)
		 + (win.eye.z * win.V_eye.z));
  delta.c = pow(win.eye.x, 2)
    + pow(win.eye.y, 2)
    + pow(win.eye.z, 2)
    - pow((*elem)->R, 2);
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  (*elem)->k = inter_objs(delta);
}

void		calc_cylindre(t_mlx win, t_elem **elem)
{
  t_delta	delta;

  init_eye(&win, *elem);
  delta.a = pow(win.V_eye.x, 2) + pow(win.V_eye.y, 2);
  delta.b = 2 * ((win.eye.x * win.V_eye.x)
		 + (win.eye.y * win.V_eye.y));
  delta.c = pow(win.eye.x, 2)
   + pow(win.eye.y, 2)
    - pow((*elem)->R, 2);
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  (*elem)->k = inter_objs(delta);
}

void		calc_cone(t_mlx win, t_elem **elem)
{
  t_delta	delta;
  double	tang;

  tang = tan((*elem)->R * (M_PI / 180));
  init_eye(&win, *elem);
  delta.a = (pow(win.V_eye.x, 2)
	     + pow(win.V_eye.y, 2)
	     - pow(win.V_eye.z, 2)) / tang;
  delta.b = 2 * ((win.eye.x * win.V_eye.x)
		 + (win.eye.y * win.V_eye.y)
		 - (win.eye.z * win.V_eye.z)) / tang;
  delta.c = (pow(win.eye.x, 2)
	     + pow(win.eye.y, 2)
	     - pow(win.eye.z, 2)) / tang;
  delta.delta = pow(delta.b, 2) - (4 * (delta.a * delta.c));
  (*elem)->k = inter_objs(delta);
}

void		calc_plan(t_mlx win, t_elem **elem)
{
  init_eye(&win, *elem);
  (*elem)->k = inter_plan(win.V_eye, win.eye.z);
}
