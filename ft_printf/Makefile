# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 15:23:26 by aalfahal          #+#    #+#              #
#    Updated: 2023/01/22 23:35:31 by aalfahal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	cc

OBJ 	=	ft_printf.c				\
			ft_printf_putchr.c		\
			ft_putnbr.c				\
			ft_putstr.c				\
			ft_printf_putunbr.c		\
			ft_printf_hexa.c		\
			ft_printf_pntr.c		\

OBJS	=	$(OBJ:%.c=%.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -fr $(OBJS)

fclean: clean
	rm -fr $(NAME)

re: clean all