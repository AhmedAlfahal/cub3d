/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:41:11 by aalfahal          #+#    #+#             */
/*   Updated: 2023/01/30 16:40:18 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include"../libft/libft.h"

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
int		len(char *s);
t_list	*lst_new(char *content);
char	*join(char *s1, char *s2);
void	add_front(t_list **lst, t_list *new);
void	add_back(t_list **lst, char *content);
char	*read_lst(t_list **lst);
char	*cut(char *s, unsigned int start, size_t len);
int		line_len(char *s);

#endif