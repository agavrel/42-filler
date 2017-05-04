/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsb2rgb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:09:48 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/23 05:50:12 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"
#include "libft.h"

t_rgb	ft_hsv2rgb(t_hsv hsv)
{
	t_rgb		rgb;
	t_vector	i;

	i.w = (int)(hsv.h / 60);
	i.w = (hsv.h / 60) - i.w;
	i.x = 0xff * (hsv.v * (1 - hsv.s));
	i.y = 0xff * (hsv.v * (1 - i.w * hsv.s));
	i.z = 0xff * (hsv.v * (1 - (1 - i.w) * hsv.s));
	hsv.v *= 0xff;
	hsv.h = (int)((hsv.h) / 60);
	if (hsv.h == 0)
		rgb = (t_rgb) {.r = hsv.v, .g = i.z, .b = i.x};
	else if (hsv.h == 1)
		rgb = (t_rgb) {.r = i.y, .g = hsv.v, .b = i.x};
	else if (hsv.h == 2)
		rgb = (t_rgb) {.r = i.x, .g = hsv.v, .b = i.z};
	else if (hsv.h == 3)
		rgb = (t_rgb) {.r = i.x, .g = i.y, hsv.v};
	else if (hsv.h == 4)
		rgb = (t_rgb) {.r = i.z, .g = i.x, hsv.v};
	else if (hsv.h == 5)
		rgb = (t_rgb) {.r = hsv.v, .g = i.x, .b = i.y};
	else
		rgb = (t_rgb) {.r = 0, .g = 0, .b = 0};
	return (rgb);
}
