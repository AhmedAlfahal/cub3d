/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:37:16 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/21 22:23:26 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	line_loop_w(t_cub3d *c, t_line *ln, t_img *txtr)
{
	//double		x_w;
	double		y_w;
	int			p_o;
	double		ss;

	if((ln->y1 - ln->y0) > HIGHT)
		y_w = (ln->y1 - ln->y0) - HIGHT;
	else
		y_w = 0;
	// x_w = ln->x1 % 64;
	//ss = (ln->y1 - ln->y0) / 64;
	ss = 64.0 / c->map->l_h;
	// ft_putnbr(ln->y1 - ln->y0);
	// write(1, "\n",1);
	while (1)
	{
		p_o = (int)y_w * txtr->line_length + (int)c->map->x_w * (txtr->bits_per_pixel / 8);
		if (ln->x0 < 0 || ln->x0 >= (WIDTH)
			|| ln->y0 < 0 || ln->y0 >= (HIGHT))
			break;
		my_mlx_pixel_put(c->img, ln->x0, ln->y0, 
			rgb_to_int((unsigned char)txtr->addr[p_o + 2],
				(unsigned char)txtr->addr[p_o + 1], (unsigned char)txtr->addr[p_o]));
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
		if (y_w != 63)
			y_w += ss;
	}
	//x_w++;
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
	line_loop_w(c, &ln, txtr);
}
