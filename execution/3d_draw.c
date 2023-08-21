/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:23:49 by hmohamed          #+#    #+#             */
/*   Updated: 2023/08/21 22:21:37 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texture(t_cub3d *c)
{
	//printf("%s\n", c->map->textures[no] + 2);
	c->map->no_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,  c->map->textures[no], &c->map->no_tx.width, &c->map->no_tx.height);
	c->map->so_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,  c->map->textures[so], &c->map->so_tx.width, &c->map->so_tx.height);
	if (c->map->no_tx.img == NULL || !c->map->so_tx.img) 
	{
		write(1, "ERRRRRRRRor\n", 13);
		return ;
	}
	c->map->no_tx.addr = mlx_get_data_addr(c->map->no_tx.img, &c->map->no_tx.bits_per_pixel, \
	&c->map->no_tx.line_length, &c->map->no_tx.endian);
	c->map->so_tx.addr = mlx_get_data_addr(c->map->so_tx.img, &c->map->so_tx.bits_per_pixel, \
	&c->map->so_tx.line_length, &c->map->so_tx.endian);
}

void	drawline3d(t_cub3d *c, int x1, int y1, int line_color)
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
	line_loop(c, &ln, line_color);
}

void	draw_3dmap_lines(t_cub3d *c, t_img *txtr)
{
	double	l_o;
	double	nangle;

	nangle = deg_to_rad(c->map->angel) - c->map->r_angel;
	if (nangle < 0)
		nangle += 2 * M_PI;
	if (nangle > 2 * M_PI)
		nangle -= 2 * M_PI;
	c->map->dest = c->map->dest * cos(nangle);
	c->map->l_h = (64 * (HIGHT)) / c->map->dest;
	if (c->map->l_h > (HIGHT))
		c->map->l_h = HIGHT ;
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

void	draw_3dmap(t_cub3d *c)
{
	c->map->x_w = 0;
	c->map->l_h = 0;
	texture(c);
	draw_lines(c, rgb_to_int(128, 0, 128));
}
