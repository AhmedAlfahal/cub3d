/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 11:08:59 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include"libft/libft.h"
# include"ft_printf/ft_printf.h"
# include"get_next_line/get_next_line.h"
# include"mlx/mlx.h"

typedef enum color_type
{
	r,
	g,
	b,
}	t_color_type;

typedef struct s_cub3d
{
	char	**map;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		*f_rgb;
	int		*c_rgb;
}			t_cub3d;

#endif