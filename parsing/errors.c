/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:33:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/27 09:23:50 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	check_text_error(t_cub3d *c)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (c->map->counters[i] == 0 || c->map->counters[i] > 1)
			c->map->error++;
		i++;
	}
}

char	*skip_space(char *s)
{
	if (!s)
		return (NULL);
	while (*s == ' ' && *s != '\0')
		s++;
	return (s);
}

int	next_space(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != ' ' && s[i])
		i++;
	return (i);
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
		i = 0;
		return (free(c->map->s1), NULL);
	}
	i++;
	return (free(c->map->s1), check_in_tmp2d(c, tmp, &text));
}
