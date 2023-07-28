/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:47 by aalfahal          #+#    #+#             */
/*   Updated: 2023/07/29 00:53:36 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_2d_array(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_all(t_cub3d *c)
{
	free_2d_array(c->map->textures);
	free_2d_array(c->map->file);
	free_2d_array(c->map->tmp_text_names);
	free(c->map->counters);
	free(c->map->f_c_rgb);
	free_2d_array(c->map->map);
	free(c->map);
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

void	clean_exit(t_cub3d *c, int msg, int ex)
{
	if (msg == 1)
		write(2, "Error\nNothing in th map :))))\n", 31);
	else if (msg == 2)
		write(2, "bye\n", 4);
	else if (msg == 3)
		write(2, "Error\nOne of the '.xpms' is missing\n", 37);
	else if (msg == 4)
		write(2, "Error\nWrong components\n", 24);
	else if (msg == 5)
		write(2, "Error\nWrong RGB color\n", 23);
	else if (msg == 6)
		write(1, "GG\n", 4);
	else if (msg == 7)
		write(2, "Map must be at the end\nor invalid components\n", 46);
	free_all(c);
	exit(ex);
}
