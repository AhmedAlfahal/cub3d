/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:37:16 by aalfahal          #+#    #+#             */
/*   Updated: 2023/09/05 16:43:50 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	line_loop_w(t_cub3d *c, t_line *ln, t_img *txtr)
{
	while (1)
	{
		ln->p_o = (int)ln->y_w * txtr->line_length
			+ (int)c->map->x_w * (txtr->bits_per_pixel / 8);
		if (ln->x0 < 0 || ln->x0 >= (WIDTH) || ln->y0 < 0 || ln->y0 >= (HIGHT)
			|| (ln->x0 == ln->x1 && ln->y0 == ln->y1))
			break ;
		my_mlx_pixel_put(c->img, ln->x0, ln->y0,
			rgb_to_int((unsigned char)txtr->addr[ln->p_o + 2],
				(unsigned char)txtr->addr[ln->p_o + 1],
				(unsigned char)txtr->addr[ln->p_o]));
		ln->e2 = 2 * ln->err;
		if (ln->e2 > -ln->dy)
		{
			ln->err -= ln->dy;
			ln->x0 += ln->sx;
		}
		if (ln->e2 < ln->dx)
		{
			ln->err += ln->dx;
			ln->y0 += ln->sy;
		}
		if (ln->y_w != 127)
			ln->y_w += ln->ss;
	}
}

void	drawline3d_w(t_cub3d *c, int x1, int y1, t_img *txtr)
{
	t_line	ln;

	ln.x0 = c->map->x0;
	ln.y0 = c->map->y0;
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
	ln.lof = 0;
	if (c->map->l_rh > HIGHT)
		ln.lof = (c->map->l_rh - HIGHT) / 2;
	ln.ss = (double)txtr->height / c->map->l_rh;
	ln.y_w = ln.lof * ln.ss;
	line_loop_w(c, &ln, txtr);
}

void	draw_3dmap_lines_ex(t_cub3d *c, t_img *txtr)
{
	double	l_o;

	l_o = ((HIGHT) / 2) - c->map->l_h / 2;
	c->map->x0 = c->map->rray;
	c->map->y0 = l_o;
	drawline3d_w(c, c->map->rray, c->map->l_h + l_o, txtr);
	c->map->x0 = c->map->rray;
	c->map->y0 = 0;
	drawline3d(c, c->map->rray, l_o, rgb_to_int(c->map->f_c_rgb[c_r],
			c->map->f_c_rgb[c_g], c->map->f_c_rgb[c_b]));
	c->map->x0 = c->map->rray;
	c->map->y0 = c->map->l_h + l_o;
	drawline3d(c, c->map->rray, HIGHT, rgb_to_int(c->map->f_c_rgb[f_r],
			c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]));
}
