/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 14:23:49 by hmohamed          #+#    #+#             */
/*   Updated: 2023/08/17 17:36:28 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	texture(t_cub3d *c)
{
	printf("%s\n", c->map->textures[no] + 2);
	c->map->no_tx.img = mlx_xpm_file_to_image(c->mlx->mlx,  c->map->textures[no], &c->map->no_tx.width, &c->map->no_tx.height);
	  if (c->map->no_tx.img == NULL) 
		{
			write(1, "ERRRRRRRRor\n", 13);
        	return ;
		}

	c->map->no_tx.addr = mlx_get_data_addr(c->map->no_tx.img, &c->map->no_tx.bits_per_pixel, \
	&c->map->no_tx.line_length, &c->map->no_tx.endian);

	for (int x = 0; x < c->map->no_tx.width; x++){
		for (int y = 0; y < c->map->no_tx.height; y++) 
		{
    	    int pixel_offset = y * c->map->no_tx.line_length + x * (c->map->no_tx.bits_per_pixel / 8);

   	     // Access color channels
    	    unsigned char red = c->map->no_tx.addr[pixel_offset + 2]; // Red channel
     	   unsigned char green = c->map->no_tx.addr[pixel_offset + 1]; // Green channel
     	   unsigned char blue = c->map->no_tx.addr[pixel_offset]; // Blue channel
      	//  unsigned char alpha = c->map->no_tx.addr[pixel_offset + 3]; // Alpha channel
		//rgb_to_int(red, green , blue);
      	printf("color %d \n " , rgb_to_int(red, green , blue));
    }
}
	ft_putstr(c->map->no_tx.addr);
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

void	draw_3dmap_lines(t_cub3d *c, int line_color)
{
	double	l_h;
	double	l_o;
	double	nangle;

	nangle = deg_to_rad(c->map->angel) - c->map->r_angel;
	if (nangle < 0)
		nangle += 2 * M_PI;
	if (nangle > 2 * M_PI)
		nangle -= 2 * M_PI;
	c->map->dest = c->map->dest * cos(nangle);
	l_h = (64 * (HIGHT)) / c->map->dest;
	if (l_h > (HIGHT))
		l_h = HIGHT ;
	l_o = ((HIGHT) / 2) - l_h / 2;
	c->map->x0 = c->map->rray;
	c->map->y0 = l_o;
	drawline3d(c, c->map->rray, l_h + l_o, line_color);
	c->map->x0 = c->map->rray;
	c->map->y0 = 0;
	drawline3d(c, c->map->rray, l_o, rgb_to_int(c->map->f_c_rgb[c_r],
			c->map->f_c_rgb[c_g], c->map->f_c_rgb[c_b]));
	c->map->x0 = c->map->rray;
	c->map->y0 = l_h + l_o;
	drawline3d(c, c->map->rray, HIGHT, rgb_to_int(c->map->f_c_rgb[f_r],
			c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]));
}

void	draw_3dmap(t_cub3d *c)
{
	texture(c);
	draw_lines(c, rgb_to_int(128, 0, 128));
}
