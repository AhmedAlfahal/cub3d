# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/01 23:54:55 by aalfahal          #+#    #+#              #
#    Updated: 2023/08/01 15:12:28 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

CC		= 	cc

CFLAGS	= 	-Wall -Wextra -Werror

OBJ		= 	ft_strnstr.c	\
			ft_strlen.c		\
			ft_strncmp.c	\
			ft_isdigit.c	\
			ft_strdup.c		\
			ft_split.c		\
			ft_bzero.c		\
			ft_strtrim.c	\
			ft_strchr.c		\
			ft_substr.c
			
OBJS 	= 	$(OBJ:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all
