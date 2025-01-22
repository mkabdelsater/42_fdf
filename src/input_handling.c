/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:56:38 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 11:45:10 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/keycodes.h"

// !TO_REFACTOR

static void modify_angle(float *angle, float mod)
{
	*angle += mod;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >=360)
		*angle = *angle - 360;
}

// !TODO : Add wasdqe control scheme

static void	rotation_control(int key, t_globals *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.b_key_ctrl)
		ang = 90;
	if (key == KEY_DOWN)
		modify_angle(&fdf->map.ang[X_AXIS], ang);
	if (key == KEY_UP)
		modify_angle(&fdf->map.ang[X_AXIS], -ang);
	if (key == KEY_LEFT)
		modify_angle(&fdf->map.ang[Y_AXIS], ang);
	if (key == KEY_RIGHT)
		modify_angle(&fdf->map.ang[Y_AXIS], -ang);
	if (key == KEY_Q)
		modify_angle(&fdf->map.ang[Z_AXIS], ang);
	if (key == KEY_W)
		modify_angle(&fdf->map.ang[Z_AXIS], -ang);
}

static void set_view_to_topdown(t_map *map)
{
	map->b_geo = 0;
	map->ang[X_AXIS] = 90;
	map->ang[Y_AXIS] = 0;
	map->ang[Z_AXIS] = 0;
	map->b_range = 0;
	map->source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y_AXIS] = WIN_HEIGHT / 2;
}

static void	map_controls_a(int key, t_globals *fdf)
{
	if (key == KEY_ESC)
		terminate(fdf);
	if (key == KEY_R)
	{
		map_init(&fdf->map, false);
		fdf->map.proportion = \
			fdf->map.limits.axis[Z_AXIS] / fdf->map.limits.axis[X_AXIS];
		if (fdf->map.proportion > 0.5)
			fdf->map.z_divisor = fdf->map.proportion * 30;
		color_map_points(&fdf->map);
		render_model(fdf, FIT);
	}
	if (key == KEY_C)
	{
		fdf->map.source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) + MENU_WIDTH;
		fdf->map.source.axis[Y_AXIS] = WIN_HEIGHT / 2;
	}
	if (key == KEY_P)
	{
		set_view_to_topdown(&fdf->map);
		render_model(fdf, FIT);
	}
}

// ? the signature is based on the prototypes found in the MLX library
// ? the return value is mask?

int	on_key_down(int key, void *param)
{
	t_globals *fdf;

	fdf = (t_globals *)param;
	rotation_control(key, fdf);
	map_controls_a(key, fdf);
	render_model(fdf, FREE);
	return (0);
}
