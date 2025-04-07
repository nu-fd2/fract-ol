/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/07 19:37:45 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int32_t color;

	y = 0;
	while (y < H)
	{
		x = 0;
		data->ci = (y / (double)H) * (2 - (-2)) + (-2);
		while (x < W)
		{
			data->cr = (x / (double)W) * (2 - (-2) + (-2));
			color = equation(data);
			mlx_put_pixel(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
