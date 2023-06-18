/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/18 19:24:52 by aalfahal         ###   ########.fr       */
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

static void	draw_line(t_cub3d *c, int line_color)
{
	static int	l_rx;
	static int	l_ry;

	if (l_rx == 0 && l_ry == 0)
	{
		l_rx = c->map->p_x;
		l_ry = c->map->p_y;
	}
	if (c->map->map[l_ry / 64][l_rx / 64] == '1')
	{
		l_rx = 0;
		l_ry = 0;
		return ;
	}
	if (c->map->angel == 0)
		my_mlx_pixel_put(c->img, l_rx++, l_ry, line_color);
	else if (c->map->angel == 90)
		my_mlx_pixel_put(c->img, l_rx, l_ry--, line_color);
	else if (c->map->angel == 180)
		my_mlx_pixel_put(c->img, l_rx--, l_ry, line_color);
	else if (c->map->angel == 270)
		my_mlx_pixel_put(c->img, l_rx, l_ry++, line_color);
	else if (c->map->angel >= 360)
		c->map->angel -= 360;
	else if (c->map->angel < 0)
		c->map->angel += 360;
	draw_line(c, line_color);
}

void	draw_player(t_cub3d *c, int color, int line_color)
{
	static int	p_rx;
	static int	p_ry;

	if (p_rx == c->map->p_x + 5 && p_ry == c->map->p_y + 5)
	{
		p_rx = 0;
		p_ry = 0;
		draw_line(c, line_color);
		return ;
	}
	if (p_rx == 0 && p_rx == 0)
	{
		p_rx = c->map->p_x;
		p_ry = c->map->p_y;
	}
	if (p_rx == c->map->p_x + 5)
	{
		p_rx = c->map->p_x;
		p_ry++;
	}
	my_mlx_pixel_put(c->img, p_rx++, p_ry, color);
	draw_player(c, color, line_color);
}

void	draw_map(t_cub3d *c)
{
	if (c->map->map[c->map->i][c->map->j] == 0)
	{
		c->map->j = 0;
		c->map->i++;
	}
	if (c->map->map[c->map->i] == NULL)
	{
		draw_player(c, rgb_to_int(255, 0, 0), rgb_to_int(128, 0, 128));
		return ;
	}
	if (c->map->map[c->map->i][c->map->j] == '1')
		draw_object(c, c->map->i * 64, rgb_to_int(c->map->f_c_rgb[c_r], \
		c->map->f_c_rgb[c_g], c->map->f_c_rgb[c_b]));
	else if (c->map->map[c->map->i][c->map->j] == '0' \
	|| c->map->map[c->map->i][c->map->j] == 'P')
		draw_object(c, c->map->i * 64, rgb_to_int(c->map->f_c_rgb[f_r], \
		c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]));
	c->map->j++;
	draw_map(c);
}
