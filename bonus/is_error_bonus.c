/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 04:16:22 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 01:01:27 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	is_error(void)
{
	write(1, "\033[1;33mTry:\033[0m\n", 16);
	write(1, "\033[1;32m./fractol mandelbrot\033[0m\n", 32);
	write(1, "\033[1;33mOr:\033[0m\n", 15);
	write(1, "\033[1;32m./fractol_bonus burning_ship\033[0m\n", 40);
	write(1, "\033[1;33mOr:\033[0m\n", 15);
	write(1, "\033[1;32m./fractol julia <0.001> <0.8>\033[0m\n", 41);
	write(1, "\033[1;32m./fractol julia <r> <i>\033[0m\n", 40);
	write(1, "\033[1;32m-2 < r < 2 and -2 < i < 2\033[0m\n", 32);
	exit(1);
}
