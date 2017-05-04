/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_alrdy_contained.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:42:39 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:41:14 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** check is array tab does already contain that val
*/

int		ft_is_alrdy_contained(int *tab, int size, int val, int index)
{
	int		i;

	i = size - index - 1;
	size--;
	while (i--)
		if (val == tab[size--])
			return (0);
	return (1);
}
