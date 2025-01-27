/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:51:32 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 16:10:53 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

static bool	point_is_in_window(t_point point)
{
	if (point.axis[X_AXIS] < 0 || point.axis[X_AXIS] > WIN_WIDTH)
		return (false);
	if (point.axis[Y_AXIS] < 0 || point.axis[Y_AXIS] > WIN_HEIGHT)
		return (false);
	return (true);
}

int	draw_line(t_globals *fdf, t_point start, t_point end)
{
	t_point	delta;
	t_point	point;
	int		pixels;
	int		len;

	if (!point_is_in_window(start) || !point_is_in_window(end))
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
		my_putpixel(fdf, point);
		point.axis[X_AXIS] += delta.axis[X_AXIS];
		point.axis[Y_AXIS] += delta.axis[Y_AXIS];
		pixels--;
	}
	return (1);
}

void	render_number(t_globals *fdf, int x_coord, int y_coord, int nbr)
{
	char	*converted_nbr;

	converted_nbr = ft_itoa(nbr);
	mlx_string_put(fdf->mlx, fdf->win, x_coord, y_coord, \
		NUMBER_COLOR, converted_nbr);
	free(converted_nbr);
}

void	render_string(t_globals *fdf, int x_coord, int y_coord, char *str)
{
	mlx_string_put(fdf->mlx, fdf->win, x_coord, y_coord, \
		TEXT_COLOR, str);
}

int	my_putpixel(t_globals *fdf, t_point point)
{
	int	pixel;
	int	alpha;

	alpha = 0;
	if (point.axis[X_AXIS] < MENU_WIDTH)
		alpha = -10;
	if (point.axis[X_AXIS] >= WIN_WIDTH || point.axis[Y_AXIS] >= WIN_HEIGHT || \
		point.axis[X_AXIS] < 0 || point.axis[Y_AXIS] < 0)
		return (-1);
	pixel = ((int)point.axis[Y_AXIS] * WIN_WIDTH * 4) + \
		((int)point.axis[X_AXIS] * 4);
	if (fdf->bitmap.bits_per_pixel != 32)
		point.color = mlx_get_color_value(fdf->mlx, point.color);
	set_color(&fdf->bitmap.buffer[pixel], \
		fdf->bitmap.endian, point.color, alpha);
	return (0);
}
