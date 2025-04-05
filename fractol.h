/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/05 15:16:51 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef FRACTOL_H
// #define FRACTOL_H

// #include <math.h>
// #include <fcntl.h>
#include "libft/libft.h"
// #include "MLX42/include/MLX42/MLX42.h"

// #endif //FRACTOL_H




#ifndef FRACTOL_H
#define FRACTOL_H

#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 800

typedef struct s_data
{
    mlx_t *mlx;
    mlx_image_t *img;
} t_data;

void draw_circle(t_data *data, int cx, int cy, int r, uint32_t color);
void put_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void	fill_screen(t_data *data);
#endif


