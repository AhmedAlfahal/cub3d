/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmohamed <hmohamed@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 02:08:40 by aalfahal          #+#    #+#             */
/*   Updated: 2023/09/05 16:43:44 by hmohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define WIDTH 1500
# define HIGHT 900

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

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
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_map
{
	char		*s1;
	char		**file;
	char		**map;
	char		**tmp_map;
	char		**tmp_text_names;
	char		**textures;
	int			*f_c_rgb;
	int			*counters;
	int			map_width;
	int			map_height;
	int			error;
	int			angel;
	t_img		no_tx;
	t_img		so_tx;
	t_img		ea_tx;
	t_img		we_tx;
	int			i;
	int			j;
	int			x0;
	int			y0;
	double		p_x;
	double		pp_x;
	double		p_y;
	double		pp_y;
	double		h_x;
	double		h_y;
	double		h_len;
	double		v_len;
	double		dest;
	double		v_x;
	double		v_y;
	double		x_w;
	double		y_w;
	double		x_stp;
	double		l_h;
	double		l_rh;
	double		rray;
	double		r_angel;
}			t_map;

typedef struct s_line
{
	int		x0;
	int		y0;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	int		x1;
	int		y1;
	int		dof;
	double	atan;
	double	ntan;
	double	l_rdx;
	double	l_rdy;
	double	lof;
	double	y_w;
	int		p_o;
	double	ss;

}			t_line;

typedef struct s_cub3d
{
	struct s_mlx		*mlx;
	struct s_img		*img;
	struct s_map		*map;
}						t_cub3d;

/******************************Pars_utils********************************/

void	reading_map(char *s, t_cub3d *c);
void	player_condition(t_map *m, int i, int j);
void	*check_in_tmp2d(t_cub3d *c, char *tmp, char ***texture);
void	check_map_at_end(t_cub3d *c);
void	cutting_text(t_cub3d *c, char *tmp, int i);
void	check_file_elements(t_cub3d *c);
void	check_map_element(t_map *m);

/******************************Render_utils******************************/

int		rgb_to_int(int red, int green, int blue);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
void	render(t_cub3d *c);
void	draw_3dmap(t_cub3d *c);
void	draw_3dmap_lines(t_cub3d *c, t_img *txtr, double pow);
double	deg_to_rad(double deg);
double	rad_to_deg(double rad);
void	line_loop(t_cub3d *c, t_line *ln, int line_color);
double	hor_line(t_cub3d *c);
double	ver_line(t_cub3d *c);
void	draw_lines_ex(t_cub3d *c);
void	drawline(t_cub3d *c, int x1, int y1, int line_color);
void	draw_lines(t_cub3d *c);
void	drawline3d(t_cub3d *c, int x1, int y1, int line_color);
void	drawline3d_w(t_cub3d *c, int x1, int y1, t_img *txtr);
void	draw_3dmap_lines_ex(t_cub3d *c, t_img *txtr);

/******************************Free_utils********************************/

void	clean_exit(t_cub3d *c, int msg, int ex);
void	closing_and_freeing(t_map *map, int fd, char *line, int ext);
void	free_2d_array(char **map);
void	check_text_error(t_cub3d *c);

#endif