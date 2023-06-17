/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/17 23:02:48 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_object(t_cub3d *c, int pix_y, int color)
{
	static int	pix_x;

	if (pix_x == (c->map->j * 64) + 63 && pix_y == (c->map->i * 64) + 63)
	{
		pix_x = 0;
		return ;
	}
	if (pix_x == 0 || pix_x == (c->map->j * 64) + 63)
	{
		pix_x = (c->map->j * 64);
		pix_y++;
	}
	my_mlx_pixel_put(c->img, pix_x++, pix_y, color);
	draw_object(c, pix_y, color);
}

void	draw_player(t_cub3d *c, int color)
{
	
}

void	draw_map(t_cub3d *c)
{
	if (c->map->map[c->map->i][c->map->j] == 0)
	{
		c->map->j = 0;
		c->map->i++;
	}
	if (c->map->map[c->map->i] == NULL)
		return ;
	if (c->map->map[c->map->i][c->map->j] == '1')
		draw_object(c, c->map->i * 64, rgb_to_int(c->map->f_c_rgb[c_r], \
		c->map->f_c_rgb[c_g], c->map->f_c_rgb[c_b]));
	else if (c->map->map[c->map->i][c->map->j] == '0' || c->map->map[c->map->i][c->map->j] == 'P')
		draw_object(c, c->map->i * 64, rgb_to_int(c->map->f_c_rgb[f_r], \
		c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]));
	draw_player(c, rgb_to_int(c->map->f_c_rgb[f_r], \
		c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]));
	c->map->j++;
	draw_map(c);
}
