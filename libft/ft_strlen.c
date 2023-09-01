/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:55:43 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/25 21:23:26 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
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
	while (s[i])
		i++;
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

int	len_2d_wo0(char **tmp)
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
