/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:27:08 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/09 15:03:11 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// ! TO_REVIEW

void	set_polar_coords(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.axis[X_AXIS] - 1);
	steps_y = M_PI / (map->limits.axis[Y_AXIS]);
	map->radius = map->limits.axis[X_AXIS] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[LONG] = -(map->points[i].axis[X_AXIS]) * steps_x;
		if (map->points[i].axis[Y_AXIS] > 0)
			map->points[i].polar[LAT] = ((map->points[i].axis[Y_AXIS]) + \
			(map->limits.axis[Y_AXIS] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[LAT] = (map->points[i].axis[Y_AXIS] + \
			(map->limits.axis[Y_AXIS] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}

}
