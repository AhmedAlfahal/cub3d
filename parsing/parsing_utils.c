/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:06:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/26 11:22:20 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	val(t_cub3d *c, char **rgb, const char *va, int n)
{
	long	res;

	res = 0;
	while (va[n] == '0' && va[n] != '\0')
		n++;
	while (va[n] != '\0' && va[n] >= '0' && va[n] <= '9')
	{
		res = (res * 10) + (va[n] - '0');
			n++;
		if (res > 255 || res < 0)
		{
			free_2d_array(rgb);
			clean_exit(c, 5, 1);
		}
	}
	return (res);
}

static int	ft_ai(t_cub3d *c, char **rgb, const char *str)
{
	int					i;
	int					sgn;
	long long			res;

	i = 0;
	sgn = 1;
	res = 0;
	while (str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		else if (str[i] == '-')
				sgn = -1;
			i++;
	}
	res = val (c, rgb, str, i);
	return (res * sgn);
}

static void	assigning_rgb(t_cub3d *c, char **rgb, int c_f)
{
	if (c_f == 0)
	{
		c->map->f_c_rgb[c_r] = ft_ai(c, rgb, rgb[0]);
		c->map->f_c_rgb[c_g] = ft_ai(c, rgb, rgb[1]);
		c->map->f_c_rgb[c_b] = ft_ai(c, rgb, rgb[2]);
	}
	else
	{
		c->map->f_c_rgb[f_r] = ft_ai(c, rgb, rgb[0]);
		c->map->f_c_rgb[f_g] = ft_ai(c, rgb, rgb[1]);
		c->map->f_c_rgb[f_b] = ft_ai(c, rgb, rgb[2]);
	}
}

static void	cut_rgbs(t_cub3d *c, char *tmp)
{
	int		c_f;
	char	*s;
	char	**rgb;

	s = skip_space(tmp);
	c_f = 0;
	if (*s == 'F')
		c_f = 1;
	s++;
	s = skip_space(s);
	if (!s)
		return ;
	rgb = ft_split(s, ',');
	if (ft_strlen_2d(rgb) != 3)
	{
		free_2d_array(rgb);
		clean_exit(c, 5, 1);
	}
	assigning_rgb(c, rgb, c_f);
	free_2d_array(rgb);
}

void	cutting_text(t_cub3d *cc, char *tmp, int i)
{
	if (i >= no && i <= ea)
	{
		free(cc->map->textures[i]);
		cc->map->textures[i] = ft_substr(skip_space(tmp), \
		next_space(skip_space(tmp)) + 1, ft_strlen(tmp));
	}
	else if (i == f || i == c)
		cut_rgbs(cc, tmp);
}
