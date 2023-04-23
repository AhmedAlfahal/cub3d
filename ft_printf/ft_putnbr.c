/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:49:19 by aalfahal          #+#    #+#             */
/*   Updated: 2022/11/12 18:56:43 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int	counter;

	counter = 0;
	if (nb == -2147483648)
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_printf_putchr('8');
	}
	else if (nb >= 10)
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_printf_putchr((nb % 10) + '0');
	}
	else if (nb < 0)
	{
		counter += ft_printf_putchr('-');
		counter += ft_putnbr(nb / -1);
	}
	else
		counter += ft_printf_putchr(nb + '0');
	return (counter);
}
