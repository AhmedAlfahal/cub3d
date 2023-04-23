/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:50:49 by aalfahal          #+#    #+#             */
/*   Updated: 2023/01/30 18:46:15 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	persentages(char s1, va_list mylist)
{
	int	counter;

	counter = 0;
	if (s1 == 'd' || s1 == 'i')
		counter += ft_putnbr(va_arg(mylist, int));
	else if (s1 == 'c')
		counter += ft_printf_putchr(((char) va_arg(mylist, int)));
	else if (s1 == 's')
		counter += ft_putstr(va_arg(mylist, char *));
	else if (s1 == 'u')
		counter += ft_printf_putunbr(va_arg(mylist, unsigned int));
	else if (s1 == 'x')
		counter += ft_printf_hexa(va_arg(mylist, unsigned int), 'W');
	else if (s1 == 'X')
		counter += ft_printf_hexa(va_arg(mylist, unsigned int), '7');
	else if (s1 == 'p')
	{
		counter += ft_putstr("0x");
		counter += ft_printf_pntr(va_arg(mylist, unsigned long));
	}
	else if (s1 == '%')
		counter += ft_printf_putchr('%');
	return (counter);
}

int	ft_printf(const char *s1, ...)
{
	va_list	mylist;
	int		i;
	int		counter;

	i = 0;
	counter = 0;
	va_start(mylist, s1);
	while (s1[i] != 0)
	{
		if (s1[i] != '%')
			counter += ft_printf_putchr(s1[i]);
		if (s1[i++] == '%')
		{
			counter += persentages(s1[i], mylist);
			i++;
		}
	}
	va_end(mylist);
	return (counter);
}
