/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:07:13 by moabdels          #+#    #+#             */
/*   Updated: 2024/11/21 12:31:36 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_F
# define FDF_H

#include "mlx_linux/mlx.h"

typedef struct s_img_data
{
	void	*img;
	char	*address;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

void	ft_pixel_put(t_img_data *data, int x, int y, int color);

#endif
