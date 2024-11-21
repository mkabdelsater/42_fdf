/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:04 by moabdels          #+#    #+#             */
/*   Updated: 2024/11/21 13:59:22 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


//? EXP : what if unsigned int was unsigned short?
/**
 *! Because an image is represented in real time in a window, changing the same
 *! image will cause screen-tearing when writing to it.
 *$ use `mlx_sync` instead
 */

void	ft_pixel_put(t_img_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->address + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
	*(unsigned int*)dest = color;
}
