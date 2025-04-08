/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/08 21:47:42 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	j_equation(t_data *data)
{
	double	itr;
	double	tmp;
	int32_t	shade;

	itr = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < 180)
	{
		tmp = (data->zr * data->zr) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zr * data->zi) + data->ci;
		data->zr = tmp;
		itr = itr + 1;
	}
	shade = 255 * (itr / 180);
	if (itr >= (double)180)
	{
		shade = (itr / 180);
		return (shade << 8) | 0x000000FF;
	}
	return (shade << 24) | 0x000060FF;
	// 	double	t;
	// int		r, g, b;

	// t = itr / 180;
	// if (t > 1.0)
	// 	t = 1.0;
 
	// // Example gradient: from deep blue to purple to red to yellow to white
	// r = (int)(9 * (1 - t) * t * t * t * 255);
	// g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	// b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

	// return (255 << 24) | (r << 16) | (g << 8) | b;
}

void	julia(t_data *data)
{
	int	x;
	int	y;
	int32_t color;

	y = 0;
	if (data->cr > 2.0 || data->cr < -2.0 || data->ci > 2.0 || data->ci < -2.0)
		is_error(0);

	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			data->zi = (((y / (double)H) * 4) - 2) * data->zoom;
			data->zr = (((x / (double)W) * 4) - 2) * data->zoom;
			color = j_equation(data);
			put(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
