/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:21 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/01 15:23:59 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	tmp;

	i = 0;
	tmp = (char )c;
	if (!s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] == tmp)
		{
			return (&((char *)s)[i]);
		}
		i++;
	}
	return (NULL);
}
