/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:54:27 by aalfahal          #+#    #+#             */
/*   Updated: 2022/11/15 17:35:54 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>

int	ft_putnbr(int nb);
int	ft_putstr(char *str);
int	ft_printf_putchr(char chr);
int	ft_printf(const char *s1, ...);
int	ft_printf_pntr(unsigned long nb);
int	ft_printf_putunbr(unsigned long nb);
int	ft_printf_hexa(unsigned int nb, int base);

#endif