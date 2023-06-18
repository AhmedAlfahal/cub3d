/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/18 20:13:17 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include"libft/libft.h"
# include"ft_printf/ft_printf.h"
# include"get_next_line/get_next_line.h"
# include"mlx/mlx.h"
# include<math.h>
# include<fcntl.h>

typedef enum color_type
{
	c_r,
	c_g,
	c_b,
	f_r,
	f_g,
	f_b,
}	t_color_type;

typedef enum directions
{
	no,
	so,
	we,
	ea,
	f,
	c,
	p_pos,
}	t_directions;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*player;
}			t_mlx;

typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_map
{
	char	*s1;
	char	**file;
	char	**map;
	char	**tmp_text_names;
	char	**textures;
	int		*f_c_rgb;
	int		*counters;
	int		map_width;
	int		map_height;
	int		error;
	int		angel;
	int		i;
	int		j;
	int		p_x;
	int		pp_x;
	int		p_y;
	int		pp_y;
}			t_map;

typedef struct s_cub3d
{
	struct s_mlx		*mlx;
	struct s_img		*img;
	struct s_map		*map;
}						t_cub3d;

/******************************Free_utils********************************/

int		next_space(char *s);
void	check_text_error(t_cub3d *c);
char	*skip_space(char *s);

/******************************Pars_utils********************************/

void	reading_map(char *s, t_cub3d *c);
void	*check_in_tmp2d(t_cub3d *c, char *tmp, char ***texture);
void	cutting_text(t_cub3d *c, char *tmp, int i);
void	check_file_elements(t_cub3d *c);
void	check_map_element(t_cub3d *c, char **map);
void	align_elements(t_cub3d *c);
void	mallocing_new(t_cub3d *c, int i);

/******************************Render_utils******************************/

int		rgb_to_int(int red, int green, int blue);
void	render(t_cub3d *c);
void	draw_object(t_cub3d *c, int pix_y, int color);
void	draw_map(t_cub3d *c);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);

/******************************Free_utils********************************/

void	clean_exit(t_cub3d *c, int msg, int ex);
void	closing_and_freeing(int fd, char *line, int ext);
void	free_2d_array(char **map);

/******************************Tmp_printers******************************/

void	print_2d_array(char **d);
void	print_counters(t_cub3d *c);

#endif