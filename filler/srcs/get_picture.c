/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_picture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:25:50 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:44:09 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	rate_area(t_index max, t_index i, t_area *area)
{
	if (i.y < max.y / 3)
	{
		if (i.x < max.x / 3)
			++area->nw;
		else if (i.x < (max.x << 1) / 3)
			++area->n;
		else
			++area->ne;
	}
	else if (i.y < (max.y << 1) / 3)
	{
		if (i.x < max.x / 3)
			++area->w;
		else if (i.x < (max.x << 1) / 3)
			++area->c;
		else
			++area->e;
	}
	else
	{
		if (i.x < max.x / 3)
			++area->sw;
		else
			(i.x < (max.x << 1) / 3) ? ++area->s : ++area->se;
	}
}

void	get_percent(t_index max, t_area *area)
{
	float map_size;

	map_size = max.x * max.y;
	area->nw /= (map_size / 9);
	area->n /= (map_size / 9);
	area->ne /= (map_size / 9);
	area->w /= (map_size / 9);
	area->c /= (map_size / 9);
	area->e /= (map_size / 9);
	area->sw /= (map_size / 9);
	area->s /= (map_size / 9);
	area->se /= (map_size / 9);
}

void	get_empty(t_areav *areav)
{
	areav->empty.nw = 1 - areav->p1.nw - areav->p2.nw;
	areav->empty.n = 1 - areav->p1.n - areav->p2.n;
	areav->empty.ne = 1 - areav->p1.ne - areav->p2.ne;
	areav->empty.w = 1 - areav->p1.w - areav->p2.w;
	areav->empty.c = 1 - areav->p1.c - areav->p2.c;
	areav->empty.e = 1 - areav->p1.e - areav->p2.e;
	areav->empty.sw = 1 - areav->p1.sw - areav->p2.sw;
	areav->empty.s = 1 - areav->p1.s - areav->p2.s;
	areav->empty.se = 1 - areav->p1.se - areav->p2.se;
}

/*
** function to check what should be the direction with 1 = North, 8 = South,
** 2 = West, 3 = East.
** f->tolerance is the margin we want to add
*/

void	get_goals(t_filler *f, int *goal, int ver_hor)
{
	float	c2;

	c2 = 0.7 * 3;
	*goal = 0;
	f->tolerance = 1;
	if (ver_hor >= 0)
	{
		if (f->min_ply.y.y > 0 && f->min_cpu.y.y -
				f->tolerance <= f->min_ply.y.y)
			*goal |= 1;
		else if (f->min_ply.y.y < f->max.y - 1
				&& f->max_ply.y.y <= f->max_cpu.y.y - f->tolerance)
			*goal |= 8;
	}
	if (ver_hor <= 0)
	{
		if (f->min_ply.x.x > 0
				&& f->max_ply.x.x <= f->max_cpu.x.x - f->tolerance)
			*goal |= 4;
		else if
			(f->min_ply.x.x < f->max.x
				&& f->min_cpu.x.x - f->tolerance <= f->min_ply.x.x)
			*goal |= 2;
	}
}

/*
** strategy involved if the opponent has placement superiority
*/

void	get_board_picture(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index		i;
	t_index		score;

	score = (t_index) {.x = 0, .y = 0};
	ft_bzero(&(f->area.p1), sizeof(t_area));
	ft_bzero(&(f->area.p2), sizeof(t_area));
	ft_bzero(&(f->area.empty), sizeof(t_area));
	i.y = f->min_area.y - 1;
	while (++i.y <= f->max_area.y)
	{
		i.x = f->min_area.x - 1;
		while (++i.x <= f->max_area.x)
		{
			if (b[i.y][i.x] >> 1)
				rate_area(f->max, i, &(f->area.p2));
			else if (b[i.y][i.x])
				rate_area(f->max, i, &(f->area.p1));
		}
	}
	get_percent(f->max, &(f->area.p1));
	get_percent(f->max, &(f->area.p2));
	get_empty(&(f->area));
	get_goals(f, &f->goal, f->ver_hor);
}
