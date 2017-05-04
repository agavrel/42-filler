/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 01:57:21 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:47:24 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** check if there is a computer piece on the left side the following way:
**
** X
** . X
** X . O
** . .
** .
*/

/*
** can break bot or can close bot
*/

int		scoring(t_filler *f, int b[f->max.y][f->max.x], int y, int x)
{
	if ((y > 0 && (b[y - 1][x] >> 1) && f->max_cpu.y.y < y)
		|| (y < f->max.y - 1 && (b[y + 1][x] >> 1) && f->min_cpu.y.y > y)
		|| (x < f->max.x - 1 && (b[y][x + 1] >> 1))
		|| (x > 0 && (b[y][x - 1] >> 1))
		|| (x > 0 && (b[y][x - 1] >> 1) && f->max_cpu.x.x < x)
		|| (x < f->max.x - 1 && (b[y][x + 1] >> 1) && f->min_cpu.x.x > x)
		|| (y < f->max.y - 1 && (b[y + 1][x] >> 1))
		|| (y > 0 && (b[y - 1][x] >> 1)))
		return (99);
	return (1);
}

int		score_left(t_filler *f, int b[f->max.y][f->max.x], t_index p)
{
	t_index		i;
	int			range_i;
	int			range;

	range = 1;
	i.x = p.x;
	while (--i.x >= 0)
	{
		i.y = p.y;
		if (p.y - range <= 0)
			return (1);
		++range;
		range_i = 0;
		while (i.y >= 0 && range_i < range)
		{
			if (b[i.y][i.x] >> 1)
				return (i.y == p.y ? 0 : range);
			--i.y;
			++range_i;
		}
	}
	return (range);
}

int		score_right(t_filler *f, int b[f->max.y][f->max.x], t_index p)
{
	t_index		i;
	int			range_i;
	int			range;

	range = 1;
	i.x = p.x;
	while (++i.x < f->max.x)
	{
		i.y = p.y;
		if (range + p.y >= f->max.y - 1)
			return (1);
		++range;
		range_i = 0;
		while (i.y >= 0 && range_i < range)
		{
			if (b[i.y][i.x] >> 1)
				return (i.y == p.y ? 0 : range);
			--i.y;
			++range_i;
		}
	}
	return (range);
}

int		score_bot(t_filler *f, int b[f->max.y][f->max.x], t_index p)
{
	t_index		i;
	int			range_i;
	int			range;

	range = 1;
	i.y = p.y;
	while (++i.y < f->max.y)
	{
		i.x = p.x;
		if (range + p.x >= f->max.x - 1)
			return (1);
		++range;
		range_i = 0;
		while (i.x >= 0 && range_i < range)
		{
			if (b[i.y][i.x] >> 1)
				return (i.x == p.x ? 0 : range);
			--i.x;
			++range_i;
		}
	}
	return (range);
}
