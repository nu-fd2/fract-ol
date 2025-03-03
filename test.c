#include "minilibx_opengl_20191021/mlx.h"

#define WIDTH 500
#define HEIGHT 500

void	draw_square(char *data, int size_line, int bpp)
{
	int x, y;
	int square_size = 100; // Size of the square

	for (y = 100; y < 100 + square_size; y++) // Square position
	{
		for (x = 100; x < 100 + square_size; x++)
		{
			int pixel = (y * size_line) + (x * (bpp / 8));
			data[pixel] = (char)255;       // Blue
			data[pixel + 1] = 0;     // Green
			data[pixel + 2] = 0;     // Red
		}
	}
}

int	main(void)
{
	void	*mlx, *win, *img;
	char	*data;
	int		bpp, size_line, endian;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Square");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	data = mlx_get_data_addr(img, &bpp, &size_line, &endian);

	draw_square(data, size_line, bpp);
	mlx_put_image_to_window(mlx, win, img, 0, 0);

	mlx_loop(mlx);
	return (0);
}
