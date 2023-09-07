/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/09/03 22:26:17 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	draw_lines(t_cub3d *c)
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
		draw_lines_ex(c);
		c->map->r_angel += 0.000173;
		c->map->rray += 0.3;
	}
}

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

int	rgb_to_int(int red, int green, int blue)
{
	int	color;

	color = 0;
	color |= (int)(red) << 16;
	color |= (int)(green) << 8;
	color |= (int)(blue);
	return (color);
}
