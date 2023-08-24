/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:11:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/22 21:43:00 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	destroy_window(t_cub3d *c)
{
	mlx_destroy_window(c->mlx->mlx, c->mlx->win);
	clean_exit(c, 0, 0);
	write(2, "bye\n", 4);
	exit(0);
}

static void	draw_img(t_cub3d *c)
{
	if (c->img->img != NULL)
		mlx_destroy_image(c->mlx->mlx, c->img->img);
	c->img->img = mlx_new_image(c->mlx->mlx, WIDTH, HIGHT);
	c->img->addr = mlx_get_data_addr(c->img->img, &c->img->bits_per_pixel, \
	&c->img->line_length, &c->img->endian);
	draw_3dmap(c);
	mlx_put_image_to_window(c->mlx->mlx, c->mlx->win, c->img->img, 0, 0);
}

static void	player_movment(int key_code, t_cub3d *c)
{
	if (key_code == 13)
	{
		c->map->p_y -= sin(deg_to_rad(c->map->angel)) * 8;
		c->map->p_x += cos(deg_to_rad(c->map->angel)) * 8;
	}
	else if (key_code == 1)
	{
		c->map->p_y += sin(deg_to_rad(c->map->angel)) * 8;
		c->map->p_x -= cos(deg_to_rad(c->map->angel)) * 8;
	}
	else if (key_code == 0)
	{
		c->map->p_y += cos(deg_to_rad(c->map->angel)) * 8;
		c->map->p_x += sin(deg_to_rad(c->map->angel)) * 8;
	}
	else if (key_code == 2)
	{
		c->map->p_y -= cos(deg_to_rad(c->map->angel)) * 8;
		c->map->p_x -= sin(deg_to_rad(c->map->angel)) * 8;
	}
}

static int	key(int key_code, t_cub3d *c)
{
	int	pp_x;
	int	pp_y;

	pp_x = c->map->p_x;
	pp_y = c->map->p_y;
	if (key_code == 53)
		destroy_window(c);
	player_movment(key_code, c);
	if (key_code == 124)
		c->map->angel += 5;
	else if (key_code == 123)
		c->map->angel -= 5;
	if (c->map->angel >= 360 || c->map->angel < 0)
		c->map->angel = (c->map->angel + 360) % 360;
	if (c->map->map[(int) c->map->p_y / 64][(int) c->map->p_x / 64] == '1')
	{
		c->map->p_x = pp_x;
		c->map->p_y = pp_y;
	}
	draw_img(c);
	return (0);
}

void	render(t_cub3d *c)
{
	t_mlx	m;
	t_img	img;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HIGHT, "cub3d");
	c->mlx = &m;
	ft_bzero(&img, sizeof(t_img));
	c->img = &img;
	draw_img(c);
	mlx_hook(c->mlx->win, 2, 0, key, c);
	mlx_hook(c->mlx->win, 17, 0, destroy_window, c);
	mlx_loop(c->mlx->mlx);
}
