/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:16:44 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/29 15:48:11 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

double	error_check(double d_x, double d_y)
{
	if (d_x == 0 && d_y == 0)
		return (-1);
	if (d_x == 0 || d_y == 0)
		return (d_x != 0 ? d_x + 1 : d_y + 1);
	if (d_x == d_y)
		return (2);
	if (d_x > d_y)
		return ((d_x / d_y) + 1);
	if (d_y > d_x)
		return ((d_y / d_x) + 1);
	return (0);
}

void	coor(t_pixel *save1, t_pixel *save2, t_coords **coor)
{
	(*coor)->x1 = save1->x;
	(*coor)->x2 = save2->x;
	(*coor)->y1 = save1->y;
	(*coor)->y2 = save2->y;
	(*coor)->d_x = 0;
	(*coor)->d_y = 0;
	(*coor)->error = 0;
	(*coor)->ar_y = 0;
	(*coor)->ar_x = 0;
}

void	clear_str(t_pixel *list)
{
	if (list->next != NULL)
		clear_str(list->next);
	free(list);
}

void	drawing(t_string **string, t_pixel **list)
{
	t_pixel		*new;
	t_coords	*cor;

	cor = (t_coords *)malloc(sizeof(t_coords));
	new = (*list);
	ft_bzero((*string)->picture, WEIGHT * HEIGHT * (*string)->bits);
	draw_x(list, string, cor);
	(*list) = new;
	draw_y(list, string, cor);
	free(cor);
}
