/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:56:38 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 14:28:57 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/rendering.h"
#include "../inc/keycodes.h"
#include "../inc/input_handling.h"

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

static void	map_controls_b(int key, t_globals *fdf)
{
	if (key == KEY_D)
		fdf->map.b_dots = !fdf->map.b_dots;
	if (key == KEY_L)
		fdf->map.b_lines = !fdf->map.b_lines;
	if (key == KEY_X)
		fdf->map.b_pluslines = !fdf->map.b_pluslines;
	if (key == KEY_G)
		fdf->map.b_geo = !fdf->map.b_geo;
	if (key == KEY_S)
		fdf->map.b_stars = !fdf->map.b_stars;
	if (key == KEY_H)
		fdf->map.b_shadow = !fdf->map.b_shadow;
	if (key == KEY_F)
		render_model(fdf, FIT);
	if (key == KEY_CMD)
		fdf->keys.b_key_ctrl = 1;
}

static void map_controls_c(int key, t_globals *fdf)
{
	if (key == KEY_B && fdf->keys.b_key_ctrl)
		fdf->map.b_range -= 0.0001;
	if (key == KEY_B && !fdf->keys.b_key_ctrl)
		fdf->map.b_range += 0.0001;
	if ((key == KEY_SUM || key == KEY_SUM2) && fdf->keys.b_key_ctrl)
		fdf->map.scale *= 1.5;
	if ((key == KEY_RES || key == KEY_RES2) && fdf->keys.b_key_ctrl)
		fdf->map.scale /= 1.5;
	if ((key == KEY_SUM || key == KEY_SUM2) && fdf->map.z_divisor > 1)
		fdf->map.z_divisor -= 10;
	if (key == KEY_I)
	{
		set_view_to_isometric(&fdf->map);
		render_model(fdf, FIT);
	}
}

// ? the signature is based on the prototypes found in the MLX library
// ! TO_REFACTOR : there are actions that trigger re-rendering twice, bad!

int	on_key_down(int key, void *param)
{
	t_globals *fdf;

	fdf = (t_globals *)param;
	rotation_control(key, fdf);
	map_controls_a(key, fdf);
	map_controls_b(key, fdf);
	map_controls_c(key, fdf);
	render_model(fdf, FREE);
	return (0);
}
