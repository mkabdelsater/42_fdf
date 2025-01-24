/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:25:51 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/24 16:14:12 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

void	set_color(char *buffer, int endian, int color, int alpha);
int		gradient(int start_color, int end_color, int len, int pixels);
void	free_2d_vector(char **vec);
void	render_number(t_globals *fdf, int x_coord, int y_coord, int nbr);
void	render_string(t_globals *fdf, int x_coord, int y_coord, char *str);

#endif
