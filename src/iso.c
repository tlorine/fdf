/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 12:21:28 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/30 14:09:29 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		isomet(double *x, double *y, int z, int pr)
{
	double previous_x;
	double previous_y;

	previous_x = *x;
	previous_y = *y;
	if (pr != 0)
	{
		*x = (previous_x - previous_y) * cos(0.523599) + WEIGHT / 2;
		*y = -z + (previous_x + previous_y) * sin(0.523599) + HEIGHT / 2;
	}
	else
	{
		*x = *x + WEIGHT / 2;
		*y = (*y - z) + HEIGHT / 2;
	}
}

t_pixel		*fill_elem(t_pixel **list, char *line, int y, int pr)
{
	int x;

	x = 0;
	while (*line != '\0')
	{
		if (y > 0 || x > 0)
		{
			if (!((*list)->next = (t_pixel *)malloc(sizeof(t_pixel))))
				return (NULL);
			(*list) = (*list)->next;
		}
		(*list)->x = x * map_size(g_tmp);
		(*list)->y = y * map_size(g_tmp);
		(*list)->z = ft_atoi(line) * map_size(g_tmp);
		(*list)->hx = x;
		(*list)->hy = y;
		isomet(&(*list)->x, &(*list)->y, (*list)->z, pr);
		x++;
		while (*line != '\0' && *line != ' ')
			line++;
		while (*line != '\0' && *line == ' ')
			line++;
	}
	return ((*list));
}

void		iso(t_pixel **list)
{
	double	*x;
	double	*y;

	while ((*list) != NULL)
	{
		x = &(*list)->x;
		y = &(*list)->y;
		isomet(x, y, (*list)->z, 0);
		(*list) = (*list)->next;
	}
}
