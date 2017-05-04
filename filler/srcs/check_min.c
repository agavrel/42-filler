/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:49:43 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:50:19 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** functions to check x and y minimum and maximum point
** for both computer (b[i.y][i.x] >> 1) and player (b[i.y][i.x] & 1)
*/

void	init_min(t_filler *f)
{
	f->min_ply.y = (t_index) {.x = -1, .y = -1};
	f->min_ply.x = (t_index) {.x = -1, .y = -1};
	f->min_cpu.y = (t_index) {.x = -1, .y = -1};
	f->min_cpu.x = (t_index) {.x = -1, .y = -1};
	f->max_ply.y = (t_index) {.x = -1, .y = -1};
	f->max_ply.x = (t_index) {.x = -1, .y = -1};
	f->max_cpu.y = (t_index) {.x = -1, .y = -1};
	f->max_cpu.x = (t_index) {.x = -1, .y = -1};
}

void	check_min(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index	i;

	i.y = f->min_area.y - 1;
	while (++i.y < f->max_area.y + 1)
	{
		i.x = f->min_area.y - 1;
		while (++i.x < f->max_area.x + 1)
			if ((b[i.y][i.x] & 1) && f->min_ply.y.y == -1)
				f->min_ply.y = i;
			else if (b[i.y][i.x] >> 1 && f->min_cpu.y.y == -1)
				f->min_cpu.y = i;
	}
	i.x = f->min_area.x - 1;
	while (++i.x < f->max_area.x + 1)
	{
		i.y = f->min_area.y - 1;
		while (++i.y < f->max_area.y + 1)
			if ((b[i.y][i.x] & 1) && f->min_ply.x.y == -1)
				f->min_ply.x = i;
			else if (b[i.y][i.x] >> 1 && f->min_cpu.x.y == -1)
				f->min_cpu.x = i;
	}
}

void	check_max(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index	i;

	i.y = f->max_area.y;
	while (--i.y >= f->min_area.y + 1)
	{
		i.x = f->max_area.y;
		while (++i.x < f->max_area.x + 1)
			if ((b[i.y][i.x] & 1) && f->max_ply.y.y == -1)
				f->max_ply.y = i;
			else if (b[i.y][i.x] >> 1 && f->max_cpu.y.y == -1)
				f->max_cpu.y = i;
	}
	i.x = f->max_area.x;
	while (--i.x >= f->min_area.x + 1)
	{
		i.y = f->max_area.y;
		while (--i.y >= f->min_area.y + 1)
			if ((b[i.y][i.x] & 1) && f->max_cpu.x.y == -1)
				f->max_ply.x = i;
			else if (b[i.y][i.x] >> 1 && f->max_cpu.x.y == -1)
				f->max_cpu.x = i;
	}
}
