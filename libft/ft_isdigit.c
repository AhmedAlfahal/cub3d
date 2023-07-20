/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/05/01 17:19:28 by aalfahal         ###   ########.fr       */
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

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (!s || !*s)
		return (0);
	remove_space(s);
	while (s[i])
	{
		if (s[i] == '+' && i == 0)
			i++;
		else if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (0);
	}
	if (i == 0)
		return (0);
	return (1);
}
