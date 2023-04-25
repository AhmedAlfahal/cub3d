/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:33:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/25 13:16:55 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

void	check_text_error(t_cub3d *c)
{
	if (c->counter->c > 1 || c->counter->ea > 1 || c->counter->f > 1 \
	|| c->counter->no > 1 || c->counter->so > 1 || c->counter->we > 1)
		c->counter->error++;
	if (c->counter->c == 0 || c->counter->ea == 0 || c->counter->f == 0 \
	|| c->counter->no == 0 || c->counter->so == 0 || c->counter->we == 0)
		c->counter->error++;
}

static void	confirm_found(t_cub3d *c, int i)
{
	ft_printf("[%d]\n", c->counter->no);
	if (i == 0)
		c->counter->no++;
	else if (i == 1)
		c->counter->so++;
	else if (i == 2)
		c->counter->we++;
	else if (i == 3)
		c->counter->ea++;
	else if (i == 4)
		c->counter->f++;
	else if (i == 5)
		c->counter->c++;
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

int	check_in_tmp2d(t_cub3d *c, char *tmp, char ***texture)
{
	static int	i;
	char		*s1;
	char		**text;

	text = *texture;
	s1 = ft_substr(skip_space(tmp), 0, next_space(skip_space(tmp)));
	if (text[i] == NULL)
	{
		i = 0;
		return (free(s1), -1);
	}
	if (ft_strncmp(s1, text[i], ft_strlen(text[i])) == 0)
	{
		i = 0;
		confirm_found(c, i);
		return (free(s1), i);
	}
	i++;
	return (free(s1), check_in_tmp2d(c, tmp, &text));
}
