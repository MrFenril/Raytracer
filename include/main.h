/*
** main.h for bsq in /home/rigola_s/rendu/CPE_2014_bsq/include
**
** Made by Sébastien Rigolat
** Login   <rigola_s@epitech.net>
**
** Started on  Mon Jan  5 17:08:21 2015 Sébastien Rigolat
** Last update Wed Jun 10 14:16:20 2015 jordan faucher
*/

#ifndef MAIN_H_
# define MAIN_H_

/*
** INCLUDE
*/

# include <X11/keysym.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <string.h>
# include <ctype.h>
# include "my.h"
# include "get_next_line.h"
# include "my_printf.h"
# include "objs.h"
# include "list.h"
# include "fdprintf.h"

/*
** ERROR
*/

# define MALLOC_E	"\e[1;31mAllocation error.\n\e[0;m"

/*
** OBJS
*/

# define NEXT		"//"
# define PLAN		"PLAN"
# define EYE		"EYE"
# define SPOT		"SPOT"
# define CYLINDRE	"CYLINDRE"
# define CONE		"CONE"
# define SPHERE		"SPHERE"
# define ORIGIN		"POSITION="
# define RAY		"RAY="
# define COLOR		"COLOR="
# define EFFECT		"EFFECT="
# define INTENSITY	"INTENSITY="
# define ROTATION	"ROTATION="

/*
** WINDOW DATA
*/

# define WIN_X		1920
# define WIN_Y		1080
# define FAR		10e8
# define AA		4
# define ANTI_A		16

/*
** COLOR
*/

# define TURQUOISE	0x00FFFF
# define YELLOW		0xF9F900
# define ORANGE		0xFF6600
# define BROWN		0x8A441A
# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define GREEN		0x00AA00
# define PINK		0xF228BB
# define BLUE		0x0000AA
# define RED		0xAA0000

# define BACKGROUND	WHITE

/*
** STRUCTURES / ENUM
*/

enum
  {
    E_PLAN = 0,
    E_SPHERE = 1,
    E_CONE = 2,
    E_CYLINDRE = 3,
    E_SPOT = 4,
  };

typedef struct	s_delta
{
  double	a;
  double	b;
  double	c;
  double	delta;
}		t_delta;

typedef struct	s_mlx
{
  void		*mlx;
  void		*win;
  void		*img;
  char		*data;
  char		*tmp;
  int		sizeline;
  int		bpp;
  int		endian;
  t_vect3f	eye_rot;
  t_vect3f	eye_t;
  t_vect3f	eye;
  t_vect3f	V_eye;
  t_elem	*spot;
}		t_mlx;

typedef struct	s_vect
{
  t_vect3f	P;
  t_vect3f	L;
  t_vect3f	N;
}		t_vect;

/*
** save.c
*/

int		save_img(t_mlx *win);
int		filter_canal(int color);

/*
** calc_functions.c
*/

void		my_normalize(t_vect3f *V);
void		init_eye(t_mlx *win, t_elem *item);
t_vect3f	calc_vision(t_vect3f eye, t_vect3f V_eye, double k);
void		translate_calc(t_vect3f *item, t_vect3f pos, int flag);

/*
** rotation.c
*/

int		item_rotation(t_elem *elem, char **tab);
void		rotate_z(double *x, double *y, double angle);
void		rotate_y(double *x, double *z, double angle);
void		rotate_x(double *y, double *z, double angle);
void		calc_rotate(t_vect3f *rot, t_vect3f angle, int flag);

/*
** get_file.c
*/

t_elem		*get_file(char *path, t_mlx *win);
void		set_item_ID(t_elem *elem, char *str);
int		set_other_items(t_elem **list, char *str, int fd, int i);
int		catch_known_item(t_elem **list, char *str, int fd, t_mlx *win);
t_elem		*get_file(char *path, t_mlx *win);

/*
** set_item.c
*/

int		set_spot(t_elem **spot, char *str, int fd);
int		set_eye(t_mlx *win, char *str, int fd);
int		set_plan(t_elem **item, char *str, int fd);
int		set_sphere(t_elem **item, char *str, int fd);
int		set_other(t_elem **item, char *str, int fd);

