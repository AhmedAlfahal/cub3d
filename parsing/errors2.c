/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:07:19 by aalfahal          #+#    #+#             */
/*   Updated: 2023/07/25 17:17:26 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	check_line(char *tmp)
{

}

int	check_map_at_end_cons(t_cub3d *c, char *tmp, char ***texture)
{
	static int	i;
	char		**text;

	text = *texture;
	c->map->s1 = ft_substr(skip_space(tmp), 0, next_space(skip_space(tmp)));
	if (text[i] == NULL)
	{
		i = 0;
		return (free(c->map->s1), 0);
	}
	if (ft_strncmp(c->map->s1, text[i], ft_strlen(text[i])) == 0 \
	&& ft_strlen(c->map->s1) == ft_strlen(text[i]))
	{
		ft_bzero(tmp, sizeof(char) * ft_strlen(tmp));
		i = 0;
		return (free(c->map->s1), 1);
	}
	else if (check_line(c->map->s1) == 0)
	{
		ft_bzero(tmp, sizeof(char) * ft_strlen(tmp));
		i = 0;
		return (free(c->map->s1), 2);
	}
	i++;
	return (free(c->map->s1), check_map_at_end_cons(c, tmp, &text));
}

void	check_map_at_end(t_cub3d *c)
{
	int	i;

	i = ft_strlen_2d(c->map->file);
	if (!c->map->file || !c->map->file[0])
		return ;
	while (i > 0)
	{
		
	}
}
