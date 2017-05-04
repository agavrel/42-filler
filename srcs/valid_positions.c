/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 21:07:50 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:44:51 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** try to put our piece in point (y, x).
** if successful add (save) the point to our list t_point **points
*/

int		put_piece(t_filler *f, BOARD, PIECE, t_point **points)
{
	t_index	i;
	int		score;

	score = 0;
	i.y = 0;
	while (i.y < f->max.y)
	{
		i.x = 0;
		while (i.x < f->max.x)
		{
			if ((score = is_valid_position(f, b, p, i)))
				add_point(points, i, score);
			++i.x;
		}
		++i.y;
	}
	return (1);
}

/*
** We try to determine is the piece is put in an invalid spot:
** extra if (pad.y + i.y - f->min_dim.y < 0 || pad.x + i.x - f->min_dim.x < 0)
** checks that we can indeed put the TOKEN on the board.
** 1) pad.y + i.y >= f->max.y || pad.x + i.x >= f->max.x checks that we don't go
** over the board size.
** 2) if there is already a computer (b[pad.y + i.y][pad.x + i.x] >> 1).
** 3) if there is the player (b[i.y + pad.y][i.x + pad.x] but
** number of connections go beyond 1  && ++connected > 1).
*/

int		is_valid_position(t_filler *f, BOARD, PIECE, t_index i)
{
	t_index	pad;
	int		connected;
	int		score;

	score = 0;
	connected = 0;
	pad.y = -1;
	while (++pad.y < f->piece_dim.y)
	{
		pad.x = -1;
		while (++pad.x < f->piece_dim.x)
		{
			if (p[pad.y][pad.x])
			{
				if (pad.y + i.y < f->min_dim.y || pad.x + i.x < f->min_dim.x
				|| pad.y + i.y >= f->max.y || pad.x + i.x >= f->max.x
				|| (b[pad.y + i.y][pad.x + i.x] >> 1)
				|| (b[i.y + pad.y][i.x + pad.x] && ++connected > 1))
					return (0);
				if (!b[i.y + pad.y][i.x + pad.x])
					score += scoring(f, b, pad.y + i.y, pad.x + i.x);
			}
		}
	}
	return (connected ? score : 0);
}

/*
** save a point inside the list
** create a new one if there was none before, else create a new one at the end
*/

void	add_point(t_point **points, t_index i, int score)
{
	t_point	*lst;

	if ((lst = *points))
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new_point(i, score);
	}
	else
		*points = new_point(i, score);
}

/*
** function to create a new (x, y) point inside the list
*/

t_point	*new_point(t_index i, int score)
{
	t_point	*point;

	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->i = i;
	point->score = score;
	point->next = NULL;
	return (point);
}

/*
** function to free our list once our piece is returned
*/

void	free_saved_positions(t_point **points)
{
	t_point	*lst;
	t_point	*tmp;

	lst = *points;
	while (lst)
	{
		tmp = lst;
		free(tmp);
		lst = lst->next;
	}
}
