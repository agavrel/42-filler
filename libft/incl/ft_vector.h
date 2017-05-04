/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:48:55 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/28 06:26:21 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include "libft.h"
# include "ft_matrix.h"

/*
** Vectors
*/

float		vector_len(t_vector v);
t_vector	ft_vector_add(t_vector v, t_vector v2);
t_vector	ft_vector_sub(t_vector v, t_vector v2);
t_vector	ft_vector_mult(t_vector v, t_vector v2);
t_vector	ft_vector_scaling(t_vector v, double n);

#endif
