/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:10:12 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/28 15:26:17 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/keycodes.h"
#include "../inc/input_handling.h"

// ! TO_REFACTOR
void	modify_angle(float *angle, float mod)
{
	*angle += mod;
	if (*angle < 0)
		*angle = 360 + *angle;
	if (*angle >= 360)
		*angle = *angle - 360;
}

// !TODO : Add wasdqe control scheme

void	rotation_control(int key, t_globals *fdf)
{
	int	ang;

	ang = 1;
	if (fdf->keys.ctrl)
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

int	on_key_release(int key, void *param)
{
	t_globals	*fdf;

	fdf = (t_globals *)param;
	if (key == KEY_CTRL)
		fdf->keys.ctrl = false;
	return (0);
}

void	swap_color_scheme(int key, t_map *map)
{
	map->colors.back = WOODSMOKE;
	map->colors.bottom = DODGER_BLUE;
	map->colors.top = MAROON;
	map->colors.ground = TULIP_TREE;
	if (key == KEY_2)
	{
		map->colors.back = SILVER;
		map->colors.bottom = WOODSMOKE;
		map->colors.top = WOODSMOKE;
		map->colors.ground = WOODSMOKE;
	}
	if (key == KEY_3)
	{
		map->colors.bottom = SILVER;
		map->colors.top = SILVER;
		map->colors.ground = SILVER;
	}
	if (key == KEY_4)
	{
		map->colors.bottom = BLUE;
		map->colors.top = FIREBRICK_RED;
		map->colors.ground = LIME_GREEN;
	}
	color_map_points(map);
}
