/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 18:27:46 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/29 20:55:50 by aalfahal         ###   ########.fr       */
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

static void	check_line_element(t_map *m, char *l)
{
	if (!l || *l == 0)
		return ;
	if (*l != '0' && *l != '1' && *l != 'N' \
	&& *l != 'S' && *l != 'E' && *l != 'W')
	{
		m->error = 1;
		return ;
	}
	if (*l == 'N' || *l == 'S' || *l == 'E' || *l == 'W')
		m->counters[p_pos]++;
	return (check_line_element(m, ++l));
}

void	check_map_elements(t_cub3d *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c->map->file[i])
	{
		remove_space(c->map->file[i]);
		check_line_element(c->map, c->map->file[i++]);
	}
	free_2d_array(c->map->map);
	c->map->map = malloc(sizeof(char *) * (len_2d_wo0(c->map->file) + 1));
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
