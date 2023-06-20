/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:07:21 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/20 12:20:55 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

double	deg_to_rad(double deg)
{
	return (deg * (M_PI / 180));
}

double	rad_to_deg(double rad)
{
	return (rad * (M_PI / 0x3F));
}
