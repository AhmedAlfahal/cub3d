/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:23:49 by hmohamed          #+#    #+#             */
/*   Updated: 2023/07/28 17:06:45 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	draw_3dmap_lines(t_cub3d *c, int line_color)
{
	double	l_h;

	l_h = (64 * (c->map->map_height * 64)) / c->map->dest;
	if (l_h > (c->map->map_height * 64))
		l_h = c->map->map_height * 64;
	ft_putnbr(l_h);write (1,"\n\n", 2);
	c->map->x0 = c->map->rray;
	c->map->y0 = 150;
	drawline3d(c, c->map->rray,  l_h, line_color);
}

void	draw_3dmap(t_cub3d *c)
{
	draw_lines(c, rgb_to_int(128, 0, 128));
}