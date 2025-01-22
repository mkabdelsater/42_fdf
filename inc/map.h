/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:23:21 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/22 11:45:10 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../inc/fdf.h"

int		render_model(t_globals *global_state, int fit);
void	draw_menu(t_globals *fdf);
void	load_map(t_map *map, char *path);
// void	draw_background(t_globals *global_state, int bg_color, int menu_color);
void	draw_menu(t_globals *global_state);
void	set_point_color(int max, int min, t_point *point, t_colors colors);
void	color_map_points(t_map *map);
void	generate_stars(t_globals *global_state);
void	map_init(t_map *map, bool is_first_init);

// ? Map Utils
bool	is_valid_point(char *value);
int		get_point_color(char *line);

#endif
