/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_scaling.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 21:00:56 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 14:44:54 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

float	**ft_matrix_scaling(float **m, t_vector scaling)
{
	float **tmp;

	tmp = ft_identity_matrix(0, 1);
	tmp[0][0] = scaling.x;
	tmp[1][1] = scaling.y;
	tmp[2][2] = scaling.z;
	m = ft_factor_matrix_free(m, tmp, 'R');
	return (m);
}
