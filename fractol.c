/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:03 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/05 15:22:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		if (!ft_strncmp(av[1], "Mandelbrot", 11)
			|| !ft_strncmp(av[1], "mandelbrot", 11))
			mandelbrot();
		else if (!ft_strncmp(av[1], "Julia", 6)
			|| !ft_strncmp(av[1], "julia", 6))
			
	}
}





