/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:57:46 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:19 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_abs(intmax_t nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int			ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int			ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}
