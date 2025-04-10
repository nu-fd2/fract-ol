/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 21:24:36 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/10 01:59:46 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>

# define W 800
# define H 800
# define MI 25

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		zoom;
	char		s;
}				t_data;

double			ft_atod(char *arg);
void			is_error(void);
void			mandelbrot(t_data *data);
void			julia(t_data *data);
void			do_fractol(int ac, char **av, t_data *data);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif // FRACTOL_H
