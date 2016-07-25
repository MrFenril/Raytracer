/*
** get_item.c for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Thu May  7 01:37:52 2015 Sébastien Rigolat
** Last update Sun Jun  7 12:24:23 2015 Sébastien Rigolat
*/

#include "main.h"

int		item_spec(t_elem *elem, char **tab, int i)
{
  static int	(*f_ptr[6])(t_elem *, char **tab) =
    {
      item_coord,
      item_ray,
      item_color,
      item_effect,
      item_intensity,
      item_rotation
    };

  if (!f_ptr[i](elem, tab))
    return (0);
  return (1);
}

int		which_carac(t_elem *elem, char **tab)
{
  int		i;
  char		*carac[6];
  int		tab_len;

  i = 0;
  carac[0] = ORIGIN;
  carac[1] = RAY;
  carac[2] = COLOR;
  carac[3] = EFFECT;
  carac[4] = INTENSITY;
  carac[5] = ROTATION;
  carac[6] = NULL;
  if (!(tab_len = size_tab(tab)))
    return (my_putstr("\e[1;31mNo caracteristic to get.\n\e[0;m", 2));
  while (carac[i])
    if (!my_strcmp(carac[i], tab[0]))
      return (item_spec(elem, tab, i++));
    else
      ++i;
  return (1);
}

int		get_item_carac(t_elem *list
			       , const char **carac
			       , int fd)
{
  char		**tab;
  char		*str;

  while ((str = get_next_line(fd)) && my_strcmp(NEXT, str))
    {
      if ((tab = my_str_to_wordtab(str, ' '))
	  && check_carac(carac, tab[0]))
	if (!which_carac(list, tab))
	  {
	    free_tools(str, tab);
	    return (0);
	  }
      free_tools(str, tab);
    }
  if (str)
    free(str);
  return (1);
}
