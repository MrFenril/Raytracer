/*
** new_get_file.c for rtracer in /home/rigola_s/TMP/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Fri Jun  5 20:31:47 2015 Sébastien Rigolat
** Last update Sun Jun  7 23:03:26 2015 valentin michel
*/

#include "main.h"

void		set_item_ID(t_elem *elem, char *str)
{
  int		i;
  char		*item[6];

  i = 0;
  item[0] = PLAN;
  item[1] = SPHERE;
  item[2] = CONE;
  item[3] = CYLINDRE;
  item[4] = SPOT;
  item[5] = NULL;
  while (item[i])
    {
      if (!my_strcmp(str, item[i]))
	{
	  elem->ID = i;
	  return;
	}
      ++i;
    }
}

int		set_other_items(t_elem **list, char *str, int fd, int i)
{
  static int	(*f_ptr[3])(t_elem **, char *, int) =
    {
      set_plan,
      set_sphere,
      set_other
    };

  if (i == 3)
    i = 2;
  if (!f_ptr[i](list, str, fd))
    return (0);
  return (1);
}

int		catch_known_item(t_elem **list, char *str, int fd, t_mlx *win)
{
  char		*items[7];
  int		i;

  items[0] = EYE;
  items[1] = SPOT;
  items[2] = PLAN;
  items[3] = SPHERE;
  items[4] = CONE;
  items[5] = CYLINDRE;
  items[6] = NULL;
  i = 0;
  while (items[i])
    {
      if (!my_strcmp(items[i], str) && i == 0)
	return (set_eye(win, str, fd));
      else if (!my_strcmp(items[i], str) && i == 1)
	return (set_spot(&win->spot, str, fd));
      else if (!my_strcmp(items[i], str) && i > 1)
	return (set_other_items(list, str, fd, i - 2));
      ++i;
    }
  fprintf(stderr, "\e[1;31mUnknown item : [%s].\n\e[0;m", str);
  return (0);
}

t_elem		*get_file(char *path, t_mlx *win)
{
  char		*str;
  t_elem	*list;
  int		fd;

  list = NULL;
  if ((fd = open(path, O_RDONLY)) == -1)
    {
      fprintf(stderr, "\e[1;31mCan't open the file.\n\e[0;m");
      return (NULL);
    }
  while ((str = get_next_line(fd)))
    catch_known_item(&list, str, fd, win);
  if (!list)
    {
      fprintf(stderr, "\e[1;31mNo items to create.\n\e[0;m");
      return (NULL);
    }
  return (list);
}
