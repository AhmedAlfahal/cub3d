/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 12:05:19 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**reading_to2d(char *s, int number_of_lines)
{
	int		fd;
	char	*line;
	char	**mapp;
	int		i;

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

static t_cub3d	*check_map_component(char **mapp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (mapp[i] != NULL)
	{
		j = 0;
		while (mapp[i][j] != '\0')
		{
			if (mapp[i][j] != '0' && mapp[i][j] != '1' \
			&& mapp[i][j] != 'C' && mapp[i][j] != 'E' && mapp[i][j] != 'P')
			{
				free_2d_array(mapp);
				write(2, "Error\nWrong map commponent\n", 28);
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (letting_component_in(mapp));
}

t_cub3d	*reading_map(char *s)
{
	int		fd;
	char	*line;
	size_t	lenn;
	int		number_of_lines;

	number_of_lines = 0;
	fd = open(s, O_RDONLY);
	if (ft_strncmp(s, ".cub", ft_strlen(s) - 4) == 1)
		closing_and_freeing(fd, NULL, 1);
	if (fd < 0)
		closing_and_freeing(fd, NULL, 1);
	line = get_next_line(fd);
	lenn = ft_strlen(line);
	while (line != NULL)
	{
		if ((lenn > ft_strlen(line) || lenn < ft_strlen(line)) && line != NULL)
			closing_and_freeing(fd, line, 1);
		free(line);
		number_of_lines++;
		line = get_next_line(fd);
	}
	closing_and_freeing(fd, line, 0);
	return (check_map_component(reading_to2d(s, number_of_lines)));
}
