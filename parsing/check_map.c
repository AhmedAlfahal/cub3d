/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:27:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/09/01 19:00:29 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <stdio.h>
#include <unistd.h>

static void	check_line_element(t_map *m, char *l, int msg)
{
	if (!l || *l == 0)
		return ;
	if (msg == 0)
	{
		if (*l != '0' && *l != '1' && *l != 'N' \
		&& *l != 'S' && *l != 'E' && *l != 'W' && *l != ' ')
		{
			m->error = 1;
			return ;
		}
		if (*l == 'N' || *l == 'S' || *l == 'E' || *l == 'W')
			m->counters[p_pos]++;
	}
	else if (msg == 1)
		if (*l != '1' && *l != ' ')
			m->error = 1;
	return (check_line_element(m, ++l, msg));
}

void	check_file_elements(t_cub3d *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map->file[i])
		check_line_element(c->map, c->map->file[i++], 0);
	free_2d_array(c->map->map);
	c->map->map = malloc(sizeof(char *) * (len_2d_wo0(c->map->file) + 1));
	if (!c->map->map)
		return ;
	i = 0;
	while (c->map->file[i])
	{
		if (c->map->file[i][0] == 0)
		{
			i++;
			continue ;
		}
		c->map->map[j++] = ft_strdup(c->map->file[i++]);
	}
	c->map->map[j] = NULL;
	check_line_element(c->map, c->map->map[0], 1);
	if (j > 0)
		check_line_element(c->map, c->map->map[j - 1], 1);
}

static void	check_space_closed(t_map *m, int i, int j)
{
	if (j < 0 || i < 0 || j > ft_strlen(m->tmp_map[i]))
		return ;
	if (m->tmp_map[i] == NULL)
		return ;
	if (m->tmp_map[i][j] == 0)
		return ;
	if (m->tmp_map[i][j] == 'X' || m->tmp_map[i][j] == '1' \
	|| i < 0 || m->tmp_map[i] == NULL)
		return ;
	if (m->tmp_map[i][j] != '1' && m->tmp_map[i][j] != ' ')
		m->error++;
	m->tmp_map[i][j] = 'X';
	check_space_closed(m, i + 1, j);
	check_space_closed(m, i - 1, j);
	check_space_closed(m, i, j + 1);
	check_space_closed(m, i, j - 1);
}

static void	check_map_element_helper(t_map *m, int i, int j)
{
	char	*tmp;

	tmp = remove_space_1(m->map[i]);
	if (tmp[0] != '1' || tmp[len(tmp) - 1] != '1')
		m->error++;
	free(tmp);
	if (m->map[i][j] == 0)
	{
		if (j > m->map_width)
			m->map_width = j;
		if (j > ft_strlen(m->map[i]))
			check_line_element(m, &m->map[i - 1][j - (j - len(m->map[i]))], 1);
		if (j < ft_strlen(m->map[i]))
			check_line_element(m, &m->map[i][j], 1);
	}
}

void	check_map_element(t_map *m)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	free_2d_array(m->tmp_map);
	m->tmp_map = ft_2d_dubpper(m->map);
	while (m->map[i])
	{
		j = 0;
		while (m->map[i][j])
		{
			player_condition(m, i, j);
			if (m->map[i][j] == ' ')
				check_space_closed(m, i, j);
			j++;
		}
		check_map_element_helper(m, i, j);
		i++;
	}
}
