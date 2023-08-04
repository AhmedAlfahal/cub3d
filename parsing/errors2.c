/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:07:19 by aalfahal          #+#    #+#             */
/*   Updated: 2023/07/29 18:28:45 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
