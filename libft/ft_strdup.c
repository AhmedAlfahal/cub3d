/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:13:07 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/22 21:36:57 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	dup = (char *) malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dup == NULL)
		return (0);
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_2d_dubpper(char **s1)
{
	int		i;
	char	**tmp;

	i = 0;
	if (!s1)
		return (NULL);
	tmp = malloc(sizeof(char *) * (ft_strlen_2d(s1) + 1));
	ft_bzero(tmp, sizeof(char *) * (ft_strlen_2d(s1) + 1));
	while (s1[i])
	{
		tmp[i] = ft_strdup(s1[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
