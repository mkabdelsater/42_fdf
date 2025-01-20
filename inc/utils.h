/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:51 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/20 15:24:32 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		gradient(int start_color, int end_color, int len, int pixels);
void	free_2d_vector(char **vec);
void	draw_number(t_globals *global_state, int x_coord, int y_coord, int nbr);
void	draw_string(t_globals *global_state, int x_coord, int y_coord, char *str);

#endif
