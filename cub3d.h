/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/04/23 16:41:09 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include"libft/libft.h"
# include"ft_printf/ft_printf.h"
# include"get_next_line/get_next_line.h"

# include<fcntl.h>

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
	char	**text_names;
	char	*no_text;
	char	*so_text;
	char	*we_text;
	char	*ea_text;
	int		*f_rgb;
	int		*c_rgb;
	int		i;
	int		j;
}			t_map;

typedef struct s_cub3d
{
	struct s_mlx		*mlx;
	struct s_img		*img;
	struct s_map		*map;
}			t_cub3d;

/******************************Pars_utils********************************/

void	reading_map(char *s, t_cub3d *c);
int		check_in_tmp2d(char *tmp, char **texture, int i);

/******************************Free_utils********************************/

void	clean_exit(t_map *map, int msg, int ex);
void	closing_and_freeing(int fd, char *line, int ext);
void	free_2d_array(char **map);

/******************************Tmp_printers******************************/

void	print_2d_array(char **d);

#endif