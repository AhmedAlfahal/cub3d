/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 12:03:42 by aalfahal         ###   ########.fr       */
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

typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*player;
}			t_mlx;

typedef struct img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}			t_img;

typedef struct s_map
{
	char	**map;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		*f_rgb;
	int		*c_rgb;
}			t_map;

typedef struct s_cub3d
{
	struct mlx		*mlx;
	struct img		*img;
	struct map		*map;
}			t_cub3d;
#endif