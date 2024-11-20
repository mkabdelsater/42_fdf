/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:56:27 by moabdels          #+#    #+#             */
/*   Updated: 2024/11/20 15:17:19 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define WIN_HEIGHT 600
#define WIN_WIDTH 800

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	img.address = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
		&img.line_length, &img.endian);
	mlx_win = mlx_new_window(mlx, WIN_HEIGHT, WIN_WIDTH, "FdF");
	(void)mlx_win;
	mlx_loop(mlx);
}