/*
** check_carac.c
*/

int		check_hexa(char *str);
int		check_carac(const char **carac, char *str);
int		get_eye_carac(t_vect3f *eye, char **tab);

/*
** get_item_carac.c
*/

int		item_spec(t_elem *elem, char **tab, int i);
int		which_carac(t_elem *elem, char **tab);
int		get_item_carac(t_elem *list
			       , const char **carac
			       , int fd);

/*
** item_carac.c
*/

int		item_coord(t_elem *elem, char **tab);
int		item_ray(t_elem *elem, char **tab);
int		item_color(t_elem *elem, char **tab);
int		item_effect(t_elem *elem, char **tab);
int		item_intensity(t_elem *elem, char **tab);

/*
** utils.c
*/

void		free_tools(char *str, char **tab);
int		gere_key(int key, t_mlx *win);
int		gere_expose(t_mlx *win);
int		ppti(t_mlx *win, int x, int y, int color);

/*
** main.c
*/

void		calc_items(t_mlx *win, t_elem **tmp);
int		fill_img(t_mlx *win, t_elem *elem);
int		init_win(t_mlx *win);
void		fill_img_with_aa(t_mlx *win, t_elem *elem, int y, int x);

/*
** objs.c
*/

void		init_objs(t_elem **elem);
void		calc_sphere(t_mlx win, t_elem **elem);
void		calc_cylindre(t_mlx win, t_elem **elem);
void		calc_cone(t_mlx win, t_elem **elem);
void		calc_plan(t_mlx win, t_elem **elem);

/*
** intersection.c
*/

double		inter_plan(t_vect3f V, double z);
double		inter_objs(t_delta delta);

/*
** draw_objs.c
*/

int		draw_objs(t_mlx *win, t_elem *elem);
t_elem		*get_nearest_inter(t_elem *elem);

/*
** light.c
*/

int		add_light(t_mlx *win, t_elem *elem, t_elem *first, int color);
int		get_color(int r, int g, int b);

/*
** color_treatment.c
*/

int		get_color(int r, int g, int b);
int             coloring(int *col, int i);
void		fill_color(int color, int *col, int i);

/*
** normale_objs.c
*/

t_vect3f	getNormale_N(t_elem *elem, t_vect3f P);
t_vect3f	normale_sphere(t_elem *elemn, t_vect3f P);
t_vect3f	normale_cone(t_elem *elem, t_vect3f P);
t_vect3f	normale_cylindre(t_elem *elem, t_vect3f P);
t_vect3f	normale_plan(t_elem *elem, t_vect3f P);

/*
** shadow.c
*/

int		draw_shadow(int nb_spot);
double		calc_delta(t_vect3f *P, t_vect3f *L, t_elem *tmp);
int		add_shadow(t_vect3f *P, t_vect3f *L,
			   t_elem *elem, t_elem *current);

/*
** calc_delta.c
*/

double		delta_sphere(t_vect3f P, t_vect3f V, t_elem *elem);
double		delta_cylindre(t_vect3f P, t_vect3f V, t_elem *elem);
double		delta_cone(t_vect3f P, t_vect3f V, t_elem *elem);

/*
** shiny.c
*/

t_vect3f	init_pos_t_vect(t_vect3f *L, t_elem *tmp,
				t_vect3f P, t_elem *elem);
int		get_shining_color(t_elem *tmp, t_elem *elem,
				  int color, double a);

/*
** func_filters.c
*/

int		is_filter(int key);
int		func_filters(int i, t_mlx *win);
int		set_filter(t_mlx *win, int filter, int (*fptr[10])(int));

/*
** filters_art.c
*/

int		filter_lsd(int color);
int		filter_hope(int color);
int		filter_pixel(int color);

/*
** filters_color.c
*/

int		filter_neg(int color);
int		filter_grey(int color);
int		filter_sepia(int color);
int		filter_water(int color);
int		filter_noise(int color);

/*
** filters_tv.c
*/

int		filter_canal(int color);

#endif /* !MAIN_H_ */
