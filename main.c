/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 04:14:31 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/06 04:14:41 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	double	cr;
	double	ci;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		mandelbrot();
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		julia(do_atod(av[2]), do_atod(av[3]));
	else
		is_error();
}
