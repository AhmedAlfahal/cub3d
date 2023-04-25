/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/25 13:13:52 by aalfahal         ###   ########.fr       */
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

static void	check_errors(t_cub3d *c)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = 0;
	while (c->map->map[i])
	{
		index = check_in_tmp2d(c, c->map->map[i], &c->map->text_names);
		if (index > 0)
			j++;
		i++;
	}
	ft_printf("[%d]\n", j);
	check_text_error(c);
	if (c->counter->error > 0)
		clean_exit(c, 4, 1);
}

static void	reading_to2d(t_cub3d *c, char *s, int number_of_lines)
{
	int		fd;
	int		i;
	char	*line;

	c->map->map = malloc(sizeof(char *) * (number_of_lines + 1));
	if (!c->map->map)
		return ;
	fd = open(s, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		c->map->map[i++] = line;
		line = get_next_line(fd);
	}
	c->map->map[i] = 0;
	close(fd);
	if (number_of_lines == 0)
		clean_exit(c, 1, 1);
}

void	reading_map(char *s, t_cub3d *c)
{
	int		fd;
	int		number_of_lines;
	char	*line;

	number_of_lines = 0;
	c->map = malloc(sizeof(t_map) * 1);
	c->counter = malloc(sizeof(t_counters) * 1);
	ft_bzero(&c->counter, sizeof(t_counters) * 1);
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
	reading_to2d(c, s, number_of_lines);
	creating_tmp_2d(c->map);
	check_errors(c);
}
