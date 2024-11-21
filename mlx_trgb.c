/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_color_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:20:36 by moabdels          #+#    #+#             */
/*   Updated: 2024/11/21 13:24:14 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_trgb_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_trgb_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_trgb_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_trgb_b(int trgb)
{
	return (trgb & 0xFF);
}
