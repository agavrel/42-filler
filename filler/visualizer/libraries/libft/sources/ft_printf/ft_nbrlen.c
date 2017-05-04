/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:54:30 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:23 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlenbase(uintmax_t nb, int base)
{
	double	tmp;
	int		i;

	i = 1;
	tmp = (double)nb;
	while (tmp >= (uintmax_t)base)
	{
		++i;
		tmp /= base;
	}
	return (i);
}

int		ft_bitlen(intmax_t p)
{
	intmax_t	tmp;
	int			i;

	tmp = p;
	i = 0;
	while (tmp && ++i)
		tmp = tmp >> 1;
	if (!i)
		return (1);
	return (i);
}
