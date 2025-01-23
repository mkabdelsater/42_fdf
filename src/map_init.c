/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:15:55 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 16:18:56 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	map_init_colors(t_map *map)
{
	map->colors.back = BACK_COLOR;
	map->colors.menu = MENU_COLOR;
	map->colors.bottom = BOTTOM_COLOR;
	map->colors.ground = GROUND_COLOR;
	map->colors.top = TOP_COLOR;
}

void	map_init(t_map *map, bool is_first_init)
{
	if (is_first_init)
	{
		map->len = 0;
		map->limits.axis[X_AXIS] = 0;
		map->limits.axis[Y_AXIS] = 0;
		map->limits.axis[Z_AXIS] = 0;
		map->z_min = 0;
	}
	map->b_lines = true;
	map->b_dots = false;
	map->b_pluslines = false;
	map->b_geo = false;
	map->b_stars = false;
	map->b_shadow = true;
	map->scale = 1;
	map->z_divisor = 1;
	map->b_range = 0;
	map->source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) - MENU_WIDTH;
	map->source.axis[Y_AXIS] = WIN_HEIGHT / 2;
	map->source.axis[Z_AXIS] = 0;
	map->ang[X_AXIS] = 0;
	map->ang[Y_AXIS] = 0;
	map->ang[Z_AXIS] = 0;
	map_init_colors(map);
}
