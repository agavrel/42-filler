/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrlong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:09:17 by qfremeau          #+#    #+#             */
/*   Updated: 2016/06/23 14:10:25 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrlong(long long int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == (-9223372036854775807 - 1))
		{
			ft_putstr("9223372036854775808");
			return ;
		}
		nb = -nb;
	}
	if (nb < 10)
		ft_putchar(48 + nb);
	else
	{
		ft_putnbrlong(nb / 10);
		ft_putnbrlong(nb % 10);
	}
}
