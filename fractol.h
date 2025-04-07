/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/07 19:21:36 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#include <stdio.h>

#define W 800
#define H 800

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t *img;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
}				t_data;

double	ft_atob(char *arg);
void	is_error(bool s);
void	mandelbrot(t_data *data);
void	julia(double cr, double ci, t_data *data);
void	do_fractol(int ac, char **av, t_data *data);
int32_t	equation(t_data *data);

void 	draw_circle(t_data *data, int cx, int cy, int r, uint32_t color);
void 	put_pixel(mlx_image_t *img, int x, int y, uint32_t color);


#endif //FRACTOL_H
