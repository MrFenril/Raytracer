/*
** get_next_line.h for get_next_line in /home/rigola_s/rendu/CPE_2014_get_next_line
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Sun Nov 23 12:27:51 2014 Sébastien Rigolat
** Last update Wed Jan 14 13:41:06 2015 Sébastien Rigolat
*/

#ifndef GNL_H_
# define GNL_H_

# include "main.h"

# define SIZEMAX 512

char		*my_catdup(char *dest, char *src, int len);
char		*grab_line(char *buffer, char *save);
char		*get_next_line(int fd);

#endif /* !GNL_H_ */
