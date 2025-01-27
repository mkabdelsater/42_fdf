/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 14:58:37 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/27 14:23:39 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

void	set_polar_coords(t_map *map);
void	set_projection_matrix(float (*matrix)[3], int axis, float angle);
t_point	project_point(float matrix[3][3], t_point point);
void	project_x(t_point *point, t_point *projected, float ang, int len);
void	project_y(t_point *point, t_point *projected, float ang, int len);
void	project_z(t_point *point, t_point *projected, float ang, int len);

#endif
