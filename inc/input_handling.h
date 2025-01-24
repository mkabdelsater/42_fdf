/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:42:17 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 14:15:55 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HANDLING_H
# define INPUT_HANDLING_H

void	modify_angle(float *angle, float mod);
void	rotation_control(int key, t_globals *fdf);
int		on_key_down(int key, void *param);
int		on_key_release(int key, void *param);

#endif
