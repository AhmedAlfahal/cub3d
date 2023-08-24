/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:37:16 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/23 18:10:15 by aalfahal         ###   ########.fr       */
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
			rgb_to_int(0, 255, 255));
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
		if (ln->y_w != 63)
			ln->y_w += ln->ss;
	}
}

int	rgb_to_int(int red, int green, int blue)
{
	int	color;

	color = 0;
	color |= (int)(red) << 16;
	color |= (int)(green) << 8;
	color |= (int)(blue);
	return (color);
}

void	line_loop(t_cub3d *c, t_line *ln, int line_color)
{
	while (1)
	{
		if (ln->x0 < 0 || ln->x0 >= (WIDTH)
			|| ln->y0 < 0 || ln->y0 >= (HIGHT))
			break ;
		my_mlx_pixel_put(c->img, ln->x0, ln->y0, line_color);
		if (ln->x0 == ln->x1 && ln->y0 == ln->y1)
			break ;
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
	ln.ss = 64.0 / c->map->l_rh;
	ln.y_w = ln.lof * ln.ss;
	line_loop_w(c, &ln, txtr);
}
