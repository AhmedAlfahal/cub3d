/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pntr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal < aalfahal@student.42abudhabi.ae> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:21:57 by aalfahal          #+#    #+#             */
/*   Updated: 2022/11/13 20:52:56 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_pntr(unsigned long nb)
{
	int	tmp;
	int	counter;

	counter = 0;
	if (nb > 15)
		counter += ft_printf_pntr(nb / 16);
	tmp = nb % 16;
	if (tmp < 10)
		counter += ft_printf_putchr(tmp + '0');
	else if (tmp >= 10)
		counter += ft_printf_putchr(tmp + 'W');
	return (counter);
}
