/*
** my_strcpy.c for strcpy in /home/rigola_s/rendu/CPE_2014_bsq/lib
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:37:07 2015 Sébastien Rigolat
** Last update Mon Jan  5 17:38:13 2015 Sébastien Rigolat
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = '\0';
  return (dest);
}
