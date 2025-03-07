/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:23:21 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 14:27:09 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../inc/fdf.h"

void	draw_menu(t_globals *fdf);
void	load_map(t_map *map, char *path);
// void	draw_background(t_globals *global_state, int bg_color, int menu_color);
void	draw_menu(t_globals *global_state);
void	color_map_points(t_map *map);
void	generate_stars(t_globals *global_state);
void	map_init(t_map *map, bool is_first_init);
void	set_view_to_isometric(t_map *map);

// ? Map Utils
bool	is_valid_point(char *value);
int		get_point_color(char *line);
void	duplicate_map(t_point *src, t_point *dst, int len);

#endif
