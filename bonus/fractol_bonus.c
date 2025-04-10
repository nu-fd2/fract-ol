/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:03 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 00:46:51 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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
	if (data.img)
		mlx_delete_image(data.mlx, data.img);
	if (data.mlx)
		mlx_terminate(data.mlx);
}
