# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 05:39:39 by aalfahal          #+#    #+#              #
#    Updated: 2023/07/28 17:44:12 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-g3 -Wall -Wextra -Werror -fsanitize=address

NAME	=	cub3d

LIBS	=	libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a mlx/libmlx.a

MLX		=	-framework OpenGL -framework AppKit

SRC		=	cub3d.c						\
			tmp_printers.c				\
			parsing/file_parsing.c		\
			parsing/check_map.c			\
			parsing/parsing_utils.c		\
			parsing/free_utils.c		\
			parsing/errors.c			\
			parsing/errors2.c			\
			parsing/rgb_utils.c			\
			execution/render.c			\
			execution/drawing_utils.c	\
			execution/deg_red.c			\
			execution/lines.c			\
			execution/utils.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./ft_printf
	@make all -C ./libft
	@make all -C ./get_next_line
	@make all -C ./mlx
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBS) -o $(NAME)
clean:
	@make clean -C ./ft_printf
	@make clean -C ./libft
	@make clean -C ./get_next_line
	rm -fr $(SRCS)

fclean: clean
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -fr $(NAME) 

re: fclean all