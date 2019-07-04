/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:05:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/07/04 19:15:46 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			mouse_hook(int button, void *init)
{
	(void)init;
	if (button == 1)
	{
		if (g_init != NULL)
		{
			free(g_init);
			g_init = NULL;
		}
		g_init = mlx_init();
		hi(g_tmp, g_init, 1);
	}
	if (button == 2)
	{
		if (g_init != NULL)
		{
			free(g_init);
			g_init = NULL;
		}
		g_init = mlx_init();
		hi(g_tmp, g_init, 0);
	}
	return (0);
}

int			hook_keydown(int key, void *init)
{
	if (key == 53)
	{
		mlx_destroy_window(init, g_window);
		exit(1);
	}
	return (0);
}
