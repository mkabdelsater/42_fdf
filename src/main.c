/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:55:14 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 12:09:10 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/input_handling.h"

int		terminate(t_globals *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->map.points);
	exit(EXIT_SUCCESS);
}

void	system_init(t_globals *fdf)
{
	fdf->map.renders = 0;
	fdf->map.proportion = fdf->map.limits.axis[Z_AXIS] / \
		fdf->map.limits.axis[X_AXIS];
	if (fdf->map.proportion > 0.5)
		fdf->map.z_divisor = fdf->map.proportion * 30;
	fdf->keys.b_key_ctrl = false;
	fdf->keys.b_mouse_l = false;
	fdf->keys.b_mouse_r = false;
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, \
		WIN_HEIGHT,"FDF - moabdels");
	fdf->bitmap.img = mlx_new_image(fdf->mlx, WIN_WIDTH, \
		WIN_HEIGHT);
	fdf->bitmap.buffer = mlx_get_data_addr(fdf->bitmap.img, \
		&fdf->bitmap.bit_x_pixel, &fdf->bitmap.lines, &fdf->bitmap.endian);
}

void	error_out(char *err_msg)
{
	ft_putstr_fd(ERR_TAG, 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

// !TODO Add a stats menu and a controls menu and an options to flip between them

int	main(int argv, char **argc)
{
	t_globals	fdf;

	if (argv != 2)
		error_out("Number of arguments not 1 - Usage : `./fdf <map file>`");
	load_map(&fdf.map, argc[1]);
	system_init(&fdf);
	if (render_model(&fdf, FIT) < 0)
		error_out("Error Drawing Model");
	mlx_hook(fdf.win, 2, 1L << 0, on_key_down, &fdf);
	mlx_hook(fdf.win, 17, 0, terminate, &fdf);
	mlx_loop(fdf.mlx);
	free(fdf.map.points);
	free(fdf.map.memory);
	exit(EXIT_SUCCESS);
}
