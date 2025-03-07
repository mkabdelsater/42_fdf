/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:17 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/28 15:26:47 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLING_H
# define INPUT_HANDLING_H

void	modify_angle(float *angle, float mod);
void	rotation_control(int key, t_globals *fdf);
void	swap_color_scheme(int key, t_map *map);

int		on_key_down(int key, void *param);
int		on_key_release(int key, void *param);

int		on_mouse_move(int x, int y, void *param);
int		on_mouse_btn_release(int button, int x, int y, void *param);
int		on_mouse_btn_press(int button, int x, int y, void *param);

#endif
