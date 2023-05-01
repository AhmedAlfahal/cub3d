/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_printers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 12:40:22 by aalfahal          #+#    #+#             */
/*   Updated: 2023/05/01 15:25:34 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_2d_array(char **d)
{
	int	i;

	i = 0;
	while (d[i])
		ft_printf("%s	\n", d[i++]);
}

void	print_counters(t_cub3d *c)
{
	int	i;

	i = 0;
	ft_printf("NO		[%s]\n", c->map->textures[no]);
	ft_printf("SO		[%s]\n", c->map->textures[so]);
	ft_printf("EA		[%s]\n", c->map->textures[ea]);
	ft_printf("WE		[%s]\n", c->map->textures[we]);
	ft_printf("F		[%d]	[%d]	[%d]\n", c->map->f_c_rgb[f_r], \
	c->map->f_c_rgb[f_g], c->map->f_c_rgb[f_b]);
	ft_printf("C		[%d]	[%d]	[%d]\n", c->map->f_c_rgb[c_r], \
	c->map->f_c_rgb[c_g], c->map->f_c_rgb[c_b]);
	while (i < 7)
		ft_printf("[%d]	,", c->map->counters[i++]);
	ft_printf("\n");
	print_2d_array(c->map->map);
}
