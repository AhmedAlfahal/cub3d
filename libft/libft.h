/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 18:15:57 by aalfahal          #+#    #+#             */
/*   Updated: 2023/08/04 18:14:29 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include<stdlib.h>
# include<unistd.h>
# include <stdint.h>

typedef struct s_tmp
{
	int		i;
	int		ret;
	int		flag;
	int		flag2;
	char	*new_s;
}	t_tmp;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strlen(const char *s);
int		ft_strlen_2d(char **s);
int		ft_commalen(char *s);
int		ft_isdigit(char *s);
void	remove_space(char *s);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_filecmp(const char *s1, const char *s2, int n);
char	*ft_strdup(const char *s1);
char	**ft_2d_dubpper(char **s1);
int		next_space(char *s);
char	*skip_space(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
