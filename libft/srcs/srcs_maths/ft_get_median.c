/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_median.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:34:46 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:36:54 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** if position equals 0.5 returns median value.
** more generally if position > 0 returns n * position
** if position < 0 returns last value (-1), before last value (-2) etc.
*/

int		ft_get_median(int *tab, size_t size, float position)
{
	int		cpy[size];
	size_t	i;
	int		pos;

	i = 0;
	while (i < size)
	{
		cpy[i] = tab[i];
		++i;
	}
	i = 0;
	while (++i < size)
	{
		if (cpy[i - 1] > cpy[i])
		{
			ft_swap(&cpy[i - 1], &cpy[i]);
			i = 0;
		}
	}
	pos = (int)(position >= 0 ? (float)(size * position)
		: (float)(size + position));
	return (cpy[pos]);
}
