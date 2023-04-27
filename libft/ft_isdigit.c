/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/27 10:06:43 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*remove_space(char **s)
{
	char	*tmp;
	char	*local;
	int		i;
	int		j;

	local = *s;
	tmp = NULL;
	i = 0;
	j = 0;
	while (local)
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
			else if (s[i][j] >= '0' && s[i][j] <= '9')
				j++;
			else
				return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
