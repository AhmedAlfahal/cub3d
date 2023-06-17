/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 15:11:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/17 21:27:15 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"../cub3d.h"

static void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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
	// else if (key_code == 13)
	// 	go(s, 0, -1);
	// else if (key_code == 1)
	// 	go(s, 0, 1);
	// else if (key_code == 0)
	// 	go(s, -1, 0);
	// else if (key_code == 2)
	// 	go(s, 1, 0);
	ft_printf("[%d]\n", key_code);
	return (0);
}

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

static void	draw_map(t_cub3d *c)
{
	if (c->map->map[c->map->i][c->map->j] == 0)
	{
		c->map->j = 0;
		c->map->i++;
	}
	if (c->map->map[c->map->i] == NULL)
		return ;
	if (c->map->map[c->map->i][c->map->j] == '1')
		draw_object(c, c->map->i * 64, 255);
	else if (c->map->map[c->map->i][c->map->j] == '0')
		draw_object(c, c->map->i * 64, 10);
	c->map->j++;
	draw_map(c);
}

void	render(t_cub3d *c)
{
	t_mlx	m;
	t_img	img;

	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, \
	c->map->map_width * 64, c->map->map_height * 64, "cub3d");
	c->mlx = &m;
	img.img = mlx_new_image(m.mlx, c->map->map_width * 64, c->map->map_height * 64);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	c->map->i = 0;
	c->map->j = 0;
	c->img = &img;
	draw_map(c);
	mlx_put_image_to_window(c->mlx->mlx, c->mlx->win, c->img->img, 0, 0);
	mlx_hook(c->mlx->win, 2, 0, key, c);
	mlx_hook(c->mlx->win, 17, 0, destroy_window, c);
	mlx_loop(c->mlx->mlx);
}