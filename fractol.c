/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:03 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/07 19:29:00 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data  data;

	data.ci = 0;
	data.cr = 0;
	data.mlx = mlx_init(W, H, av[1], false);
	data.img = mlx_new_image(data.mlx, W, H);
	printf("\033[1;35mHi! :3\033[0m\n");
	do_fractol(ac, &av[1], &data);
	printf("\033[1;35mByyy :D\033[0m\n");
	mlx_loop(data.mlx);
}
