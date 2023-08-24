/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:03:22 by hmohamed          #+#    #+#             */
/*   Updated: 2023/08/24 16:14:44 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	hor_extra(t_cub3d *c, t_line *hln)
{
	if (c->map->r_angel == 0 || c->map->r_angel == M_PI)
	{
		c->map->h_x = c->map->p_x;
		c->map->h_y = c->map->p_y;
		hln->dof = 100;
	}
	while (hln->dof != 100)
	{
		if (c->map->h_x < 0 || c->map->h_x >= (c->map->map_width * 64)
			|| c->map->h_y < 0 || c->map->h_y >= (c->map->map_height * 64))
			break ;
		if (c->map->map[(int) c->map->h_y / 64][(int) c->map->h_x / 64] == '1')
			break ;
		else
		{
			c->map->h_x += hln->l_rdx;
			c->map->h_y += hln->l_rdy;
			hln->dof++;
		}
	}
}

static void	ver_extra(t_cub3d *c, t_line *vln)
{
	if (c->map->r_angel == M_PI / 2
		|| c->map->r_angel == 3 * M_PI / 2)
	{
		c->map->v_x = c->map->p_x;
		c->map->v_y = c->map->p_y;
		vln->dof = 100;
	}
	while (vln->dof != 100)
	{
		if (c->map->v_x < 0 || c->map->v_x >= (c->map->map_width * 64)
			|| c->map->v_y < 0 || c->map->v_y >= (c->map->map_height * 64))
			break ;
		if (c->map->map[(int) c->map->v_y / 64][(int) c->map->v_x / 64] == '1')
			break ;
		else
		{
			c->map->v_x += vln->l_rdx;
			c->map->v_y += vln->l_rdy;
			vln->dof++;
		}
	}
}

void	draw_lines_ex(t_cub3d *c, int line_color)
{
	(void)line_color;
	if (c->map->v_len < c->map->h_len)
	{
		c->map->x_w = (int)c->map->v_y % 64;
		c->map->dest = c->map->v_len;
		if ((c->map->r_angel < 3 * (M_PI / 2) && c->map->r_angel > M_PI / 2))
			draw_3dmap_lines(c, &c->map->ea_tx);
		else
			draw_3dmap_lines(c, &c->map->we_tx);
	}
	else
	{
		c->map->x_w = (int)c->map->h_x % 64;
		c->map->dest = c->map->h_len;
		if (c->map->r_angel > 0 && c->map->r_angel < M_PI)
			draw_3dmap_lines(c, &c->map->no_tx);
		else
			draw_3dmap_lines(c, &c->map->so_tx);
	}
}

double	hor_line(t_cub3d *c)
{
	t_line	hln;
	double	len;

	c->map->h_x = c->map->p_x;
	c->map->h_y = c->map->p_y;
	hln.atan = 1 / tan(c->map->r_angel);
	hln.dof = 0;
	if (c->map->r_angel < M_PI)
	{
		c->map->h_y = (((int)c->map->p_y >> 6) << 6) - 0.0001;
		c->map->h_x = (c->map->p_y - c->map->h_y) * hln.atan + c->map->p_x;
		hln.l_rdy = -64;
		hln.l_rdx = -hln.l_rdy * hln.atan;
	}
	if (c->map->r_angel > M_PI)
	{
		c->map->h_y = (((int)c->map->p_y >> 6) << 6) + 64;
		c->map->h_x = (c->map->p_y - c->map->h_y) * hln.atan + c->map->p_x;
		hln.l_rdy = 64;
		hln.l_rdx = -hln.l_rdy * hln.atan;
	}
	hor_extra(c, &hln);
	len = sqrt(((c->map->h_x - c->map->p_x) * (c->map->h_x - c->map->p_x))
			+ ((c->map->h_y - c->map->p_y) * (c->map->h_y - c->map->p_y)));
	return (len);
}

double	ver_line(t_cub3d *c)
{
	t_line	vln;
	double	len;

	vln.ntan = tan(c->map->r_angel);
	vln.dof = 0;
	if (c->map->r_angel > M_PI / 2
		&& c->map->r_angel < 3 * M_PI / 2)
	{
		c->map->v_x = (((int)c->map->p_x >> 6) << 6) - 0.0001;
		c->map->v_y = (c->map->p_x - c->map->v_x) * vln.ntan + c->map->p_y;
		vln.l_rdx = -64;
		vln.l_rdy = -vln.l_rdx * vln.ntan;
	}
	if (c->map->r_angel < M_PI / 2
		|| c->map->r_angel > 3 * M_PI / 2)
	{
		c->map->v_x = (((int)c->map->p_x >> 6) << 6) + 64;
		c->map->v_y = (c->map->p_x - c->map->v_x) * vln.ntan + c->map->p_y;
		vln.l_rdx = 64;
		vln.l_rdy = -vln.l_rdx * vln.ntan;
	}
	ver_extra(c, &vln);
	len = sqrt(((c->map->v_x - c->map->p_x) * (c->map->v_x - c->map->p_x))
			+ ((c->map->v_y - c->map->p_y) * (c->map->v_y - c->map->p_y)));
	return (len);
}
