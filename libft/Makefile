# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 23:54:55 by aalfahal          #+#    #+#              #
#    Updated: 2023/02/02 16:05:49 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

OBJ		= 	ft_strnstr.c ft_strlen.c ft_strncmp.c
			
OBJS 	= $(OBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
