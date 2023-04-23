/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:52 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 13:04:50 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	c;

	if (ac == 2)
	{
		reading_map(av[1], &c);
		print_2d_array(c.map->map);
		clean_exit(c.map, 0, 0);
	}
	else
	{
		ft_printf("Wrong arguments\n");
		return (1);
	}
	return (0);
}
