/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/29 20:31:10 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

void	remove_space(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == ' ' && s[j] != '\0')
			j++;
		if (s[j] == '\0')
			continue ;
		s[i++] = s[j++];
	}
	s[i] = 0;
}

int	ft_isdigit(char **s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s || !*s)
		return (0);
	while (s[i])
	{
		while (s[i][j])
		{
			if (s[i][j] == '+' && j == 0)
				j++;
			else if ((s[i][j] >= '0' && s[i][j] <= '9') || s[i][j] == ' ')
				j++;
			else
				return (0);
		}
		remove_space(s[i]);
		i++;
		j = 0;
	}
	return (1);
}
