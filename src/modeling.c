/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:38:37 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/10 16:02:27 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/geometry.h"
#include "../inc/utils.h"
#include <time.h>

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

// ! Optimization Angle : each of these functions can/should be applied separately
// ! to avoid redrawing the map everytime

static void	parse_map_to_model(t_globals *global_state, t_point *projection)
{
	z_division(projection, global_state->map.z_divisor, global_state->map.len);
	bend_model_view(projection, global_state->map.len, global_state->map.b_range);
	if (global_state->map.b_geo)
		toggle_geography_view(&global_state->map, projection);
	rotate_x(projection, projection, global_state->map.ang[X_AXIS], \
		global_state->map.len);
	rotate_y(projection, projection, global_state->map.ang[Y_AXIS], \
		global_state->map.len);
	rotate_z(projection, projection, global_state->map.ang[Z_AXIS], \
		global_state->map.len);
	if (global_state->map.b_geo && global_state->map.b_shadow)
		shadow(projection, global_state->map.len);
	orto_projection(projection, projection, global_state->map.len);
	scale(projection, global_state->map.scale, global_state->map.len);
	translate(projection, global_state->map.source, global_state->map.len);
}

int	draw_model(t_globals *global_state, int fit)
{
	t_point *projection;
	clock_t	t;

	t = clock();
	projection = malloc(global_state->map.len * sizeof(t_point));
	if (projection == NULL)
		error_out("Failed Alocating memory for projected map in draw_model()");
	global_state->map.renders = global_state->map.renders + 1;
	generate_background(global_state, global_state->map.colors.back, \
		global_state->map.colors.menu);
	copy_map(global_state->map.points, projection, global_state->map.len);
	parse_map_to_model(global_state, projection);
	drawing(global_state, projection, fit);
	mlx_put_image_to_window(global_state->mlx, global_state->win, \
		global_state->bitmap.img, 0, 0);
	draw_menu(global_state);
	free(projection);
	t = clock() - t;
	global_state->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
