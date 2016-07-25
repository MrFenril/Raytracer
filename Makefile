##
## Makefile for rtracer in /home/rigola_s/rendu/IGRAPH/MUL_2014_rtracer
## 
## Made by Sébastien Rigolat
## Login   <rigola_s@epitech.net>
## 
## Started on  Wed May  6 16:33:12 2015 Sébastien Rigolat
## Last update Sun Jun  7 23:14:23 2015 Sébastien Rigolat
##

CC	=	cc

RM	=	rm -f

NAME	=	rt

DIR	=	srcs/

LIB	=	-Llib/ -lmy					\
		-L/usr/lib/minilibx -lmlx 			\
		-L/usr/lib/X11 -lX11 -lXext -lm -lmy

INCLUDE	=	-Iinclude/

CFLAGS	=	$(LIB)			\
		$(INCLUDE)		\
		-W			\
		-Wall			\
		-Wextra

SRC	=	main.c			\
		get_file.c		\
		set_item.c		\
		get_item_carac.c	\
		check_carac.c		\
		item_carac.c		\
		utils.c			\
		intersection.c		\
		objs.c			\
		rotation.c		\
		calc_functions.c	\
		draw_objs.c		\
		light.c			\
		normal_objs.c		\
		anti_aliasing.c		\
		shadow.c		\
		calc_delta.c		\
		shiny.c			\
		filters_color.c		\
		filters_art.c		\
		func_filters.c		\
		color_treatment.c	\
		filters_tv.c		\
		printf_func2.c		\
		printf_func.c		\
		my_str.c		\
		my_strlen.c		\
		printf.c		\
		save.c

SRCS	=	$(addprefix $(DIR), $(SRC))
OBJS	=	$(SRCS:.c=.o)

%.o:		%.c
	@echo "cc -c -o $@ $^"
	@$(CC) -c -o $@ $^ $(CFLAGS)

$(NAME):	$(OBJS)
	@make -C lib/ --no-print-directory
	@echo ""
	@echo -e "\e[1;32m/--------------\\"
	@echo -e "    Lib DONE"
	@echo -e "\--------------/\e[0;m"
	@echo ""
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	@echo ""
	@echo -e "\e[1;32m/------------\\"
	@echo -e "    RT DONE"
	@echo -e "\------------/\e[0;m"
	@echo ""

all:	$(NAME)

clean:
	@$(RM) $(OBJS)
	@make clean -C lib/ --no-print-directory
	@echo -e "\e[1;31m| directory SRCS cleaned |\e[0;m"
	@echo -e "\e[1;31m| Lib .o cleaned |\e[0;m"
	@echo -e "\e[1;31m| server cleaned   |\e[0;m"
	@echo -e "\e[1;31m| client cleaned   |\e[0;m"

fclean:	clean
	@$(RM) $(NAME)
	@make fclean -C lib/ --no-print-directory
	@echo -e "\e[1;31m| RT erased   |\e[0;m"
	@echo -e "\e[1;31m| Lib erased |\e[0;m"
	@echo -e "\e[1;31m| server erased   |\e[0;m"
	@echo -e "\e[1;31m| client erased   |\e[0;m"

re:	fclean all

.PHONY: all clean fclean re
