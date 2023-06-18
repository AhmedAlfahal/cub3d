/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deg_red.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalfahal <aalfahal@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 20:07:21 by aalfahal          #+#    #+#             */
/*   Updated: 2023/06/18 20:12:29 by aalfahal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	deg_to_rad(double deg)
{
	return (deg * (0x3F / 180));
}

double	rad_to_deg(double rad)
{
	return (rad * (180 / 0x3F));
}
