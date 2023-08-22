/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/21 20:57:25 by hmohamed         ###   ########.fr       */
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

void	drawline(t_cub3d *c, int x1, int y1, int line_color)
{
	t_line	ln;

	ln.x0 = c->map->p_x;
	ln.y0 = c->map->p_y;
	ln.dx = abs(x1 - ln.x0);
	ln.dy = abs(y1 - ln.y0);
	if (ln.x0 < x1)
		ln.sx = 1;
	else
		ln.sx = -1;
	if (ln.y0 < y1)
		ln.sy = 1;
	else
		ln.sy = -1;
	ln.err = ln.dx - ln.dy;
	ln.x1 = x1;
	ln.y1 = y1;
	line_loop(c, &ln, line_color);
}

void	draw_lines(t_cub3d *c, int line_color)
{
	double	fov;

	c->map->rray = 0;
	fov = deg_to_rad(c->map->angel + 30);
	c->map->r_angel = deg_to_rad(c->map->angel - 30);
	while (c->map->rray < WIDTH)
	{
		if (c->map->r_angel > 2 * M_PI)
		{
			fov = fov - 2 * M_PI;
			c->map->r_angel = c->map->r_angel - 2 * M_PI;
		}
		else if (c->map->r_angel <= 0)
		{
			fov = fov + 2 * M_PI;
			c->map->r_angel = c->map->r_angel + 2 * M_PI;
		}
		c->map->v_x = c->map->p_x;
		c->map->v_y = c->map->p_y;
		c->map->v_len = ver_line(c);
		c->map->h_len = hor_line(c);
		draw_lines_ex(c, line_color);
		c->map->r_angel += 0.000173;
		c->map->rray += 0.3;
	}
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
		draw_lines(c, line_color);
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
