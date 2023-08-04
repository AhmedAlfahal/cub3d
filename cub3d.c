/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:52 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/01 18:54:26 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub3d	c;

	if (ac == 2)
	{
		reading_map(av[1], &c);
		render(&c);
		print_counters(&c);
		clean_exit(&c, 0, 0);
	}
	else
	{
		write(2, "Error\nWrong Number of Arguments\n", 33);
		return (1);
	}
	return (0);
}
