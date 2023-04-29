/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/28 11:09:08 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strlen_2d(char **s)
{
	int	i;

	i = 0;
	if (!s || *s == 0)
		return (0);
	while (s[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	ft_commalen(char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s || *s == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ',')
			j++;
		i++;
	}
	return (j);
}
