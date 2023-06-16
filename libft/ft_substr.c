/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 01:32:41 by aalfahal          #+#    #+#             */
/*   Updated: 2023/05/01 17:59:58 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	int		k;

	i = 0;
	k = start;
	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (len > (size_t)ft_strlen(s))
	{
		sub = malloc(sizeof(char) * (ft_strlen(s) - start) + 1);
		if (!sub)
			return (NULL);
		len = ft_strlen(s);
	}
	else
		sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && i < len - k)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
