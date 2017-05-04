/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_opencl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 11:45:49 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/04 15:24:35 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			cf(double *elem1, double elem2)
{
	*elem1 = elem2;
	return (1);
}

int			ci(short *elem1, int elem2)
{
	*elem1 = elem2;
	return (1);
}
