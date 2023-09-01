# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 05:39:39 by aalfahal          #+#    #+#              #
#    Updated: 2023/09/01 16:12:56 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	= 	-Wall -Wextra -Werror -g3

NAME	=	cub3D

LIBS	=	libft/libft.a get_next_line/gnl.a mlx/libmlx.a

MLX		=	-framework OpenGL -framework AppKit

SRC		=	cub3d.c						\
			parsing/file_parsing.c		\
			parsing/check_map.c			\
			parsing/free_utils.c		\
			parsing/errors.c			\
			parsing/rgb_utils.c			\
			execution/render.c			\
			execution/drawing_utils.c	\
			execution/lines.c			\
			execution/utils.c			\
			execution/3d_draw.c 
			

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./libft
	@make all -C ./get_next_line
	@make all -C ./mlx
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBS) -o $(NAME)
clean:
	@make clean -C ./libft
	@make clean -C ./get_next_line
	@make clean -C ./mlx
	rm -fr $(SRCS)

fclean: clean
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -fr $(NAME) 

re: fclean all