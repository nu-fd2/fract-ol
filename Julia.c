/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/08 15:43:31 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	j_equation(t_data *data)
{
	double	itr;
	double	tmp;
	int32_t	shade;

	itr = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < 100)
	{
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

void	julia(double ncr, double nci, t_data *data)
{
	int	x;
	int	y;
	int32_t color;

	y = 0;
	if (ncr > 2.0000 || ncr < -2.0000 || nci > 2.0000 || nci < -2.0000)
		is_error(0);
	data->cr = ncr;
	data->ci = nci;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			data->zi = (y / (double)H) * (2 - (-2)) + (-2);
			data->zr = (x / (double)W) * (2 - (-2)) + (-2);
			color = j_equation(data);
			put(data->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->mlx, data->img, 0, 0);
}
