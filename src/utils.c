/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:08 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 15:20:26 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

bool	point_is_in_window(t_point point)
{
	if (point.axis[X_AXIS] < 0 || point.axis[X_AXIS] > WIN_WIDTH)
		return (false);
	if(point.axis[Y_AXIS] < 0 || point.axis[Y_AXIS] > WIN_HEIGHT)
		return (false);
	return (true);
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


int	ft_round_double(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

// !REFACTOR
int	gradient(int start_color, int end_color, int len, int pixels)
{
	double	increment[3];
	int		new[3];
	int		new_color;

	increment[0] = (double)((end_color >> 16) - \
					(start_color >> 16)) / (double)len;
	increment[1] = (double)(((end_color >> 8) & 0xFF) - \
					((start_color >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((end_color & 0xFF) - \
					(start_color & 0xFF)) / (double)len;
	new[0] = (start_color >> 16) + ft_round_double(pixels * increment[0]);
	new[1] = ((start_color >> 8) & 0xFF) + ft_round_double(pixels * increment[1]);
	new[2] = (start_color & 0xFF) + ft_round_double(pixels * increment[2]);
	new_color = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_color);
}

int	draw_line(t_globals *globals, t_point start, t_point end)
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
		my_putpixel(globals, point);
		point.axis[X_AXIS] += delta.axis[X_AXIS];
		point.axis[Y_AXIS] += delta.axis[Y_AXIS];
		pixels--;
	}
	return (1);
}

void	free_2d_vector(char **vec)
{
	int	i;

	if (!vec)
		return ;
	i = 0;
	while (vec[i])
	{
		free(vec[i]);
		i++;
	}
	free (vec);
}

void	print_nbr(t_globals *global_state, int x_coord, int y_coord, int nbr)
{
	char	*converted_nbr;

	converted_nbr = ft_itoa(nbr);
	mlx_string_put(global_state->mlx, global_state->win, x_coord, y_coord, \
		NUMBER_COLOR, converted_nbr);
	free(converted_nbr);
}
