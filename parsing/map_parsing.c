/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:18:00 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/26 10:51:26 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	malloc_all(t_map *m)
{
	int	i;

	i = 0;
	m->tmp_text_names = malloc(sizeof(char *) * 7);
	m->f_c_rgb = malloc(sizeof(int) * 7);
	m->counters = malloc(sizeof(int) * 7);
	m->textures = malloc(sizeof(char *) * 5);
	ft_bzero(m->textures, sizeof(char *) * 5);
	while (m->textures[i])
		m->textures[i++] = ft_strdup("");
	ft_bzero(m->tmp_text_names, sizeof(char *) * 7);
	ft_bzero(m->f_c_rgb, sizeof(int) * 7);
	ft_bzero(m->counters, sizeof(int) * 7);
	m->tmp_text_names[no] = ft_strdup("NO");
	m->tmp_text_names[so] = ft_strdup("SO");
	m->tmp_text_names[we] = ft_strdup("WE");
	m->tmp_text_names[ea] = ft_strdup("EA");
	m->tmp_text_names[f] = ft_strdup("F");
	m->tmp_text_names[c] = ft_strdup("C");
	m->error = 0;
}

static void	check_errors(t_cub3d *c)
{
	int	i;

	i = 0;
	malloc_all(c->map);
	while (c->map->map[i])
		check_in_tmp2d(c, c->map->map[i++], &c->map->tmp_text_names);
	check_text_error(c);
	print_counters(c);
	if (c->map->error > 0)
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
	check_errors(c);
}
