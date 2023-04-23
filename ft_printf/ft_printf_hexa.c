/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:56:55 by aalfahal          #+#    #+#             */
/*   Updated: 2022/11/13 20:21:02 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hexa(unsigned int nb, int base)
{
	int				tmp;
	int				counter;

	counter = 0;
	if (nb > 15)
		counter += ft_printf_hexa(nb / 16, base);
	tmp = nb % 16;
	if (tmp < 10)
		counter += ft_printf_putchr(tmp + '0');
	else if (tmp >= 10)
		counter += ft_printf_putchr(tmp + base);
	return (counter);
}
