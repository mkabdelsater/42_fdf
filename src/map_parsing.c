/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:21:30 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 14:26:44 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/rendering.h"
#include "../inc/geometry.h"

// ! Optimization Angle : each of these functions can or
// ! should be applied separately
// ! to avoid redrawing the map everytime?

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
	int	i;

	i = 0;
	while (i < fdf->map.len)
	{
		projection[i].axis[Z_AXIS] /= fdf->map.z_divisor;
		i++;
	}
	bend_model_view(projection, fdf->map.len, fdf->map.b_range);
	if (fdf->map.b_geo)
		toggle_geography_view(&fdf->map, projection);
	project_x(projection, projection, fdf->map.ang[X_AXIS], \
		fdf->map.len);
	project_y(projection, projection, fdf->map.ang[Y_AXIS], \
		fdf->map.len);
	project_z(projection, projection, fdf->map.ang[Z_AXIS], \
		fdf->map.len);
	if (fdf->map.b_geo && fdf->map.b_shadow)
		toggle_opacity(projection, fdf->map.len);
	orto_projection(projection, projection, fdf->map.len);
	scale_model(projection, fdf->map.scale, fdf->map.len);
	translate_model(projection, fdf->map.source, fdf->map.len);
}
