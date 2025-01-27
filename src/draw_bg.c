/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:59:38 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 16:10:53 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	convert_color_to_32bit(t_globals *global_state, int color)
{
	if (global_state->bitmap.bits_per_pixel != 32)
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

static void	set_bitmap_color(char *bitmap_buf, int color, int alpha, int endian)
{
	if (endian == 1)
	{
		bitmap_buf[0] = alpha;
		bitmap_buf[1] = (color >> 16) & 0xFF;
		bitmap_buf[2] = (color >> 8) & 0xFF;
		bitmap_buf[3] = (color) & 0xFF;
	}
	else
	{
		bitmap_buf[0] = (color) & 0xFF;
		bitmap_buf[1] = (color >> 8) & 0xFF;
		bitmap_buf[2] = (color >> 16) & 0xFF;
		bitmap_buf[3] = alpha;
	}
}

// ! TO_REFACTOR: what does `pixel` mean here??

void	draw_background(t_globals *fdf, int bg_color, int menu_color)
{
	int	axis[2];
	int	i;
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
			i = (axis[Y_AXIS] * fdf->bitmap.lines) + (axis[X_AXIS] * 4);
			set_bitmap_color(&fdf->bitmap.buffer[i], \
				color, 1, fdf->bitmap.endian);
			axis[X_AXIS]++;
		}
		axis[Y_AXIS]++;
		axis[X_AXIS] = 0;
	}
}
