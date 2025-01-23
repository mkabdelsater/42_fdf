/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:47:45 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/23 15:10:51 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/utils.h"

static void	set_point_color(int max, int min, t_point *point, t_colors colors)
{
	point->painted = true;
	point->color = DEFAULT_COLOR;
	if (point->color_hex > 0)
	{
		point->color = point->color_hex;
		return ;
	}
	if (point->axis[Z_AXIS] == max)
		point->color = colors.top;
	else if (point->axis[Z_AXIS] == 0)
		point->color = colors.ground;
	else if (point->axis[Z_AXIS] == min && min != 0)
		point->color = colors.bottom;
	else if (point->axis[Z_AXIS] > 0)
		point->color = gradient(colors.ground, colors.top, \
		max, point->axis[Z_AXIS]);
	else
		point->color = gradient(colors.bottom, colors.ground, \
			-min, - (min - point->axis[Z_AXIS]));
}

int	get_point_color(char *line)
{
	char	**vec;
	int		color;

	if (ft_strchr(line, ',') != 0)
	{
		vec = ft_split(line, ',');
		color = strtol(vec[1] + 2, NULL, 16);
		free_2d_vector(vec);
		return (color);
	}
	return (0);
}

void	color_map_points(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		set_point_color((int)map->limits.axis[Z_AXIS], map->z_min, \
		&map->points[i], map->colors);
		i++;
	}
}

bool	is_valid_point(char *value)
{
	int	i;

	i = 0;
	if (value[i] != '-' && value[i] != '+' && !ft_isdigit(value[i]))
		return (false);
	i++;
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (false);
		i++;
	}
	return (true);
}

void	duplicate_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}
