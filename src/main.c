/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:51:58 by tlorine           #+#    #+#             */
/*   Updated: 2019/07/04 19:19:03 by tlorine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			map_size(char *argv)
{
	if (strcmp("test_maps/mars.fdf", argv) == 0)
		return (4);
	if (strcmp("test_maps/10-2.fdf", argv) == 0)
		return (50);
	if (strcmp("test_maps/100-6.fdf", argv) == 0 ||
	strcmp("test_maps/20-60.fdf", argv) == 0
	|| strcmp("test_maps/10-70.fdf", argv) == 0)
		return (5);
	if (strcmp("test_maps/42.fdf", argv) == 0
	|| strcmp("test_maps/basictest.fdf", argv) == 0)
		return (42);
	if (strcmp("test_maps/elem.fdf", argv) == 0)
		return (30);
	return (10);
}

t_pixel		*fill_list(int map, int pr)
{
	char	*line;
	int		y;
	t_pixel *new_list;
	t_pixel *list;

	y = 0;
	if (!(list = (t_pixel *)malloc(sizeof(t_pixel))))
		return (NULL);
	new_list = list;
	while (get_next_line(map, &line) == 1)
	{
		list = fill_elem(&list, line, y, pr);
		free(line);
		line = NULL;
		y++;
	}
	close(map);
	list->next = NULL;
	return (new_list);
}

int			hi(char *argv, void *g_init, int pr)
{
	t_pixel		*list;
	t_string	*string;
	void		*image;

	image = mlx_new_image(g_init, 1720, 1280);
	string = (t_string *)malloc(sizeof(t_string));
	list = fill_list(open(argv, O_RDONLY), pr);
	string->picture = mlx_get_data_addr(image, &string->bits,
	&string->size, &string->endian);
	string->bits = string->bits / 8;
	ft_bzero(string->picture, WEIGHT * HEIGHT * string->bits);
	drawing(&string, &list, image, g_init);
	list = NULL;
	string = NULL;
	return (0);
}

int			main(int argc, char **argv)
{
	void	*g_init;

	if (argc == 2)
	{
		g_init = mlx_init();
		g_window = mlx_new_window(g_init, 1720, 1280, "g_window");
		g_tmp = argv[1];
		hi(g_tmp, g_init, 0);
		mlx_key_hook(g_window, hook_keydown, g_init);
		mlx_mouse_hook(g_window, mouse_hook, g_init);
		mlx_loop(g_init);
	}
	return (0);
}
