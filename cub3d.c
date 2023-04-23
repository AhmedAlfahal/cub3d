/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:52 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 12:50:36 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	c;

	c.map = NULL;
	if (ac == 2)
	{
		reading_map(av[1], c.map);
		print_2d_array(c.map->map);
		free_2d_array(c.map->map);
	}
	else
	{
		ft_printf("Wrong arguments\n");
		return (1);
	}
	return (0);
}
