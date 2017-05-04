/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:27:05 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/04 15:23:55 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			i(int *elem1, int elem2)
{
	*elem1 = elem2;
	return (1);
}

int			d(double *elem1, double elem2)
{
	*elem1 = elem2;
	return (1);
}

int			h(t_vec *vec, unsigned hex)
{
	vec->x = ((hex >> 16) & 0xFF);
	vec->y = ((hex >> 8) & 0xFF);
	vec->z = ((hex) & 0xFF);
	return (1);
}

int			vc(t_vec *vec1, t_vec vec2)
{
	vec1->x = vec2.x;
	vec1->y = vec2.y;
	vec1->z = vec2.z;
	return (1);
}

int			s(char **elem1, char *elem2)
{
	*elem1 = elem2;
	return (1);
}
