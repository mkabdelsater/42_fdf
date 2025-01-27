/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:08 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 12:59:32 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

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

static int	ft_round_double(double num)
{
	int	rounded;

	rounded = (int)num;
	if (num - rounded >= .5)
		rounded++;
	return (rounded);
}

// !TO_REFACTOR
int	gradient(int start_color, int end_color, int len, int pixels)
{
	double	step[3];
	int		new[3];
	int		new_color;

	step[0] = (double)((end_color >> 16) - \
					(start_color >> 16)) / (double)len;
	step[1] = (double)(((end_color >> 8) & 0xFF) - \
					((start_color >> 8) & 0xFF)) / (double)len;
	step[2] = (double)((end_color & 0xFF) - \
					(start_color & 0xFF)) / (double)len;
	new[0] = (start_color >> 16) + ft_round_double(pixels * step[0]);
	new[1] = ((start_color >> 8) & 0xFF) + ft_round_double(pixels * step[1]);
	new[2] = (start_color & 0xFF) + ft_round_double(pixels * step[2]);
	new_color = (new[0] << 16) + (new[1] << 8) + new[2];
	return (new_color);
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
