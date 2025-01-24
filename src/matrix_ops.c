/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:23:26 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 16:36:09 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

// ! TO_REFACTOR: put this into it's own file - matrix operations

static void	b_zero_matrix(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

static void	set_projection_matrix(float (*matrix)[3], int axis, float angle)
{
	b_zero_matrix(matrix);
	if (axis == X_AXIS)
	{
		matrix[0][0] = 1;
		matrix[1][1] = cos(angle);
		matrix[1][2] = -sin(angle);
		matrix[2][1] = sin(angle);
		matrix[2][2] = cos(angle);
	}
	else if (axis == Y_AXIS)
	{
		matrix[0][0] = cos(angle);
		matrix[0][2] = sin(angle);
		matrix[1][1] = 1;
		matrix[2][0] = -sin(angle);
		matrix[2][2] = cos(angle);
	}
	else
	{
		matrix[0][0] = cos(angle);
		matrix[0][1] = -sin(angle);
		matrix[1][0] = sin(angle);
		matrix[1][1] = cos(angle);
		matrix[2][2] = 1;
	}
}

t_point	project_point(float matrix[3][3], t_point point)
{
	int		i;
	int		j;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = point.color;
		j = 0;
		while (j < 3)
		{
			result.axis[i] += matrix[i][j] * point.axis[j];
			j++;
		}
		i++;
	}
	return (result);
}

void	rotate_along_axis(t_point *points, t_point *projection, \
	float angle, int len, int axis)
{
	int		i;
	float	projection_matrix[3][3];
	float	rad;

	rad = angle * M_PI / 180;
	set_projection_matrix(projection_matrix, axis, rad);
	i = 0;
	while (i < len)
	{
		projection[i] = project_point(projection_matrix, points[i]);
		i++;
	}
}

// !TO_RESEARCH : projection matrix value

void	orto_projection(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	b_zero_matrix(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = project_point(projection_matrix, points[i]);
		i++;
	}
}
