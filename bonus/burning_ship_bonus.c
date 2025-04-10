/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:48 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/09 23:16:34 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int32_t	b_equation(t_data *data)
{
	double	itr;
	double	tmp;
	int32_t	shade;

	itr = 0;
	data->zr = 0;
	data->zi = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < MI)
	{
		data->zr = fabs(data->zr);
		data->zi = fabs(data->zi);
		tmp = (data->zr * data->zr) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zr * data->zi) + data->ci;
		data->zr = tmp;
		itr = itr + 1;
	}
	if (itr >= (double)MI)
		return (0x000000FF);
	shade = 255 * (itr / MI);
	shade = (shade << 24) | 0x000000FF;
	return (shade);
}

void	burning_ship(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < H)
	{
		x = 0;
		data->ci = (((y / (double)H) * 4) - 2) * data->zoom;
		while (x < W)
		{
			data->cr = (((x / (double)W) * 4) - 2) * data->zoom;
			if (x >= 0 && x < W && y >= 0 && y < H)
				mlx_put_pixel(data->img, x, y, b_equation(data));
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
