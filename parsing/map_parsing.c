/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/24 11:14:23 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	creating_tmp_2d(t_map *m)
{
	m->text_names = malloc(sizeof(char *) * 7);
	m->text_names[0] = ft_strdup("NO");
	m->text_names[1] = ft_strdup("SO");
	m->text_names[2] = ft_strdup("WE");
	m->text_names[3] = ft_strdup("EA");
	m->text_names[4] = ft_strdup("F");
	m->text_names[5] = ft_strdup("C");
	m->text_names[6] = NULL;
}

static void	check_errors(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (m->map[i])
	{
		if (check_in_tmp2d(m->map[i], m->text_names, 0) == 1)
			j++;
		i++;
	}
	ft_printf("[%d]\n", j);
	if (j > 6)
		clean_exit(m, 4, 1);
}

static void	reading_to2d(char *s, int number_of_lines, t_map *m)
{
	int		fd;
	int		i;
	char	*line;

	m->map = malloc(sizeof(char *) * (number_of_lines + 1));
	if (!m->map)
		return ;
	fd = open(s, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		m->map[i++] = line;
		line = get_next_line(fd);
	}
	m->map[i] = 0;
	close(fd);
	if (number_of_lines == 0)
		clean_exit(m, 1, 1);
}

void	reading_map(char *s, t_cub3d *c)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	c->map = malloc(sizeof(t_map) * 1);
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
	reading_to2d(s, number_of_lines, c->map);
	creating_tmp_2d(c->map);
	check_errors(c->map);
}
