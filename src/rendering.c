/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:38:37 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 14:01:26 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/geometry.h"
#include "../inc/utils.h"
#include "../inc/rendering.h"
#include <time.h>

// ! OPTIMIZATION ANGLE : non-polynomial time calculation?

static bool	point_is_in_screen(t_point *points, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (points[i].axis[X_AXIS] < (MENU_WIDTH + FIT_MARGIN) || \
			points[i].axis[X_AXIS] > (WIN_WIDTH - FIT_MARGIN))
			return (false);
		if (points[i].axis[Y_AXIS] < FIT_MARGIN || \
			points[i].axis[Y_AXIS] > (WIN_HEIGHT - FIT_MARGIN))
			return (false);
		i++;
	}
	return (true);
}

// ! AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA

static void	zoom_model_to_fit(t_globals *fdf, t_point *projection)
{
	fdf->map.source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) + MENU_WIDTH;
	fdf->map.source.axis[Y_AXIS] = WIN_HEIGHT / 2;
	fdf->map.source.axis[Z_AXIS] = 0;
	fdf->map.scale = 1;
	duplicate_map(fdf->map.points, projection, fdf->map.len);
	parse_map_to_model(fdf, projection);
	while (point_is_in_screen(projection, fdf->map.len))
	{
		duplicate_map(fdf->map.points, projection, fdf->map.len);
		parse_map_to_model(fdf, projection);
		fdf->map.scale += 0.2;
	}
}

static void	draw_wire(t_point *point, t_globals *fdf, int visual_density, int line)
{
	int	i;
	int	x_length;
	int	y_length;
	int	x_limit;

	i = 0;
	x_limit = (int)fdf->map.limits.axis[X_AXIS];
	while (i < x_limit)
	{
		x_length = i + visual_density;
		if (x_length >= x_limit)
			x_length = x_limit - 1;
		y_length = i + x_limit * visual_density;
		if (point[i].painted)
		{
			draw_line(fdf, point[i], point[x_length]);
			if (line + visual_density < (int)fdf->map.limits.axis[Y_AXIS])
				draw_line(fdf, point[i], point[y_length]);
		}
		i += visual_density;
	}
}

// ! TO_REFACTOR : magic number
static void	draw_wires(t_globals *fdf, t_point *wire)
{
	int	i;
	int	visual_density;

	visual_density = 8 / fdf->map.scale;
	if (visual_density == 0)
		visual_density = 1;
	i = 0;
	while (i < fdf->map.len)
	{
		draw_wire(&wire[i], fdf, visual_density, i / fdf->map.limits.axis[X_AXIS]);
		i += fdf->map.limits.axis[X_AXIS] * visual_density;
	}
}

// ! TO_REFACTOR : rename projection arg to something like model_projection?
// ! TODO : add functionality to resize window?
// ! TODO : make isometric the default view

int	render_model(t_globals *fdf, int fit)
{
	t_point *projection;
	clock_t	t;

	t = clock();
	projection = malloc(fdf->map.len * sizeof(t_point));
	if (projection == NULL)
		error_out("Failed Alocating memory for projected map in render_model()");
	fdf->map.renders++;
	draw_background(fdf, fdf->map.colors.back, \
		fdf->map.colors.menu);
	duplicate_map(fdf->map.points, projection, fdf->map.len);
	parse_map_to_model(fdf, projection);
	if (fit)
		zoom_model_to_fit(fdf, projection);
	if (fdf->map.b_lines)
		draw_wires(fdf, projection);
	// if (fdf->map.b_dots)
	mlx_put_image_to_window(fdf->mlx, fdf->win, \
		fdf->bitmap.img, 0, 0);
	draw_menu(fdf);
	free(projection);
	t = clock() - t;
	fdf->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
