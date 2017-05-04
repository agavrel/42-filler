/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 00:54:16 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:44:36 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** we try to reach sides depending on starting position
*/

void	has_reached_borders(t_filler *f, int b[f->max.y][f->max.x])
{
	get_board_picture(f, b);
	if (f->min_ply.y.y == 0)
		f->goal &= ~1;
	else if (f->max_ply.y.y == f->max.y - 1)
		f->goal &= ~8;
	if (f->min_ply.x.x == 0)
		f->goal &= ~2;
	else if (f->max_ply.x.x == f->max.x - 1)
		f->goal &= ~4;
}

/*
** check if we are in the central area compared to cpu
** we light bit 1 if player 1 and bit 2 for player 2.
** if both bits are lighted on a row or on a column we are close enough
*/

int		has_captured_center(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index	i;
	int		check;

	i.y = f->min_area.y - 1;
	while (++i.y < f->max_area.y)
	{
		i.x = f->min_area.x - 1;
		check = 0;
		while (++i.x < f->max_area.x)
			check |= b[i.y][i.x];
		if ((check & 1) && (check & 2))
			return (1);
	}
	i.x = f->min_area.x - 1;
	while (++i.x < f->max_area.x)
	{
		i.y = f->min_area.y - 1;
		check = 0;
		while (++i.y < f->max_area.y)
			check |= b[i.y][i.x];
		if ((check & 1) && (check & 2))
			return (1);
	}
	return (0);
}
