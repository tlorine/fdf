/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:34:55 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/30 14:05:22 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WEIGHT 1720
# define HEIGHT 1280

void				*g_tmp;
void				*g_window;

typedef struct	s_pixel
{
	double			x;
	double			y;
	double			z;
	double			hx;
	double			hy;
	struct s_pixel	*next;
}				t_pixel;

typedef struct	s_string
{
	int			size;
	int			bits;
	int			endian;
	char		*picture;
}				t_string;

typedef struct	s_coords
{
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	double		ar_y;
	double		ar_x;
	double		error;
	double		d_x;
	double		d_y;
}				t_coords;

double			error_check(double d_x, double d_y);
void			put_v(t_coords *cor, t_string **string);
void			drawing(t_string **string, t_pixel **list);
void			iso(t_pixel **list);
void			isomet(double *x, double *y, int z, int pr);
void			draw_x(t_pixel **list, t_string **string, t_coords *cor);
t_pixel			*fill_elem(t_pixel **list, char *line, int y, int pr);
void			draw_y(t_pixel **list, t_string **string, t_coords *cor);
void			coor(t_pixel *save1, t_pixel *save2, t_coords **coor);
void			clear_str(t_pixel *list);
int				hook_keydown(int key, void *init, void *window);
int				hi(char *argv, void *init, void *window, int pr);
int				mouse_hook(int button, void *init);
int				map_size(char *argv);

#endif
