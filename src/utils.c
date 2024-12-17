/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:29:08 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/17 13:49:36 by moabdels         ###   ########.fr       */
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

int	put_pixel(t_globals *globals, t_point point)
{
	int	pixel;
	int	alpha;

	alpha = 0;
	if (point.axis[X_AXIS] < )
}
