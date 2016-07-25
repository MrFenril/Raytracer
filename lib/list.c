/*
** list.c for list in /home/rigola_s/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu Jan 29 13:12:22 2015 Sébastien Rigolat
** Last update Sat Jun  6 21:05:46 2015 Sébastien Rigolat
*/

#include "main.h"

int		list_size(t_elem **list)
{
  t_elem	*tmp;
  int		i;

  if (!(*list))
    return (0);
  i = 0;
  tmp = *list;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      ++i;
    }
  return (i);
}

int		free_node(t_elem **elem)
{
  t_elem	*tmp;

  if (list_size(elem) == 1)
    {
      free(*elem);
      *elem = NULL;
      return (0);
    }
  tmp = *elem;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
  return (0);
}

t_elem		*append_list(t_elem **list)
{
  t_elem	*elem;
  t_elem	*tmp;

  elem = NULL;
  if (!(*list))
    return (create_list(list));
  if (!(elem = malloc(sizeof(t_elem))))
    {
      my_putstr("Allocation error.\n", 2);
      return (NULL);
    }
  init_objs(&elem);
  tmp = *list;
  while (tmp->next != NULL)
    tmp = tmp->next;
  elem->next = NULL;
  tmp->next = elem;
  tmp = elem;
  return (tmp);
}

t_elem		*create_list(t_elem **list)
{
  t_elem	*elem;

  elem = NULL;
  if (!(elem = malloc(sizeof(t_elem)))
      || !(*list = malloc(sizeof(t_elem))))
    {
      my_putstr("Allocation error.\n", 2);
      return (NULL);
    }
  init_objs(&elem);
  elem->next = NULL;
  (*list) = elem;
  (*list)->next = NULL;
  return (elem);
}
