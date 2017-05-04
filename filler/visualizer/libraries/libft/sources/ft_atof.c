/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:54:58 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 04:54:30 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

double		ft_atof(char *str, int i)
{
	double		s;
	double		r;
	double		d;

	d = 1.;
	r = 0.;
	s = (str[i] == '-') ? -1. : 1.;
	(str[i] == '-' || str[i] == '+') ? i++ : i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		r = r * 10. + str[i++] - '0';
	(str[i] && str[i] == '.') ? i++ : 1;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && (d *= 10.) != 0.)
		r = r * 10. + str[i++] - '0';
	return ((r != 0.) ? (r = (r / d) * s) : (r /= d));
}
