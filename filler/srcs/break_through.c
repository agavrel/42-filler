/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_through.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 14:56:39 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:46:26 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** try to break through to be fight on equal ground
*/

void	break_through(t_filler *f, int b[f->max.y][f->max.x], t_point *points)
{
	t_point	*tmp;

	f->score = 0;
	tmp = points;
	f->tolerance = 1;
	while (tmp)
	{
		if (tmp->score >= f->score)
		{
			LAST = tmp->i;
			f->score = tmp->score;
		}
		tmp = tmp->next;
	}
	if (f->score < 90)
	{
		surround(f, b, points);
	}
}

/*
** function try to decide if it is worth to to north direction, going through
** the right side or the left by taking the most critical points.
*/

int		go_top(t_filler *f, int b[f->max.y][f->max.x], t_index i)
{
	int	through_right;
	int through_left;

	through_right = score_top_left(f, b, i);
	through_left = score_top_right(f, b, i);
	through_right = through_right > through_left ? through_right : through_left;
	return (through_right);
}

int		go_bot(t_filler *f, int b[f->max.y][f->max.x], t_index i)
{
	int	through_right;
	int through_left;

	through_right = score_bot(f, b, i);
	through_left = score_bot(f, b, i);
	through_right = through_right > through_left ? through_right : through_left;
	return (through_right);
}

int		go_left(t_filler *f, int b[f->max.y][f->max.x], t_index i)
{
	int	bot;

	bot = score_left(f, b, i);
	return (bot);
}

int		go_right(t_filler *f, int b[f->max.y][f->max.x], t_index i)
{
	int	bot;

	bot = score_right(f, b, i);
	return (bot);
}
