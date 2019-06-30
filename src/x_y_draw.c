/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_y_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:30:29 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/29 12:30:30 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line(t_coords *cor, t_string **string)
{
	double i;

	i = 0;
	while (cor->x1 != cor->x2 || cor->y1 != cor->y2)
	{
		if (cor->d_x >= cor->d_y && i < cor->error && cor->x1 != cor->x2)
			cor->x1 = cor->x1 + cor->ar_x;
		if (cor->d_y > cor->d_x && i < cor->error && cor->y1 != cor->y2)
			cor->y1 = cor->y1 + cor->ar_y;
		if (i >= cor->error)
		{
			if (cor->d_x >= cor->d_y)
				cor->y1 = cor->y1 + cor->ar_y;
			if (cor->d_x < cor->d_y)
				cor->x1 = cor->x1 + cor->ar_x;
			i = i - cor->error;
		}
		if (cor->x1 >= 1720 || cor->y1 >= 1280)
			return ;
		*(int*)((*string)->picture +
		((cor->x1 + (1720 * cor->y1)) * 4)) = 0x9b30ff;
		i++;
	}
}

void	put_v(t_coords *cor, t_string **string)
{
	if (cor->x2 == 0 && cor->y2 == 0)
	{
		return ;
	}
	cor->d_y = abs(cor->y1 - cor->y2);
	cor->d_x = abs(cor->x1 - cor->x2);
	cor->error = error_check(cor->d_x, cor->d_y);
	cor->ar_y = cor->y1 < cor->y2 ? 1 : -1;
	cor->ar_x = cor->x1 < cor->x2 ? 1 : -1;
	if (cor->d_x > cor->d_y)
		cor->x1 = cor->x1 - cor->ar_x;
	if (cor->d_x < cor->d_y)
		cor->y1 = cor->y1 - cor->ar_y;
	put_line(cor, string);
}

void	draw_x(t_pixel **list, t_string **string, t_coords *cor)
{
	while ((*list)->next != NULL)
	{
		if ((*list)->next != NULL)
		{
			if ((*list)->next->hx == 0)
				(*list) = (*list)->next;
		}
		coor((*list), (*list)->next, &cor);
		put_v(cor, string);
		(*list) = (*list)->next;
	}
}

void	draw_y(t_pixel **list, t_string **string, t_coords *cor)
{
	t_pixel *list_y;

	list_y = (*list);
	while (list_y != NULL)
	{
		if (list_y->hy != 0)
			break ;
		list_y = list_y->next;
	}
	while (list_y != NULL)
	{
		coor((*list), list_y, &cor);
		put_v(cor, string);
		list_y = list_y->next;
		(*list) = (*list)->next;
	}
}
