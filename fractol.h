/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/06 06:03:54 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#include <math.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#include <stdio.h>

#define W 800
#define H 800

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t *img;
	int			x;
	int			y;
}				t_data;

typedef struct 	s_q
{
	double		r;
	double		i;
}				t_q;


void	is_error();
double	do_atob(char *arg);
void	mandelbrot();
void	julia(double cr, double ci);

void 	draw_circle(t_data *data, int cx, int cy, int r, uint32_t color);
void 	put_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void	fill_screen(t_data *data);


#endif //FRACTOL_H
