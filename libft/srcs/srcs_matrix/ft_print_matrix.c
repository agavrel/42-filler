/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 20:46:02 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 14:45:35 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(float **m)
{
	t_i	i;

	i.y = 0;
	while (++i.y < 4)
	{
		i.x = 0;
		while (++i.x < 4)
		{
			if (!(m[i.y][i.x] - (int)m[i.y][i.x]))
				ft_printf("%.0f.0   ", m[i.y][i.x]);
			else
				ft_printf("%.1f   ", m[i.y][i.x]);
			++i.x;
		}
		ft_printf("\n");
		++i.y;
	}
}
