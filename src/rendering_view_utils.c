/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_view_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:09:20 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 16:36:33 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	set_view_to_isometric(t_map *map)
{
	map->b_geo = 0;
	map->ang[X_AXIS] = 30;
	map->ang[Y_AXIS] = 330;
	map->ang[Z_AXIS] = 30;
	map->b_range = 0;
	map->source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) + MENU_WIDTH;
	map->source.axis[Y_AXIS] = WIN_HEIGHT / 2;
}

void	toggle_opacity(t_point *points, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[Z_AXIS] < 0)
			points[i].painted = 0;
		else
			points[i].painted = 1;
		i++;
	}
}
