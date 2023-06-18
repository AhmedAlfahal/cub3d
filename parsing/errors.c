/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:33:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/18 15:48:24 by aalfahal         ###   ########.fr       */
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

static void	player_condition(t_cub3d *c, int i)
{
	c->map->p_x = c->map->j * 64;
	c->map->p_y = i * 64;
	if (c->map->map[i][c->map->j] == 'N')
		c->map->angel = 90;
	else if (c->map->map[i][c->map->j] == 'E')
		c->map->angel = 0;
	else if (c->map->map[i][c->map->j] == 'W')
		c->map->angel = 180;
	else if (c->map->map[i][c->map->j] == 'S')
		c->map->angel = 270;
}

void	mallocing_new(t_cub3d *c, int i)
{
	char	*tmp;

	if (c->map->map[i] == NULL)
		return ;
	tmp = malloc(sizeof(char) * c->map->map_width + 1);
	if (!tmp)
		return ;
	while (c->map->map[i][c->map->j])
	{
		tmp[c->map->j] = c->map->map[i][c->map->j];
		if (c->map->map[i][c->map->j] == 'N' \
		|| c->map->map[i][c->map->j] == 'E' \
		|| c->map->map[i][c->map->j] == 'W' || c->map->map[i][c->map->j] == 'S')
		{
			player_condition(c, i);
			tmp[c->map->j] = 'P';
		}
		c->map->j++;
	}
	while (c->map->j < c->map->map_width)
		tmp[c->map->j++] = '1';
	tmp[c->map->j] = 0;
	free(c->map->map[i]);
	c->map->map[i] = tmp;
}
