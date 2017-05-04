/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:10:17 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 15:10:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_shade_color(int c, double n)
{
	t_rgb	rgb;

	n = (1 - ft_fclamp(n, 0, 1));
	rgb.r = ((int)(n * ((c >> 16) & 0xff)) << 16);
	rgb.g = ((int)(n * ((c >> 8) & 0xff)) << 8);
	rgb.b = n * (c & 0xff);
	return (rgb.r + rgb.g + rgb.b);
}
