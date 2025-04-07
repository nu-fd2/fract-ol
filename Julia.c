/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-mado <oel-mado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 01:05:07 by oel-mado          #+#    #+#             */
/*   Updated: 2025/04/07 10:04:38 by oel-mado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(double cr, double ci, t_data *data)
{
	if (cr > 2.0000 || cr < -2.0000 || ci > 2.0000 || ci < -2.0000)
		is_error(0);
}
