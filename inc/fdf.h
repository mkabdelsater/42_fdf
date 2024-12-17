/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:55:52 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/17 12:41:42 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "../lib/minilibx_linux/mlx.h"
#include "../lib/libft/libft.h"
#include <math.h>
#include <stdbool.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define X_AXIS 0
# define Y_AXIS 1
# define Z_AXIS 2

typedef struct s_point {
	bool	painted;
	int		color_hex;
	int		color;
	float	axis[3];
	float	polar[2];
}	t_point;

bool	point_is_in_window(t_point point);

#endif
