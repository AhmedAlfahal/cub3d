/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:17:21 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/23 02:15:33 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
