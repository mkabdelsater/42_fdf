/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:21:30 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 12:59:58 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rendering.h"

static void	z_division(t_point *projection, float divisor, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		projection[i].axis[Z_AXIS] /= divisor;
		i++;
	}
}

static void	bend_model_view(t_point *points, int len, float range)
{
	int		i;
	float	bend_factor;

	i = 0;
	while (i < len)
	{
		bend_factor = (pow(points[i].axis[X_AXIS], 2) * range) + \
			(pow(points[i].axis[Y_AXIS], 2) * range);
		points[i].axis[Z_AXIS] -= bend_factor;
		i++;
	}
}

// ! TO_REFACTOR this might not be working correctly?

static void	toggle_geography_view(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].axis[X_AXIS] = (map->radius + points[i].axis[Z_AXIS]) * \
			cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Y_AXIS] = (map->radius + points[i].axis[Z_AXIS]) * \
			sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		points[i].axis[Z_AXIS] = (map->radius + points[i].axis[Z_AXIS]) * \
			cos(points[i].polar[LAT]);
		i++;
	}
}

static void	scale_model(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X_AXIS] = points[i].axis[X_AXIS] * scale;
		points[i].axis[Y_AXIS] = points[i].axis[Y_AXIS] * scale;
		points[i].axis[Z_AXIS] = points[i].axis[Z_AXIS] * scale;
		i++;
	}
}

static void	translate_model(t_point *points, t_point dest, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X_AXIS] = points[i].axis[X_AXIS] + dest.axis[X_AXIS];
		points[i].axis[Y_AXIS] = points[i].axis[Y_AXIS] + dest.axis[Y_AXIS];
		points[i].axis[Z_AXIS] = points[i].axis[Z_AXIS] + dest.axis[Z_AXIS];
		i++;
	}
}

void	parse_map_to_model(t_globals *fdf, t_point *projection)
{
	z_division(projection, fdf->map.z_divisor, fdf->map.len);
	bend_model_view(projection, fdf->map.len, fdf->map.b_range);
	if (fdf->map.b_geo)
		toggle_geography_view(&fdf->map, projection);
	rotate_along_axis(projection, projection, fdf->map.ang[X_AXIS], \
		fdf->map.len, X_AXIS);
	rotate_along_axis(projection, projection, fdf->map.ang[Y_AXIS], \
		fdf->map.len, Y_AXIS);
	rotate_along_axis(projection, projection, fdf->map.ang[Z_AXIS], \
		fdf->map.len, Z_AXIS);
	// if (fdf->map.b_geo && fdf->map.b_shadow)
	// 	shadow(projection, fdf->map.len);
	orto_projection(projection, projection, fdf->map.len);
	scale_model(projection, fdf->map.scale, fdf->map.len);
	translate_model(projection, fdf->map.source, fdf->map.len);
}
