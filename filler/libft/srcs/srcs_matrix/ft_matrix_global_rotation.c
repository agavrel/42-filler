/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_global_rotation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:53:04 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 15:12:09 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

float	**ft_matrix_global_rotation(float **m, t_vector a)
{
	float	**tmp;

	tmp = ft_identity_matrix(0, 1);
	tmp[0][0] = cos(a.y) * cos(a.z);
	tmp[0][1] = cos(a.z) * sin(a.x) * sin(a.y) - cos(a.x) * sin(a.z);
	tmp[0][2] = cos(a.x) * cos(a.z) * sin(a.y) + sin(a.x) * sin(a.z);
	tmp[1][0] = cos(a.y) * sin(a.z);
	tmp[1][1] = cos(a.x) * cos(a.z) + sin(a.x) * sin(a.y) * sin(a.z);
	tmp[1][2] = -cos(a.z) * sin(a.x) + cos(a.x) * sin(a.y) * sin(a.z);
	tmp[2][0] = -sin(a.y);
	tmp[2][1] = cos(a.y) * sin(a.x);
	tmp[2][2] = cos(a.x) * cos(a.y);
	m = ft_factor_matrix_free(m, tmp, 'R');
	return (m);
}
