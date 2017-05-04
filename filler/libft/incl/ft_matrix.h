/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:48:55 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/28 06:26:37 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include <math.h>
# include "libft.h"

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
	float		w;
}				t_vector;

/*
** Matrix
*/

void			ft_print_matrix(float **m);
float			**ft_identity_matrix(int fill, int fill_diagonal);
float			**ft_matrix_rotation(float x, char axis);
float			**ft_matrix_global_rotation(float **m, t_vector angle);
float			**ft_matrix_scaling(float **m, t_vector scaling);
float			**ft_matrix_z_scaling(float **matrix, float coefficient);
float			**ft_sum_matrix(float **a, float **b);
float			**ft_factor_matrix_free(float **a, float **b, char free);
t_vector		ft_matrix_to_vector(float **m, t_vector v, t_vector center);
void			ft_free_matrix(float **m);
float			**ft_copy_matrix(float **m);

#endif
