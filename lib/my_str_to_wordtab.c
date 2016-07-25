/*
** my_str_to_wordtab.c for my_str_to_wordtab in /home/rigola_s/rendu/42SH
**
** Made by sebastien rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Tue Apr 22 16:18:27 2014 sebastien rigolat
** Last update Tue May 19 15:45:08 2015 Sébastien Rigolat
*/

#include "main.h"

int		size_tab(char **tab)
{
  int		i;

  i = 0;
  if (!tab)
    return (0);
  while (tab[i])
    ++i;
  return (i);
}

int		get_length(char *str, char separator)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] != separator && str[i] >= 32)
	{
	  while (str[i] != separator && str[i] >= 32)
	    i++;
	  count++;
	}
      else
	i++;
    }
  return (count);
}

int		size_word(char *str, int i)
{
  int		count;

  count = 0;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] < 127)
	{
	  while (str[i] >= 32 && str[i] < 127)
	    {
	      i++;
	      count++;
	    }
	  return (count);
	}
      else
	i++;
    }
  return (count);
}

char		**my_str_to_wordtab(char *str, char separator)
{
  char		**tab;
  int		y;
  int		x;
  int		i;

  y = 0;
  i = 0;
  if (!(tab = malloc((get_length(str, separator) + 1) * sizeof(char *))))
    return (NULL);
  while (str[i])
    {
      if (str[i] != separator && str[i] >= 32)
	{
	  if (!(tab[y] = malloc((size_word(str, i) + 1) * sizeof(char))))
	    return (NULL);
	  x = 0;
	  while (str[i] != separator && str[i] >= 32)
	    tab[y][x++] = str[i++];
	  tab[y++][x] = '\0';
	}
      else
	i++;
    }
  tab[y] = NULL;
  return (tab);
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  if (!tab)
    return;
  while (tab[i])
    free(tab[i++]);
}
