/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:19:28 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 01:33:54 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	hoo(mlx_key_data_t keydata, void *param)
{
	t_data	*bruh;

	bruh = (t_data *)param;
	if (keydata.action == MLX_PRESS)
		if (keydata.key == MLX_KEY_ESCAPE)
			exit (0);
}

void	scroller(double xdelta, double ydelta, void *param)
{
	t_data	*bruh;

	(void)xdelta;
	bruh = (t_data *)param;
	if (ydelta > 0)
		bruh->zoom *= 1.1;
	else if (ydelta < 0)
		bruh->zoom *= 0.9;
	else
		return ;
	if (bruh->s == 'm')
		mandelbrot(bruh);
	else if (bruh->s == 'j')
		julia(bruh);
	else if (bruh->s == 'b')
		burning_ship(bruh);
}

void	do_fractol(int ac, char **av, t_data *data)
{
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11)))
	{
		data->s = 'm';
		mandelbrot(data);
	}
	else if ((ac == 2 && !ft_strncmp(av[1], "burning_ship", 13)))
	{
		data->s = 'b';
		burning_ship(data);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
	{
		data->s = 'j';
		data->cr = ft_atod(av[2]);
		data->ci = ft_atod(av[3]);
		julia(data);
	}
	else
		is_error();
	mlx_key_hook(data->mlx, hoo, data);
	mlx_scroll_hook(data->mlx, scroller, data);
}
