/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:28:59 by fsidler           #+#    #+#             */
/*   Updated: 2017/03/09 18:01:20 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vec_para(t_vec *xyz, double x, double y, double z)
{
	xyz->x = x;
	xyz->y = y;
	xyz->z = z;
}

void	ft_rgb_para(t_rgb *rgb, int r, int g, int b)
{
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
}

void	ft_sinvec(t_vec *vec)
{
	vec->x = sin(vec->x);
	vec->y = sin(vec->y);
	vec->z = sin(vec->z);
}

void	ft_tanvec(t_vec *vec)
{
	vec->x = tan(vec->x);
	vec->y = tan(vec->y);
	vec->z = tan(vec->z);
}

double	v_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
