/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:47:45 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/06 15:52:32 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	get_point_color(char *line)
{
	char	**vec;
	int		color;

	if (ft_strchr(line, ',') != 0)
	{
		vec = ft_split(line, ',');
		color = strtol(vec[1] + 2, NULL, 16);
		free_2d_vec(vec);
		return (color);
	}
	return (0);
}
