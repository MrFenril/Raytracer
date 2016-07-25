##
## Makefile for bsq in /home/rigola_s/rendu/CPE_2014_bsq/lib
## 
## Made by Sébastien Rigolat
## Login   <rigola_s@epitech.net>
## 
## Started on  Mon Jan  5 17:18:20 2015 Sébastien Rigolat
## Last update Wed May 27 13:19:29 2015 jordan faucher
##

CC	=	cc

RM	=	rm -f

NAME	=	libmy.a

INCLUDE = 	-I../include

CFLAGS	+=	$(INCLUDE)
CFLAGS	+=	-W
CFLAGS	+=	-Wall
CFLAGS	+=	-Wextra -g

SRCS	=	get_next_line.c		\
		my_putchar.c		\
		my_putnbr.c		\
		my_strncpy.c		\
		my_strncat.c		\
		my_putstr.c		\
		my_puterror.c		\
		my_strdup.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_printf.c		\
		my_str_to_wordtab.c	\
		flags.c			\
		list.c			\
		my_strcmp.c

OBJS	=	$(SRCS:.c=.o)

%.o:		%.c
	@echo "cc -c -o $@ $^"
	@$(CC) -c -o $@ $^ $(CFLAGS)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

all:	$(NAME)

clean:
	@$(RM) $(OBJS)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all
