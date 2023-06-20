/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:37:16 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/17 22:13:49 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb_to_int(int red, int green, int blue)
{
	int	color;

	color = 0;
	color |= (int)(red) << 16;
	color |= (int)(green) << 8;
	color |= (int)(blue);
	return (color);
}
