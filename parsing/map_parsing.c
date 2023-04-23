/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 12:38:30 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**reading_to2d(char *s, int number_of_lines)
{
	int		fd;
	int		i;
	char	*line;
	char	**mapp;

	mapp = malloc(sizeof(char *) * (number_of_lines + 1));
	if (!mapp)
		return (NULL);
	fd = open(s, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		mapp[i++] = line;
		line = get_next_line(fd);
	}
	mapp[i] = 0;
	close(fd);
	return (mapp);
}

void	reading_map(char *s, t_map *m)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	fd = open(s, O_RDONLY);
	if (ft_strncmp(s, ".cub", ft_strlen(s) - 4) == 1)
		closing_and_freeing(fd, NULL, 1);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		number_of_lines++;
		line = get_next_line(fd);
	}
	closing_and_freeing(fd, line, 0);
	m->map = reading_to2d(s, number_of_lines);
}
