/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 05:38:00 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/10 18:53:47 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** the fd of GNL is set to 0 as it is where VM sends information.
** compile program and then do one player match
** f->cpu = (f->player >> 1) equivalent to f->cpu = (f->player == 2)
** first get_next_line is for //$$$ exec p[1-2]
** second one is for //Plateau 14 17:
*/

int		main(void)
{
	t_filler	f;
	char		*line;

	get_next_line(0, &line);
	if (!line[10] || (line[10] != '1' && line[10] != '2'))
		return (ft_error("error about player position"));
	f.player = line[10] - '0';
	f.ply_name = &line[14];
	f.cpu = (f.player & 2) >> 1 | (f.player & 1) << 1;
	get_next_line(0, &line);
	f.max = (t_index) {.y = 0, .x = 0};
	filler_atoi(&f.max, line + 8);
	f.turn = 0;
	f.goal = 0;
	f.ply_score = 0;
	f.cpu_score = 0;
	while (1)
		filler_loop(&f);
	return (0);
}

/*
** first SKIP_LINE is used in order to skip "012345..."
** then we store into an array data related to the board shape
** second SKIP_LINE is to get piece dimensions (Piece 5 6)
** then we store into an array data related to the piece shape
** third SKIP_LINE is to skip Plateau as we already know board dimensions
*/

void	filler_loop(t_filler *f)
{
	t_index	i;
	char	*line;
	int		b[f->max.y][f->max.x];

	SKIP_LINE;
	i.y = -1;
	while (++i.y < f->max.y)
	{
		if (get_next_line(0, &line) == -1)
		{
			ft_error("GNL Error");
			exit(1);
		}
		board_char2int(f, line + 4, i.y, b);
	}
	f->min_area = ft_check_min(f, b);
	check_max_area(f, b);
	SKIP_LINE;
	f->piece_dim = (t_index) {.y = 0, .x = 0};
	filler_atoi(&f->piece_dim, line + 6);
	get_piece_dimension(f, line, b);
	SKIP_LINE;
	++f->turn;
}

/*
** function to convert the board into ints :
** 1 for Player and 2 for CPU, 0 if empty.
*/

void	board_char2int(t_filler *f, char *s, int y, int b[f->max.y][f->max.x])
{
	int	x;

	x = -1;
	while (s[++x])
		if (s[x] == 'O')
			b[y][x] = PLY;
		else if (s[x] == 'X')
			b[y][x] = (PLY & 2) >> 1 | (PLY & 1) << 1;
		else
			b[y][x] = 0;
}

/*
** function to check trimmed board limits (min point and max point)
*/

t_index	ft_check_min(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index	i;
	t_index	min;

	i.y = -1;
	min.y = -1;
	while (++i.y < f->max.y && min.y == -1)
	{
		i.x = -1;
		while (++i.x < f->max.x && min.y == -1)
			if (b[i.y][i.x])
				min.y = i.y;
	}
	i.x = -1;
	min.x = -1;
	while (++i.x < f->max.x && min.x == -1)
	{
		i.y = -1;
		while (++i.y < f->max.y && min.x == -1)
			if (b[i.y][i.x])
				min.x = i.x;
	}
	return (min);
}

void	check_max_area(t_filler *f, int b[f->max.y][f->max.x])
{
	t_index	i;

	i.y = f->max.y;
	f->max_area.y = -1;
	while (--i.y >= 0 && f->max_area.y == -1)
	{
		i.x = f->max.x;
		while (--i.x >= 0 && f->max_area.y == -1)
		{
			if (b[i.y][i.x])
				f->max_area.y = i.y;
		}
	}
	f->max_area.x = -1;
	i.x = f->max.x;
	while (--i.x >= 0 && f->max_area.x == -1)
	{
		i.y = f->max.y;
		while (--i.y >= 0 && f->max_area.x == -1)
		{
			if (b[i.y][i.x])
				f->max_area.x = i.x;
		}
	}
}
