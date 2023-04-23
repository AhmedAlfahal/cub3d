/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putunbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:41:11 by aalfahal          #+#    #+#             */
/*   Updated: 2022/11/12 19:01:55 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putunbr(unsigned long nb)
{
	int	counter;

	counter = 0;
	if (nb >= 10)
	{
		counter += ft_putnbr(nb / 10);
		counter += ft_printf_putchr((nb % 10) + '0');
	}
	else
		counter += ft_printf_putchr(nb + '0');
	return (counter);
}
