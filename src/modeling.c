/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modeling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:38:37 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/10 14:03:57 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"
#include "../inc/map.h"
#include "../inc/geometry.h"
#include "../inc/utils.h"
#include <time.h>

int	draw_model(t_globals *global_state, int fit)
{
	t_point *projection;
	clock_t	t;

	t = clock();
	projection = malloc(global_state->map.len * sizeof(t_point));
	if (projection == NULL)
		error_out("Failed Alocating memory for projected map in draw_model()");
	global_state->map.renders = global_state->map.renders + 1;
	generate_background(global_state, global_state->map.colors.back, \
		global_state->map.colors.menu);
	copy_map(global_state->map.points, projection, global_state->map.len);
	parse_map_to_model(global_state, projection);
	drawing(global_state, projection, fit);
	mlx_put_image_to_window(global_state->mlx, global_state->win, \
		global_state->bitmap.img, 0, 0);
	draw_menu(global_state);
	free(projection);
	t = clock() - t;
	global_state->map.performance = ((double)t) / CLOCKS_PER_SEC;
	return (1);
}
