/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:08 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/17 14:11:16 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

bool	point_is_in_window(t_point point)
{
	if (point.axis[X_AXIS] < 0 || point.axis[X_AXIS] > WIN_WIDTH)
		return (false);
	if(point.axis[Y_AXIS] < 0 || point.axis[Y_AXIS] > WIN_HEIGHT)
		return (false);
	return (true);
}

int	my_putpixel(t_globals *globals, t_point point)
{
	int	pixel;
	int	alpha;

	alpha = 0;
	if (point.axis[X_AXIS] < MENU_WIDTH)
		alpha = -10;
	if (point.axis[X_AXIS] >= WIN_WIDTH || point.axis[Y_AXIS] >= WIN_HEIGHT || \
		point.axis[X_AXIS] < 0 || point.axis[Y_AXIS] < 0)
		return (-1);
	pixel = ((int)point.axis[Y_AXIS] * WIN_WIDTH * 4) + ((int)point.axis[X_AXIS] * 4);
	if (globals->bitmap.bit_x_pixel != 32)
		point.color = mlx_get_color_value(globals->mlx, point.color);
	set_color(&globals->bitmap.buffer[pixel], \
		globals->bitmap.endian, point.color, alpha);
	return (0);
}

void	set_color(char *buffer, int endian, int color, int alpha)
{
	if (endian == 1)
	{
		buffer[0] = alpha;
		buffer[1] = (color >> 16) & 0xFF;
		buffer[2] = (color >> 8) & 0xFF;
		buffer[3] = (color) & 0xFF;
	}
	else
	{
		buffer[3] = alpha;
		buffer[2] = (color >> 16) & 0xFF;
		buffer[1] = (color >> 8) & 0xFF;
		buffer[0] = (color) & 0xFF;
	}
}

int	draw_line(t_globals *globals, t_point start, t_point end)
{
	t_point	delta;
	t_point	point;
	int		pixels;
	int		len;

	if (!point_is_in_window(start) && !point_is_in_window(end))
		return (0);
	delta.axis[X_AXIS] = end.axis[X_AXIS] - start.axis[X_AXIS];
	delta.axis[Y_AXIS] = end.axis[Y_AXIS] - start.axis[Y_AXIS];
	pixels = sqrt((delta.axis[X_AXIS] * delta.axis[X_AXIS]) + \
			(delta.axis[Y_AXIS] * delta.axis[Y_AXIS]));
	len = pixels;
	delta.axis[X_AXIS] /= pixels;
	delta.axis[Y_AXIS] /= pixels;
	point.axis[X_AXIS] = start.axis[X_AXIS];
	point.axis[Y_AXIS] = start.axis[Y_AXIS];
	while (pixels > 0)
	{
		point.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(globals, point);
		point.axis[X_AXIS] += delta.axis[X_AXIS];
		point.axis[Y_AXIS] += delta.axis[Y_AXIS];
		pixels--;
	}
	return (1);
}
