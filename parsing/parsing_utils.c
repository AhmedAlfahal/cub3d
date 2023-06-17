/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 22:05:35 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/17 22:13:04 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
