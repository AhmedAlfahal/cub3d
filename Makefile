# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/20 05:39:39 by aalfahal          #+#    #+#              #
#    Updated: 2023/04/25 13:11:49 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror  -g3 -fsanitize=address

NAME	=	cub3d

LIBS	=	libft/libft.a get_next_line/gnl.a ft_printf/libftprintf.a

SRC		=	cub3d.c					\
			tmp_printers.c			\
			parsing/map_parsing.c	\
			parsing/free_utils.c	\
			parsing/errors.c

SRCS	=	$(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(SRCS)
	@make all -C ./ft_printf
	@make all -C ./libft
	@make all -C ./get_next_line
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) -o $(NAME)  
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