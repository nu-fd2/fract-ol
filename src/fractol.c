/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:03 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 02:00:00 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h" 

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 1)
		is_error();
	data.ci = 0;
	data.cr = 0;
	data.zoom = 1;
	data.mlx = mlx_init(W, H, av[1], false);
	data.img = mlx_new_image(data.mlx, W, H);
	do_fractol(ac, av, &data);
	mlx_loop(data.mlx);
}
