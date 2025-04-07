/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:00:32 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/08 00:37:38 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int32_t	equation(t_data *data)
{
	double	itr;
	double	tmp;

	itr = 0;
	data->zr = 0;
	data->zi = 0;
	while ((data->zr * data->zr) + (data->zi * data->zi) < 5 && itr < 100)
	{
		tmp = (data->zr * data->zr) - (data->zi * data->zi) + data->cr;
		data->zi = (2 * data->zr * data->zi) + data->ci;
		data->zr = tmp;
		itr = itr + 0.5;
	}
	if (itr >= (double)100)
		return (0x000000FF);
	int shade = 255 * (itr / 10.0);
	return (shade << 24) | 0x00FFFFFF;
	// return (0xFFFFFFFF * (itr / 100));


}
