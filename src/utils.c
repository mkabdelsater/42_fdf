/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:08 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/17 14:00:29 by moabdels         ###   ########.fr       */
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


