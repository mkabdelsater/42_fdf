/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:06:02 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 14:30:21 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/geometry.h"

// THank you Norminette

void	project_x(t_point *point, t_point *projected, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	set_projection_matrix(projection_matrix, X_AXIS, rad);
	i = 0;
	while (i < len)
	{
		projected[i] = project_point(projection_matrix, point[i]);
		i++;
	}
}

void	project_y(t_point *point, t_point *projected, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	set_projection_matrix(projection_matrix, Y_AXIS, rad);
	i = 0;
	while (i < len)
	{
		projected[i] = project_point(projection_matrix, point[i]);
		i++;
	}
}

void	project_z(t_point *point, t_point *projected, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	rad = ang * M_PI / 180;
	set_projection_matrix(projection_matrix, Z_AXIS, rad);
	i = 0;
	while (i < len)
	{
		projected[i] = project_point(projection_matrix, point[i]);
		i++;
	}
}
