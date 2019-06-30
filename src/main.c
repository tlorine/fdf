/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlorine <tlorine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 13:51:58 by tlorine           #+#    #+#             */
/*   Updated: 2019/06/30 18:19:34 by tlorine          ###   ########.fr       */
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

int			hi(char *argv, void *init, void *g_window, int pr)
{
	t_pixel		*list;
	t_string	*string;
	void		*image;

	image = mlx_new_image(init, 1720, 1280);
	string = (t_string *)malloc(sizeof(t_string));
	list = fill_list(open(argv, O_RDONLY), pr);
	string->picture = mlx_get_data_addr(image, &string->bits,
	&string->size, &string->endian);
	string->bits = string->bits / 8;
	ft_bzero(string->picture, WEIGHT * HEIGHT * string->bits);
	drawing(&string, &list);
	clear_str(&list);
	list = NULL;
	free(string);
	string = NULL;
	mlx_put_image_to_window(init, g_window, image, 0, 0);
	mlx_destroy_image(init, image);
	return (0);
}

int			main(int argc, char **argv)
{
	void		*init;

	if (argc == 2)
	{
		init = mlx_init();
		g_tmp = argv[1];
		g_window = mlx_new_window(init, 1720, 1280, "g_window");
		hi(g_tmp, init, g_window, 0);
		mlx_key_hook(g_window, hook_keydown, init);
		mlx_mouse_hook(g_window, mouse_hook, init);
		mlx_loop(init);
	}
	return (0);
}
