/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:33:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/04 23:53:35 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	check_text_error(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (c->map->counters[i] == 0 || c->map->counters[i] > 1)
			c->map->error++;
		i++;
	}
}

void	*check_in_tmp2d(t_cub3d *c, char *tmp, char ***texture)
{
	static int	i;
	char		**text;

	text = *texture;
	c->map->s1 = ft_substr(skip_space(tmp), 0, next_space(skip_space(tmp)));
	if (text[i] == NULL)
	{
		i = 0;
		return (free(c->map->s1), NULL);
	}
	if (ft_strncmp(c->map->s1, text[i], ft_strlen(text[i])) == 0 \
	&& ft_strlen(c->map->s1) == ft_strlen(text[i]))
	{
		c->map->counters[i]++;
		cutting_text(c, tmp, i);
		ft_bzero(tmp, sizeof(char) * ft_strlen(tmp));
		i = 0;
		return (free(c->map->s1), NULL);
	}
	i++;
	return (free(c->map->s1), check_in_tmp2d(c, tmp, &text));
}

static int	check_map_end(t_cub3d *c, char *tmp, char **text)
{
	static int	i;

	c->map->s1 = ft_substr(skip_space(tmp), 0, next_space(skip_space(tmp)));
	if ((ft_strncmp(c->map->s1, text[i], ft_strlen(text[i])) == 0 \
	&& ft_strlen(c->map->s1) == ft_strlen(text[i])))
	{
		i = 0;
		return (free(c->map->s1), 1);
	}
	else if (text[i] == NULL)
	{
		i = 0;
		return (free(c->map->s1), 2);
	}
	i++;
	return (free(c->map->s1), check_map_end(c, tmp, text));
}

void	check_map_at_end(t_cub3d *c)
{
	int	i;
	int	r;
	int	rr;

	i = ft_strlen_2d(c->map->file) - 1;
	r = -1;
	rr = -2;
	if (!c->map->file || !c->map->file[0])
		return ;
	while (i > 0)
	{
		r = check_map_end(c, c->map->file[i--], c->map->tmp_text_names);
		if (rr == -2)
			rr = r;
		else if (rr == 1 && r == 2)
			clean_exit(c, 7, 1);
		rr = r;
	}
}

void	player_condition(t_map *m, int i, int j)
{
	if (m->map[i][j] == 'N' || m->map[i][j] == 'S' \
	|| m->map[i][j] == 'E' || m->map[i][j] == 'W')
	{
		m->p_x = j * 64;
		m->p_y = i * 64;
		if (m->map[i][j] == 'N')
			m->angel = 90;
		else if (m->map[i][j] == 'E')
			m->angel = 0;
		else if (m->map[i][j] == 'W')
			m->angel = 180;
		else if (m->map[i][j] == 'S')
			m->angel = 270;
		m->map[i][j] = 'P';
	}
}
