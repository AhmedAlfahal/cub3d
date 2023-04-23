# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 05:39:39 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/20 05:53:06 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	CC

CFLAGS	=	-Wall -Wextra -Werror  -g3 #-fsanitize=address

NAME	=	cub3d

MLX		=	-framework OpenGL -framework AppKit

LIBS	=	libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a mlx/libmlx.a

SRC		=	cub3d.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./ft_printf
	@make all -C ./libft
	@make all -C ./get_next_line
	@make -C ./mlx
	$(CC) $(CFLAGS) $(SRCS) $(MLX) $(LIBS) -o $(NAME)  
clean:
	@make clean -C ./ft_printf
	@make clean -C ./libft
	@make clean -C ./get_next_line
	@make clean -C ./mlx
	rm -fr $(SRCS)

fclean: clean
	@make fclean -C ./ft_printf
	@make fclean -C ./libft
	@make fclean -C ./get_next_line
	rm -fr $(NAME) 

re: fclean all