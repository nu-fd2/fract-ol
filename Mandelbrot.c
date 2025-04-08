/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/08 21:51:44 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	m_equation(t_data *data)
{
	double	itr;
	double	tmp;
	int32_t	shade;

	itr = 0;
	data->zr = 0;
	data->zi = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < 10)
	{
		data->zr = fabs(data->zr);
		data->zi = fabs(data->zi);
		tmp = (data->zr * data->zr) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zr * data->zi) + data->ci;
		data->zr = tmp;
		itr = itr + 0.5;
	}
	if (itr >= (double)10)
		return (0x000000FF);
	shade = 255 * (itr / 10);
	return (shade << 24) | 0x000000FF;
}

void	mandelbrot(t_data *data)
{
	int	x;
	int	y;
	int32_t color;

	y = 0;
	while (y < H)
	{
		x = 0;
		data->ci = (((y / (double)H) * 4) - 2) * data->zoom;
		while (x < W)
		{
			data->cr = (((x / (double)W) * 4) - 2) * data->zoom;
			color = m_equation(data);
			put(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
