/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 01:23:45 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int32_t	j_equation(t_data *data)
{
	double	itr;
	double	tmp;
	int32_t	shade;

	itr = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < MI)
	{
		tmp = (data->zr * data->zr) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zr * data->zi) + data->ci;
		data->zr = tmp;
		itr = itr + 1;
	}
	if (itr >= (double)MI)
		return (0x000000FF);
	shade = 255 * (itr / MI);
	shade = (shade << 8) | 0x000000FF;
	return (shade);
}

void	julia(t_data *data)
{
	double	x;
	double	y;

	if (data->cr > 2.0 || data->cr < -2.0 || data->ci > 2.0 || data->ci < -2.0)
		is_error();
	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			data->zi = (((y / (double)H) * 4) - 2) * data->zoom;
			data->zr = (((x / (double)W) * 4) - 2) * data->zoom;
			if (x >= 0 && x < W && y >= 0 && y < H)
				mlx_put_pixel(data->img, x, y, j_equation(data));
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
