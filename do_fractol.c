/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:19:28 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/08 15:13:54 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_fractol(int ac, char **av, t_data *data)
{

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
		mandelbrot(data);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 6))
		julia(ft_atod(av[2]), ft_atod(av[3]), data);
	else
		is_error(1);
}
