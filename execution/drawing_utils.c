/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/20 12:26:36 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_object(t_cub3d *c, int pix_y, int color)
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

static void	draw_line_cons(t_cub3d *c, int *angel, double *l_rx, double *l_ry)
{
	if (*angel == 0)
		*angel = c->map->angel - 22;
	if (*l_rx == 0 && *l_ry == 0)
	{
		*l_rx = c->map->p_x;
		*l_ry = c->map->p_y;
	}
}

static void	draw_line(t_cub3d *c, int line_color)
{
	static double	l_rx;
	static double	l_ry;
	static int		angel;

	draw_line_cons(c, &angel, &l_rx, &l_ry);
	if (c->map->map[(int) l_ry / 64][(int) l_rx / 64] == '1')
	{
		l_rx = 0;
		l_ry = 0;
		if (angel <= c->map->angel + 22)
		{
			angel++;
			if (angel == 0)
				angel++;
			return (draw_line(c, line_color));
		}
		angel = 0;
		return ;
	}
	l_ry -= sin(deg_to_rad(angel));
	l_rx += cos(deg_to_rad(angel));
	my_mlx_pixel_put(c->img, l_rx, l_ry, line_color);
	draw_line(c, line_color);
}

static void	draw_player(t_cub3d *c, int color, int line_color)
{
	static double	p_rx;
	static double	p_ry;

	if ((int) p_rx == (int) c->map->p_x + 5 \
	&& (int) p_ry == (int) c->map->p_y + 5)
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
