/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:27:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/30 12:15:09 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	len_2d_wo0(char **tmp)
{
	static int	i;
	static int	j;

	if (tmp[j] == NULL)
		return (i);
	if (tmp[j][0] == 0)
		j++;
	else
	{
		j++;
		i++;
	}
	return (len_2d_wo0(tmp));
}

static void	check_line_element(t_map *m, char *l, int msg)
{
	if (!l || *l == 0)
		return ;
	if (msg == 0)
	{
		if (*l != '0' && *l != '1' && *l != 'N' \
		&& *l != 'S' && *l != 'E' && *l != 'W')
		{
			m->error = 1;
			return ;
		}
		if (*l == 'N' || *l == 'S' || *l == 'E' || *l == 'W')
			m->counters[p_pos]++;
	}
	else if (msg == 1)
		if (*l != '1')
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
	{
		remove_space(c->map->file[i]);
		check_line_element(c->map, c->map->file[i++], 0);
	}
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
	print_2d_array(c->map->map);
}

void	check_map_element(t_cub3d *c, char **map)
{
	static int	i;

	if (map[i] == NULL)
		return ;
	if (i == 0 || i == ft_strlen_2d(map) - 1)
	{
		check_line_element(c->map, map[i], 1);
		if (c->map->error > 0)
			clean_exit(c, 4, 1);
	}
	else
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			clean_exit(c, 4, 1);
		if (ft_strlen(map[i]) > c->map->max_len)
			c->map->max_len = ft_strlen(map[i]);
	}
	i++;
	return (check_map_element(c, map));
}

// void	align_elements(t_cub3d *c)
// {
// 	static int	i;
// 	char		*tmp;

// 	tmp = malloc(sizeof(char) * (c->map->max_len + 1));
// 	if (!tmp)
// 		return ;
// }