/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_z_scaling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:12:25 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 14:45:01 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_matrix.h"

float	**ft_matrix_z_scaling(float **matrix, float coefficient)
{
	matrix[0][2] *= coefficient;
	matrix[1][2] *= coefficient;
	return (matrix);
}
