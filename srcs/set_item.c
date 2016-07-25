/*
** new_set_item.c for set_item in /home/rigola_s/TMP/MUL_2014_rtracer/srcs
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Fri Jun  5 21:40:23 2015 Sébastien Rigolat
** Last update Sun Jun  7 13:55:22 2015 Sébastien Rigolat
*/

#include "main.h"

int		set_spot(t_elem **spot, char *str, int fd)
{
  const char	*carac[4];
  t_elem	*tmp;

  carac[0] = INTENSITY;
  carac[1] = COLOR;
  carac[2] = ORIGIN;
  carac[3] = NULL;
  if (!(tmp = append_list(spot)))
    return (my_putstr(MALLOC_E, 2));
  set_item_ID(tmp, str);
  if (!get_item_carac(tmp, carac, fd))
    {
      my_putstr("\e[1;31mCaracteristic missing or invalid, ", 2);
      fprintf(stderr, "item [%s] is gonna be ignored.\n", str);
      my_putstr("-------------------------------\n\e[0;m", 2);
      free(str);
      while ((str = get_next_line(fd)) && my_strcmp(NEXT, str))
	free(str);
      free_node(spot);
    }
  if (str)
    free(str);
  return (1);
}

int		set_eye(t_mlx *win, char *str, int fd)
{
  char		**tab;

  free(str);
  while	((str = get_next_line(fd)) && my_strcmp(NEXT, str))
    {
      if ((tab = my_str_to_wordtab(str, ' ')) && size_tab(tab) == 4
	   && !my_strcmp(tab[0], ORIGIN))
	get_eye_carac(&win->eye, tab);
      else if ((tab = my_str_to_wordtab(str, ' ')) && size_tab(tab) == 4
	       && !my_strcmp(tab[0], ROTATION))
	get_eye_carac(&win->eye_rot, tab);
      else
	fprintf(stderr, "Useless caracteristic : [%s] for EYE\n", str);
      free_tools(str, tab);
    }
  if (str)
    free(str);
  return (1);
}

int		set_plan(t_elem **item, char *str, int fd)
{
  const char	*carac[5];
  t_elem	*tmp;

  carac[0] = ORIGIN;
  carac[1] = ROTATION;
  carac[2] = EFFECT;
  carac[3] = COLOR;
  carac[4] = NULL;
  if (!(tmp = append_list(item)))
    return (my_putstr(MALLOC_E, 2));
  set_item_ID(tmp, str);
  if (!get_item_carac(tmp, carac, fd))
    {
      my_putstr("\e[1;31mCaracteristic missing or invalid, ", 2);
      fprintf(stderr, "item [%s] is gonna be ignored.\n", str);
      my_putstr("-------------------------------\n\e[0;m", 2);
      free(str);
      while ((str = get_next_line(fd)) && my_strcmp(NEXT, str))
	free(str);
      if (str)
	free(str);
      free_node(item);
      return (0);
    }
  return (1);
}

int		set_sphere(t_elem **item, char *str, int fd)
{
  const char	*carac[5];
  t_elem	*tmp;

  carac[0] = ORIGIN;
  carac[1] = RAY;
  carac[2] = EFFECT;
  carac[3] = COLOR;
  carac[4] = NULL;
  if (!(tmp = append_list(item)))
    return (my_putstr(MALLOC_E, 2));
  set_item_ID(tmp, str);
  if (!get_item_carac(tmp, carac, fd))
    {
      my_putstr("\e[1;31mCaracteristic missing or invalid, ", 2);
      fprintf(stderr, "item [%s] is gonna be ignored.\n", str);
      my_putstr("-------------------------------\n\e[0;m", 2);
      free(str);
      while ((str = get_next_line(fd)) && my_strcmp(NEXT, str))
	free(str);
      if (str)
	free(str);
      free_node(item);
      return (0);
    }
  return (1);
}

int		set_other(t_elem **item, char *str, int fd)
{
  const char	*carac[5];
  t_elem	*tmp;

  carac[0] = ORIGIN;
  carac[1] = RAY;
  carac[2] = EFFECT;
  carac[3] = COLOR;
  carac[4] = NULL;
  if (!(tmp = append_list(item)))
    return (my_putstr(MALLOC_E, 2));
  set_item_ID(tmp, str);
  if (!get_item_carac(tmp, carac, fd))
    {
      my_putstr("\e[1;31mCaracteristic missing or invalid, ", 2);
      fprintf(stderr, "item [%s] is gonna be ignored.\n", str);
      my_putstr("+-------------------------------+\n\e[0;m", 2);
      free(str);
      while ((str = get_next_line(fd)) && my_strcmp(NEXT, str))
	free(str);
      if (str)
	free(str);
      free_node(item);
      return (0);
    }
  return (1);
}
