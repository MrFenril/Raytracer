/*
** list.h for list in /home/rigola_s/include
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Fri Jan 16 11:47:51 2015 Sébastien Rigolat
** Last update Sat Jun  6 20:39:51 2015 Sébastien Rigolat
*/

#ifndef LIST_H_
# define LIST_H_

# include "main.h"

typedef struct	s_elem
{
  int		ID;
  t_vect3f	pos;
  t_vect3f	rot;
  double	R;
  double	k;
  double	b;
  double	t;
  double	r;
  double	i;
  int		color;
  struct s_elem	*next;
}		t_elem;

int		free_node(t_elem **elem);
int		list_size(t_elem **list);
t_elem		*create_list(t_elem **list);
t_elem		*append_list(t_elem **list);

#endif /* !LIST_H_ */
