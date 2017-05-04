/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 15:37:22 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/16 15:38:26 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** sl stands for sizeline; number of pixels per line
*/

void	ft_init_img(t_mlx *mlx)
{
	int	bpp;
	int	sl;
	int	endian;

	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &bpp, &sl, &endian);
	mlx->bpp = bpp;
	mlx->sl = sl;
	mlx->endian = endian;
}
