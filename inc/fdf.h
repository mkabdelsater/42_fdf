/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabdels <moabdels@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:55:52 by moabdels          #+#    #+#             */
/*   Updated: 2025/01/23 14:29:48 by moabdels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/minilibx_linux/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include <math.h>
# include <stdbool.h>
# include <fcntl.h>

// ! There's minor spaghettification with the include files but this project
// ! has taken way too much time already, you'll need to clean this up

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080
# define X_AXIS		0
# define Y_AXIS		1
# define Z_AXIS		2
# define MENU_WIDTH	350
# define FIT_MARGIN	50
# define FIT		1
# define FREE		0
# define LAT		0
# define LONG		1

# define FIREBRICK_RED	0xc1272d
# define LIME_GREEN		0x33cc55
# define CRIMSON 		0xff255c
# define DODGER_BLUE	0x1B8EFA
# define BLUE			0x0000FF
# define WOODSMOKE		0x151515
# define SILVER			0xBBBBBB
# define CARDINAL_PINK	0x9A1F6A
# define MAROON			0xC2294E
# define FLAMINGO		0xEC4B27
# define JAFFA			0xEF8633
# define TULIP_TREE		0xF3AF3D

# define DEFAULT_COLOR		JAFFA
# define BOTTOM_COLOR		DODGER_BLUE
# define TOP_COLOR			MAROON
# define GROUND_COLOR		TULIP_TREE
# define BACK_COLOR			WOODSMOKE
# define MENU_COLOR			0x202020
# define TEXT_COLOR			0xEAEAEA
# define NUMBER_COLOR		0xF3AF3D

# define DEF_COLOR	"\033[0;39m"
# define SH_GRAY	"\033[0;90m"
# define SH_RED		"\033[0;91m"
# define SH_GREEN	"\033[0;92m"
# define SH_YELLOW	"\033[0;93m"
# define SH_BLUE	"\033[0;94m"
# define SH_MAGENTA	"\033[0;95m"
# define SH_CYAN	"\033[0;96m"
# define SH_WHITE	"\033[0;97m"

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
	int			z_min;
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

// ? General Functionality
void	error_out(char *err_msg);
int		terminate(t_globals *fdf);

int		my_putpixel(t_globals *meta, t_point point);
int		draw_line(t_globals *globals, t_point start, t_point end);

#endif
