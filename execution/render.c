/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:11:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/17 22:23:54 by aalfahal         ###   ########.fr       */
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

static int	key(int key_code, t_cub3d *c)
{
	if (key_code == 53)
		destroy_window(c);
	ft_printf("[%d]\n", key_code);
	return (0);
}

void	render(t_cub3d *c)
{
	t_mlx	m;
	t_img	img;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, \
	c->map->map_width * 64, c->map->map_height * 64, "cub3d");
	c->mlx = &m;
	img.img = mlx_new_image(m.mlx, c->map->map_width * 64 \
	, c->map->map_height * 64);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	c->map->i = 0;
	c->map->j = 0;
	c->img = &img;
	draw_map(c);
	mlx_put_image_to_window(c->mlx->mlx, c->mlx->win, c->img->img, 0, 0);
	mlx_hook(c->mlx->win, 2, 0, key, c);
	mlx_hook(c->mlx->win, 17, 0, destroy_window, c);
	mlx_loop(c->mlx->mlx);
}
