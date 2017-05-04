/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarray_is_sorted.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 16:20:43 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:41:25 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function to check that an int array is arranged by ascending ordered.
*/

int		ft_intarray_is_sorted(int *array, size_t array_size)
{
	size_t	i;

	i = 0;
	while (i < array_size - 1)
		if (array[i] > array[i + 1])
			return (0);
		else
			++i;
	return (1);
}
