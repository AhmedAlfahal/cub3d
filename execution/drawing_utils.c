/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:17:29 by aalfahal          #+#    #+#             */
/*   Updated: 2023/07/20 19:25:13 by hmohamed         ###   ########.fr       */
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

static void	drawline(t_cub3d *c, int x1, int y1, int line_color)
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

static void	draw_lines(t_cub3d *c, int line_color)
{
	double	x;
	double	y;
	double	fov;

	fov = c->map->angel + 30;
	c->map->r_angel = c->map->angel - 30;
	while (c->map->r_angel < fov)
	{
		if (c->map->r_angel >= 360)
		{
			fov = fov - 360;
			c->map->r_angel = c->map->r_angel - 360;
		}
		else if(c->map->r_angel <= 0)
		{
			fov = fov + 360;
			c->map->r_angel = c->map->r_angel + 360;
		}
		c->map->v_x = c->map->p_x;
		c->map->v_y = c->map->p_y;
		x = ver_line(c);
		y = hor_line(c);
		if (x < y)
			drawline(c, c->map->v_x, c->map->v_y, line_color);
		else
			drawline(c, c->map->h_x, c->map->h_y, 0xFF0000);
		c->map->r_angel += 0.00973;
	}
}

// static void	draw_lines(t_cub3d *c, int line_color)
// {
// 	static double	l_rx;
// 	static double	l_rdx;
// 	static double	l_rdy;
// 	static double	l_ry;
// 	static double		angel;
// 	double 		fov;
// 	double 		f;

// 	f = 0;
// 	l_rx = c->map->p_x;
// 	l_ry = c->map->p_y;
// 	int dof;
// 	angel = deg_to_rad(c->map->angel - 30);
// 	fov = deg_to_rad(c->map->angel + 30);
// 	//Horizontal
	
// 	while (f < M_PI / 2)
// 	{
// 		if(angel >= 2 * M_PI)
// 		{
// 			angel = angel - 2 * M_PI;
// 		}
// 		else if(angel < 0)
// 		{
// 			angel = angel + 2 * M_PI;
// 		}
// 		double aTan = 1/tan(angel);
// 		dof = 0;
// 		if (angel < M_PI)
// 		{
// 			l_ry = (((int)c->map->p_y >> 6) << 6) - 0.0001;
// 			l_rx = (c->map->p_y - l_ry) * aTan + c->map->p_x;
// 			l_rdy = -64;
// 			l_rdx = -l_rdy * aTan;
// 		}
// 		if (angel > M_PI)
// 		{
// 			l_ry = (((int)c->map->p_y >> 6) << 6) + 64;
// 			l_rx = (c->map->p_y - l_ry) * aTan + c->map->p_x;
// 			l_rdy = 64;
// 			l_rdx = -l_rdy * aTan;
// 		}
// 		if(angel == 0 || angel == M_PI)
// 		{
// 			l_rx = c->map->p_x;
// 			l_ry = c->map->p_y;
// 			dof = 8;
// 		}
// 		while (dof < 8)
// 		{
// 			// ft_putnbr(c->map->map_width * 64);
// 			// write(1, "\n", 1);
// 			// ft_putnbr(c->map->map_height * 64);
// 			if (l_rx < 0 || l_rx >= (c->map->map_width * 64)
// 				|| l_ry < 0 || l_ry >= (c->map->map_height * 64))
// 				break ;
// 			if (c->map->map[(int) l_ry / 64][(int) l_rx / 64] == '1')
// 				dof = 8;
// 			else
// 			{
// 				//write(1,"helooo\n",8);
// 				l_rx += l_rdx;
// 				l_ry += l_rdy;
// 				dof++;
// 			}
// 		}
// 		ft_putnbr(c->map->angel);
// 		write(1, "\n", 1);
// 		drawline(c , l_rx, l_ry, line_color);
		
// 		angel += 0.000579;
// 		f += 0.000579; 
// 	}

// // 	//virtical
// // 	double nTan = tan(deg_to_rad(angel));
// // 	dof = 0;
// // 	if (deg_to_rad(angel) > M_PI/2 && deg_to_rad(angel) < 3 * M_PI/2)
// // 	{
// // 		l_rx = (((int)c->map->p_x >> 6) << 6) - 0.0001;
// // 		l_ry = (c->map->p_x - l_rx) * nTan + c->map->p_y;
// // 		l_rdx = -64;
// // 		l_rdy = -l_rdx * nTan;
// // 	}
// // 	if (deg_to_rad(angel) < M_PI/2 || deg_to_rad(angel) > 3 * M_PI/2)
// // 	{
// // 		l_rx = (((int)c->map->p_x >> 6) << 6) + 64;
// // 		l_ry = (c->map->p_x - l_rx) * nTan + c->map->p_y;
// // 		l_rdx = 64;
// // 		l_rdy = -l_rdx * nTan;
// // 	}
// // 	if(deg_to_rad(angel) == M_PI/2 || deg_to_rad(angel) == 3 * M_PI/2)
// // 	{
// // 		l_rx = c->map->p_x;
// // 		l_ry = c->map->p_y;
// // 		dof = 8;
// // 	}
// // 	while (dof < 8)
// // 	{
// // 		if (l_rx < 0 || l_rx >= (c->map->map_width * 64)
// // 			|| l_ry < 0 || l_ry >= (c->map->map_height * 64))
// // 			break ;
// // 		if (c->map->map[(int) l_ry / 64][(int) l_rx / 64] == '1')
// // 			dof = 8;
// // 		else
// // 		{
// // 			//write(1,"helooo\n",8);
// // 			l_rx += l_rdx;
// // 			l_ry += l_rdy;
// // 			dof++;
// // 		}
// // 	}
// 	// ft_putnbr(c->map->angel);
// 	// write(1, "\n", 1);
// 	// drawline(c , l_rx, l_ry, line_color);
// }


// static void	draw_line_cons(t_cub3d *c, int *angel, double *l_rx, double *l_ry)
// {
// 	if (*angel == 0)
// 		*angel = c->map->angel - 45;
// 	if (*l_rx == 0 && *l_ry == 0)
// 	{
// 		*l_rx = c->map->p_x;
// 		*l_ry = c->map->p_y;
// 	}
// }

// static void	draw_line(t_cub3d *c, int line_color)
// {
// 	static double	l_rx;
// 	static double	l_ry;
// 	static int		angel;

// 	draw_line_cons(c, &angel, &l_rx, &l_ry);
// 	if (c->map->map[(int) l_ry / 64][(int) l_rx / 64] == '1')
// 	{
// 		l_rx = 0;
// 		l_ry = 0;
// 		if (angel == 360 && c->map->angel >= 0 && c->map->angel <= 45)
// 			angel = 0;
// 		if (angel <= c->map->angel + 45)
// 		{
// 			angel++;
// 			if (angel == 0)
// 				angel = 360;
// 			return (draw_line(c, line_color));
// 		}
// 		angel = 0;
// 		return ;
// 	}
// 	l_ry -= sin(deg_to_rad(angel));
// 	l_rx += cos(deg_to_rad(angel));
// 	my_mlx_pixel_put(c->img, l_rx, l_ry, line_color);
// 	draw_line(c, line_color);
// }

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
