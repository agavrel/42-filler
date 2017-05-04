/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 21:07:28 by angavrel          #+#    #+#             */
/*   Updated: 2017/04/15 03:50:42 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <time.h>

/*
** Board and Piece are saved on the stack
*/

# define BOARD		int b[f->max.y][f->max.x]
# define PIECE		int p[f->piece_dim.y][f->piece_dim.x]

/*
** relative position of player compared to cpu.
*/

# define POSITION	f->position
# define SE			3
# define SW			1
# define NE			9
# define NW			7
# define E			6
# define W			4
# define S			2
# define N			8

/*
** other usefull define
** SKIP_LINE to skip useless lines
** LAST it the last point sent to the Virtual Machine
** Exit messg is to exit;
*/

# define SKIP_LINE	get_next_line(0, &line)
# define PLY		f->player
# define LAST 		f->last_p

/*
** structure to rate each area (nw = north west, c = center etc.)
*/

typedef struct		s_area
{
	float			nw;
	float			n;
	float			ne;
	float			e;
	float			se;
	float			s;
	float			sw;
	float			w;
	float			c;
}					t_area;

typedef struct		s_areav
{
	t_area			p1;
	t_area			p2;
	t_area			empty;
}					t_areav;

/*
** structure for (y, x) points
*/

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_index2
{
	t_index			x;
	t_index			y;
}					t_index2;

/*
** this list saved all valid positions
*/

typedef struct		s_point
{
	t_index			i;
	int				score;
	struct s_point	*next;
}					t_point;

/*
** board is the board stocked as char* while b is the board as int *
** max is max dimension y and x of the board
** player is the position of the player.
*/

typedef struct		s_filler
{
	int				cpu;
	int				player;
	char			*cpu_name;
	char			*ply_name;
	int				turn;
	t_index			max;
	t_index			last_p;
	int				cpu_score;
	int				ply_score;
	int				position;
	t_index			dir;
	t_index			piece_dim;
	t_index			min_dim;
	t_index			max_dim;
	int				ver_hor;
	t_index			min_area;
	t_index			max_area;
	t_index2		min_ply;
	t_index2		max_ply;
	t_index2		min_cpu;
	t_index2		max_cpu;
	int				goal;
	int				score;
	int				tolerance;
	t_areav			area;
}					t_filler;

/*
** initialization and parsing functions ~ main.c
*/

void				filler_loop(t_filler *filler);
void				board_char2int(t_filler *f, char *s, int y,
						int b[f->max.y][f->max.x]);
t_index				ft_check_min(t_filler *f, int b[f->max.y][f->max.x]);
void				check_max_area(t_filler *f, int b[f->max.y][f->max.x]);
void				init_min(t_filler *f);
void				check_min(t_filler *f, int b[f->max.y][f->max.x]);
void				check_max(t_filler *f, int b[f->max.y][f->max.x]);

/*
** parsing and triming piece ~ parse.c
*/

void				get_piece_dimension(t_filler *f, char *line,
						int b[f->max.y][f->max.x]);
t_index				ft_check_min_piece(t_filler *f,
						int p[f->piece_dim.y][f->piece_dim.x]);
void				trim_piece(t_filler *f,
						int p[f->piece_dim.y][f->piece_dim.x]);
void				filler_atoi(t_index *i, char *s);
void				return_piece(int a, int b);

/*
** solving algos ~ solver.c
*/

void				solver(t_filler *f, int b[f->max.y][f->max.x],
						int p[f->piece_dim.y][f->piece_dim.x]);
void				surround(t_filler *f, int b[f->max.y][f->max.x],
						t_point *points);
int					g_d(t_filler *f, int b[f->max.y][f->max.x], t_index p);
int					next_to_cpu(t_filler *f,
						int b[f->max.y][f->max.x], t_index i);

/*
** PLAN B: break_through algo ~ break_through.c
*/

void				get_board_picture(t_filler *f, int b[f->max.y][f->max.x]);
int					has_captured_center(t_filler *f, int b[f->max.y][f->max.x]);
int					get_relative_position(t_filler *f, t_index cpu_area,
						t_index i);
void				get_direction(t_filler *f, int b[f->max.y][f->max.x]);
void				break_through(t_filler *f, int b[f->max.y][f->max.x],
						t_point *points);

/*
** checks if sides are reached
*/

int					go_top(t_filler *f, int b[f->max.y][f->max.x], t_index i);
int					go_bot(t_filler *f, int b[f->max.y][f->max.x], t_index i);
int					go_left(t_filler *f, int b[f->max.y][f->max.x], t_index i);
int					go_right(t_filler *f, int b[f->max.y][f->max.x],
						t_index i);
void				has_reached_borders(t_filler *f,
						int b[f->max.y][f->max.x]);

/*
** scoring system when trying to reach sides
*/

int					scoring(t_filler *f, int b[f->max.y][f->max.x],
						int y, int x);
int					score_bot(t_filler *f,
						int b[f->max.y][f->max.x], t_index p);
int					score_left(t_filler *f,
						int b[f->max.y][f->max.x], t_index p);
int					score_right(t_filler *f,
						int b[f->max.y][f->max.x], t_index p);
int					score_top_left(t_filler *f,
						int b[f->max.y][f->max.x], t_index p);
int					score_top_right(t_filler *f,
						int b[f->max.y][f->max.x], t_index p);

/*
** Save relevant (y, x) valid positions inside a list ~ valid_positions.c
*/

int					put_piece(t_filler *f, int b[f->max.y][f->max.x],
					int p[f->piece_dim.y][f->piece_dim.x], t_point **points);
int					is_valid_position(t_filler *f, int b[f->max.y][f->max.x],
						int p[f->piece_dim.y][f->piece_dim.x], t_index c);
void				add_point(t_point **points, t_index i, int score);
t_point				*new_point(t_index i, int score);
void				free_saved_positions(t_point **points);

#endif
