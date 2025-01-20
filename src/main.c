/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 11:55:14 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 16:43:42 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"

void	system_init(t_globals *global_state)
{
	global_state->map.renders = 0;
	global_state->map.proportion = global_state->map.limits.axis[Z_AXIS] / \
		global_state->map.limits.axis[X_AXIS];
	if (global_state->map.proportion > 0.5)
		global_state->map.z_divisor = global_state->map.proportion * 30;
	global_state->keys.b_key_ctrl = 0;
	global_state->keys.b_mouse_l = 0;
	global_state->keys.b_mouse_r = 0;
	global_state->mlx = mlx_init();
	global_state->win = mlx_new_window(global_state->mlx, WIN_WIDTH, \
		WIN_HEIGHT,"FDF - moabdels");
	global_state->bitmap.img = mlx_new_image(global_state->mlx, WIN_WIDTH, \
		WIN_HEIGHT);
	global_state->bitmap.buffer = mlx_get_data_addr(global_state->bitmap.img, \
		&global_state->bitmap.bit_x_pixel, &global_state->bitmap.lines, \
		&global_state->bitmap.endian);
}

void	error_out(char *err_msg)
{
	ft_putstr_fd(ERR_TAG, 2);
	ft_putstr_fd(err_msg, 2);
	exit(EXIT_FAILURE);
}

int	main(int argv, char **argc)
{
	t_globals	fdf;

	if (argv != 2)
		error_out("Number of arguments not 1 - Usage : `./fdf <map file>`");
	load_map(&fdf.map, argc[1]);
	system_init(&fdf);
	if (draw_model(&fdf, FIT) < 0)
		error_out("Error Drawing Model");
	mlx_loop(fdf.mlx);
	free(fdf.map.points);
	free(fdf.map.memory);
	exit(EXIT_SUCCESS);
}
