/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:47 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 13:00:51 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2d_array(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map[i]);
	free(map);
}

void	closing_and_freeing(int fd, char *line, int ext)
{
	close(fd);
	free(line);
	if (ext == 1)
	{
		write(2, "Error\n", 7);
		exit(1);
	}
}

void	clean_exit(t_map *map, int msg, int ex)
{
	if (msg == 1)
		write(2, "Error\nNothing in th map :))))\n", 31);
	else if (msg == 2)
		write(2, "bye\n", 4);
	else if (msg == 3)
		write(2, "Error\nOne of the '.xpms' is missing\n", 37);
	free_2d_array(map->map);
	free(map);
	exit(ex);
}
