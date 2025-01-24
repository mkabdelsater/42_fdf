/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:01:27 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 14:27:21 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
 #define RENDERING_H

t_point	project_point(float matrix[3][3], t_point point);
void	rotate_along_axis(t_point *points, t_point *projection, \
	float angle, int len, int axis);
void	orto_projection(t_point *points, t_point *projection, int len);
void	toggle_opacity(t_point *points, int len);
void	draw_background(t_globals *fdf, int bg_color, int menu_color);

void	parse_map_to_model(t_globals *fdf, t_point *projection);
int		render_model(t_globals *global_state, int fit);

#endif
