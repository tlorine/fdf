/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:05:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/30 18:16:10 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			mouse_hook(int button, void *init)
{
	init = mlx_init();
	if (button == 1)
		hi(g_tmp, init, g_window, 1);
	if (button == 2)
		hi(g_tmp, init, g_window, 0);
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
