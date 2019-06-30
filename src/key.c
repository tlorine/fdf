/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:05:31 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/30 14:06:35 by tlorine          ###   ########.fr       */
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

int			hook_keydown(int key, void *init, void *g_window)
{
	if (key == 53)
	{
		(void)init;
		(void)g_window;
		exit(1);
	}
	return (0);
}
