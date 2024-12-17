/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:55:52 by moabdels          #+#    #+#             */
/*   Updated: 2024/12/17 13:53:36 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx_linux/mlx.h"
# include "../lib/libft/libft.h"
# include <math.h>
# include <stdbool.h>

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define X_AXIS		0
# define Y_AXIS		1
# define Z_AXIS		2
# define MENU_WIDTH	350
# define FIT_MARGIN	50
# define FIT		1
# define FREE		0

typedef struct s_point {
	bool	painted;
	int		color_hex;
	int		color;
	float	axis[3];
	float	polar[2];
}	t_point;

typedef struct s_colors
{
	int	top;
	int	ground;
	int	bottom;
	int	back;
	int	menu;
}	t_colors;

typedef struct s_bitmap
{
	void	*img;
	char	*buffer;
	int		bit_x_pixel;
	int		lines;
	int		endian;
}	t_bitmap;

typedef struct s_keys
{
	bool	b_mouse_l;
	bool	b_mouse_r;
	bool	b_key_ctrl;
	t_point	last_click_l;
	t_point	last_click_r;
}	t_keys;

typedef struct s_map
{
	t_point		*points;
	t_point		limits;
	t_point		source;
	t_colors	colors;
	double		performance;
	float		ang[3];
	float		z_divisor;
	float		scale;
	float		b_range;
	float		proportion;
	float		radius;
	int			zmin;
	int			len;
	int			renders;
	char		*memory;
	char		**lines;
	bool		b_lines;
	bool		b_dots;
	bool		b_pluslines;
	bool		b_geo;
	bool		b_stars;
	bool		b_shadow;
}	t_map;

typedef struct s_globals
{
	void		*mlx;
	void		*win;
	t_bitmap	bitmap;
	t_map		map;
	t_keys		keys;
}	t_globals;

bool	point_is_in_window(t_point point);
int		my_putpixel(t_globals *meta, t_point point);


#endif
