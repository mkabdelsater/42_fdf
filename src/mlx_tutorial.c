#include "../inc/mlx_tutorial.h"

static int	draw_line(void *mlx, void *win, int beginX, int beginY,\
	int endX, int endY, int color)
{
	int		result = 0;
	double	deltaX = endX - beginX;
	double	deltaY = endY - beginY;

	int pixels = sqrt((deltaX * deltaY) + (deltaY * deltaY));

	deltaX /= pixels;
	deltaY /= pixels;

	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels--)
	{
		result += mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
	}

	return (result);
}

int	main()
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 640, 360, "Tutorial Window");
	draw_line(mlx, win, 640, 360, 0, 0, 0xFFFFFF);
	mlx_loop(mlx);
}

