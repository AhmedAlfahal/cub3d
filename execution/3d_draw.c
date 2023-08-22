/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:23:49 by hmohamed          #+#    #+#             */
/*   Updated: 2023/08/22 22:12:00 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_lines(t_cub3d *c, int line_color)
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

static void	texture(t_cub3d *c)
{
	c->map->no_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,
			c->map->textures[no], &c->map->no_tx.width, &c->map->no_tx.height);
	c->map->so_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,
			c->map->textures[so], &c->map->so_tx.width, &c->map->so_tx.height);
	c->map->we_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,
			c->map->textures[we], &c->map->we_tx.width, &c->map->we_tx.height);
	c->map->ea_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,
			c->map->textures[ea], &c->map->ea_tx.width, &c->map->ea_tx.height);
	if (c->map->no_tx.img == NULL || c->map->so_tx.img == NULL
		|| c->map->we_tx.img == NULL || c->map->ea_tx.img == NULL)
		clean_exit(c, 3, 1);
	c->map->no_tx.addr = mlx_get_data_addr(c->map->no_tx.img,
			&c->map->no_tx.bits_per_pixel,
			&c->map->no_tx.line_length, &c->map->no_tx.endian);
	c->map->so_tx.addr = mlx_get_data_addr(c->map->so_tx.img,
			&c->map->so_tx.bits_per_pixel,
			&c->map->so_tx.line_length, &c->map->so_tx.endian);
	c->map->we_tx.addr = mlx_get_data_addr(c->map->we_tx.img,
			&c->map->we_tx.bits_per_pixel,
			&c->map->we_tx.line_length, &c->map->we_tx.endian);
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
	c->map->l_rh = c->map->l_h;
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
	c->map->l_rh = 0;
	texture(c);
	c->map->ea_tx.addr = mlx_get_data_addr(c->map->ea_tx.img,
			&c->map->ea_tx.bits_per_pixel,
			&c->map->ea_tx.line_length, &c->map->ea_tx.endian);
	draw_lines(c, rgb_to_int(128, 0, 128));
}
