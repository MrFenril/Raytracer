/*
** get_next_line.c for get_next_line in /home/rigola_s/rendu/CPE_2014_get_next_line
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Sun Nov 23 12:28:08 2014 Sébastien Rigolat
** Last update Tue Jan  6 16:34:23 2015 Sébastien Rigolat
*/

#include "main.h"

char		*my_catdup(char *dest, char *src, int len)
{
  char		*newdest;
  int		i;
  int		end;

  i = 0;
  end = my_strlen(dest);
  if (!(newdest = malloc(sizeof(char *) * end + (len + 1))))
    return (NULL);
  newdest = my_strcpy(newdest, dest);
  free(dest);
  while (src[i])
    {
      newdest[end + i] = src[i];
      ++i;
    }
  newdest[end + i] = '\0';
  return (newdest);
}

char		*grab_line(char *buffer, char *save)
{
  int		i;
  char		*str;
  char		*tmp;

  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == '\n')
	{
	  buffer[i] = '\0';
	  str = my_strdup(buffer, 0);
	  tmp = my_strdup(&buffer[i + 1], 0);
	  save = my_strcpy(save, tmp);
	  free(tmp);
	  free(buffer);
	  return (str);
	}
      ++i;
    }
  return (NULL);
}

char		*get_next_line(int fd)
{
  static char	buffer[SIZEMAX + 1];
  char		*str;
  char		*tmp;
  int		size;

  tmp = my_strdup(buffer, 0);
  while (!(str = grab_line(tmp, buffer)))
    {
      if ((size = read(fd, buffer, SIZEMAX)) <= 0)
	{
	  free(tmp);
	  return (NULL);
	}
      buffer[size] = '\0';
      tmp = my_catdup(tmp, buffer, my_strlen(buffer));
    }
  if (str[0] == 0 && size != 0 && my_strlen(buffer) == 0)
    {
      free(str);
      return (NULL);
    }
  return (str);
}
