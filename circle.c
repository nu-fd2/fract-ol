#include "fractol.h"

void	draw_circle(t_data *data, int cx, int cy, int r, uint32_t color)
{
	int x = 0;
	int y = r;
	int d = 1 - r;

	while (x <= y)
	{
		put_pixel(data->img, cx + x, cy + y, color);
		put_pixel(data->img, cx - x, cy + y, color);
		put_pixel(data->img, cx + x, cy - y, color);
		put_pixel(data->img, cx - x, cy - y, color);
		put_pixel(data->img, cx + y, cy + x, color);
		put_pixel(data->img, cx - y, cy + x, color);
		put_pixel(data->img, cx + y, cy - x, color);
		put_pixel(data->img, cx - y, cy - x, color);

		x++;
		if (d < 0)
			d += 2 * x + 1;
		else
		{
			y--;
			d += 2 * (x - y) + 1;
		}
	}
}