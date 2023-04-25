/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 12:06:26 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/25 13:08:40 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	val(const char *va, int sgn, int n, t_cub3d *c)
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
			clean_exit(c, 1, 1);
	}
	return (res);
}

static int	ft_ai(const char *str, t_cub3d *c)
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
	res = val (str, sgn, i, c);
	return (res * sgn);
}

static void	assigning_rgb(t_cub3d *c, char *s, char **rgb, int c_f)
{
	if (c_f == 0)
	{
		c->map->c_rgb = malloc(sizeof(int) * 4);
		ft_bzero(&c->map->c_rgb, sizeof(int) * 4);
		c->map->c_rgb[r] = rgb[r];
		c->map->c_rgb[g] = rgb[g];
		c->map->c_rgb[b] = rgb[b];
	}
	else
	{
		c->map->f_rgb = malloc(sizeof(int) * 4);
		ft_bzero(&c->map->f_rgb, sizeof(int) * 4);
		c->map->f_rgb[r] = rgb[r];
		c->map->f_rgb[g] = rgb[g];
		c->map->f_rgb[b] = rgb[b];
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
	assigning_rgb(c, s, rgb, c_f);
	free_2d_array(rgb);
}

void	cutting_text(t_cub3d *c, char *tmp, int i)
{
	if (i == 0)
		c->map->no_text = ft_substr(skip_space(tmp), \
		0, next_space(skip_space(tmp)));
	else if (i == 1)
		c->map->so_text = ft_substr(skip_space(tmp), \
		0, next_space(skip_space(tmp)));
	else if (i == 2)
		c->map->we_text = ft_substr(skip_space(tmp), \
		0, next_space(skip_space(tmp)));
	else if (i == 3)
		c->map->ea_text = ft_substr(skip_space(tmp), \
		0, next_space(skip_space(tmp)));
	else if (i == 4 || i == 5)
		cut_rgbs(c, tmp);
}
