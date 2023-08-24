/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 20:46:32 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/22 21:37:34 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

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

static void	ft_isdigit_cons(t_tmp *t)
{
	t->ret = 0;
	if (t->new_s[t->i] == '+' \
		&& t->i == 0 && t->flag != 1 && ft_strlen(t->new_s) > 0)
		t->i++;
	if (t->new_s[t->i] >= '0' && t->new_s[t->i] <= '9' && t->flag != 1)
	{
		t->flag2 = 1;
		t->i++;
		t->ret = 1;
	}
}

int	ft_isdigit(char *s)
{
	t_tmp	t;

	ft_bzero(&t, sizeof(t_tmp));
	if (!s || !*s)
		return (0);
	t.new_s = ft_strtrim(s, " ");
	while (t.new_s[t.i])
	{
		if (t.new_s[t.i] == ' ')
		{
			t.flag = 1;
			if (t.flag2 == 1)
				return (free(t.new_s), 0);
		}
		ft_isdigit_cons(&t);
		if (t.ret == 0)
			return (free(t.new_s), 0);
	}
	if (t.i == 0)
		return (free(t.new_s), 0);
	return (free(t.new_s), 1);
}
