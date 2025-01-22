/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:38:37 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 12:21:40 by moabdels         ###   ########.fr       */
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

// ! TO_REFACTOR: put this into it's own file - matrix operations

static void	b_zero_matrix(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	set_projection_matrix(float (*matrix)[3], int axis, float angle)
{
	b_zero_matrix(matrix);
	if (axis == X_AXIS)
	{
		matrix[0][0] = 1;
		matrix[1][1] = cos(angle);
		matrix[1][2] = -sin(angle);
		matrix[2][1] = sin(angle);
		matrix[2][2] = cos(angle);
	}
	else if (axis == Y_AXIS)
	{
		matrix[0][0] = cos(angle);
		matrix[0][2] = sin(angle);
		matrix[1][1] = 1;
		matrix[2][0] = -sin(angle);
		matrix[2][2] = cos(angle);
	}
	else
	{
		matrix[0][0] = cos(angle);
		matrix[0][1] = -sin(angle);
		matrix[1][0] = sin(angle);
		matrix[1][1] = cos(angle);
		matrix[2][2] = 1;
	}
}

static t_point	project_point(float matrix[3][3], t_point point)
{
	int		i;
	int		j;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = point.color;
		j = 0;
		while (j < 3)
		{
			result.axis[i] += matrix[i][j] * point.axis[j];
			j++;
		}
		i++;
	}
	return (result);
}

static void	rotate_along_axis(t_point *points, t_point *projection, \
	float angle, int len, int axis)
{
	int		i;
	float	projection_matrix[3][3];
	float	rad;

	rad = angle * M_PI / 180;
	set_projection_matrix(projection_matrix, axis, rad);
	i = 0;
	while (i < len)
	{
		projection[i] = project_point(projection_matrix, points[i]);
		i++;
	}
}

static void	orto_projection(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	b_zero_matrix(projection_matrix);
	// !TO_RESEARCH
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = project_point(projection_matrix, points[i]);
		i++;
	}
}

// ! Optimization Angle : each of these functions can/should be applied separately
// ! to avoid redrawing the map everytime

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

static void	parse_map_to_model(t_globals *fdf, t_point *projection)
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
	// if (global_state->map.b_geo && global_state->map.b_shadow)
	// 	shadow(projection, global_state->map.len);
	orto_projection(projection, projection, fdf->map.len);
	scale_model(projection, fdf->map.scale, fdf->map.len);
	translate_model(projection, fdf->map.source, fdf->map.len);
}

static void	duplicate_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

static int	convert_color_to_32bit(t_globals *global_state, int color)
{
	if (global_state->bitmap.bit_x_pixel != 32)
		color = mlx_get_color_value(global_state->mlx, color);
	return (color);
}

/*
 ! TO_REFACTOR: we do this operation several times? should probably be used more?
 *
 * fill the 4 bytes of the bitmap buffer with the color values
 * endian == 1 => MSB - Alpha
 * endian == 0 => LSB - Blue
 *
 */

static void	set_bitmap_color(char *bitmap_buffer, int color, int alpha, int endian)
{
	if (endian == 1)
	{
		bitmap_buffer[0] = alpha;
		bitmap_buffer[1] = (color >> 16) & 0xFF;
		bitmap_buffer[2] = (color >> 8) & 0xFF;
		bitmap_buffer[3] = (color) & 0xFF;
	}
	else
	{
		bitmap_buffer[0] = (color) & 0xFF;
		bitmap_buffer[1] = (color >> 8) & 0xFF;
		bitmap_buffer[2] = (color >> 16) & 0xFF;
		bitmap_buffer[3] = alpha;
	}
}

// ! TO_REFACTOR: what does `pixel` mean here??

static void	draw_background(t_globals *fdf, int bg_color, int menu_color)
{
	int	axis[2];
	int	pixel_index;
	int	color;

	axis[Y_AXIS] = 0;
	axis[X_AXIS] = 0;
	bg_color = convert_color_to_32bit(fdf, bg_color);
	menu_color = convert_color_to_32bit(fdf, menu_color);
	while (axis[Y_AXIS] < WIN_HEIGHT)
	{
		while (axis[X_AXIS] < WIN_WIDTH)
		{
			if (axis[X_AXIS] < MENU_WIDTH)
				color = menu_color;
			else
				color = bg_color;
			pixel_index = (axis[Y_AXIS] * fdf->bitmap.lines) + (axis[X_AXIS] * 4);
			set_bitmap_color(&fdf->bitmap.buffer[pixel_index], \
				color, 1, fdf->bitmap.endian);
			axis[X_AXIS]++;
		}
		axis[Y_AXIS]++;
		axis[X_AXIS] = 0;
	}
}

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

static void	zoom_model_to_fit(t_globals *global_state, t_point *projection)
{
	global_state->map.source.axis[X_AXIS] = ((WIN_WIDTH - MENU_WIDTH) / 2) + MENU_WIDTH;
	global_state->map.source.axis[Y_AXIS] = WIN_HEIGHT / 2;
	global_state->map.source.axis[Z_AXIS] = 0;
	global_state->map.scale = 1;
	duplicate_map(global_state->map.points, projection, global_state->map.len);
	parse_map_to_model(global_state, projection);
	while (point_is_in_screen(projection, global_state->map.len))
	{
		duplicate_map(global_state->map.points, projection, global_state->map.len);
		parse_map_to_model(global_state, projection);
		global_state->map.scale = global_state->map.scale + 0.2;
	}
}

static void	draw_wire(t_point *point, t_globals *global_state, int visual_density, int line)
{
	int	i;
	int	x_length;
	int	y_length;
	int	x_limit;

	i = 0;
	x_limit = (int)global_state->map.limits.axis[X_AXIS];
	while (i < x_limit)
	{
		x_length = i + visual_density;
		if (x_length >= x_limit)
			x_length = x_limit - 1;
		y_length = i + x_limit * visual_density;
		if (point[i].painted)
		{
			draw_line(global_state, point[i], point[x_length]);
			if (line + visual_density < (int)global_state->map.limits.axis[Y_AXIS])
				draw_line(global_state, point[i], point[y_length]);
		}
		i += visual_density;
	}
}

// ! TO_REFACTOR : magic number
static void	draw_wires(t_globals *global_state, t_point *wire)
{
	int	i;
	int	visual_density;

	visual_density = 8 / global_state->map.scale;
	if (visual_density == 0)
		visual_density = 1;
	i = 0;
	while (i < global_state->map.len)
	{
		draw_wire(&wire[i], global_state, visual_density, i / global_state->map.limits.axis[X_AXIS]);
		i += global_state->map.limits.axis[X_AXIS] * visual_density;
	}
}

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

// ! TO_REFACTOR : rename projection arg to something like model_projection
// ! TODO : add functionality to resize window

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
	mlx_put_image_to_window(fdf->mlx, fdf->win, \
		fdf->bitmap.img, 0, 0);
	draw_menu(fdf);
	free(projection);
	t = clock() - t;
	fdf->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
