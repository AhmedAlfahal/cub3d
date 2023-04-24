/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:33:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/24 11:30:34 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3d.h"

static char	*skip_space(char *s)
{
	if (!s)
		return (NULL);
	while (*s == ' ' && *s != '\0')
		s++;
	return (s);
}

static int	next_space(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != ' ' && s[i])
		i++;
	return (i);
}

int	check_in_tmp2d(char *tmp, char **texture, int i)
{
	char	*s1;

	s1 = ft_substr(skip_space(tmp), 0, next_space(skip_space(tmp)));
	if (texture[i] == NULL)
		return (free(s1), 0);
	if (ft_strncmp(s1, texture[i], ft_strlen(texture[i])) == 0)
	{
		return (free(s1), 1);
	}
	return (free(s1), check_in_tmp2d(tmp, texture, ++i));
}
