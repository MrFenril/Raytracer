/*
** client.h for rtracer in /Users/jfaucher/Rendu/Epitech/Igraph/MUL_2014_rtracer/cluster/client
**
** Made by jordan faucher
** Login   <jfaucher@epitech.net>
**
** Started on  Wed May 27 13:51:24 2015 jordan faucher
** Last update Wed May 27 15:33:35 2015 jordan faucher
*/

#ifndef CLIENT_H_
# define CLIENT_H_

#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "main.h"
#define BUF_SIZE 4096

int     init_connection(char *ip_adress, char *port);
int     end_connection(int sock);
int     my_select(int sock, char *pseudo);
int     read_serv(int sokc, char *buff);
int     write_server(int sock, char *buff);

#endif /* !CLIENT_H_ */
