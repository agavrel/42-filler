/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:33:17 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 11:27:25 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/*
** file modified by angavrel
*/

typedef struct		s_index
{
	int				x;
	int				y;
}					t_index;

typedef struct		s_env
{
	char			**err;
	SDL_Window		*win;
	char			*tmp;
	SDL_Event		event;
	SDL_Cursor		*cursor;
	SDL_Surface		*w_icon;
	SDL_Surface		*s_back;
	SDL_Surface		*s_tmp;
	SDL_Surface		*s_t2;
	SDL_Surface		*s_ui;
	TTF_Font		**font;
	int				x;
	int				y;
	int				mx;
	int				my;
	int				nx;
	int				ny;
	int				sx;
	int				sy;
	int				t1;
	int				t2;
	int				size;
	int				radius;
	int				dmtr;
	int				r_radius;
	int				fd;
	double			m_title;
	double			s_title;
	char			*p1;
	char			*p2;
	short			p_p1;
	short			p_p2;
	short			p_empty;
	char			*name_p1;
	char			*name_p2;
	short			score_p1;
	short			score_p2;
	short			tmp_p1;
	short			tmp_p2;
	short			score_max;
	short			score_mmax;
	SDL_Surface		*s_p1;
	SDL_Surface		*s_p2;
	SDL_Surface		*s_versus;
	short			step;
	short			win_w;
	short			win_h;
	short			draw;
	short			p_bar_w;
	short			p_bar_rw;
	short			p_bar_s;
	short			p_bar_rs;
	short			error;
	short			size_tab;
	short			parse;
	short			***tab;
	short			value_clr_p1;
	short			value_clr_p2;
	char			*map_name;
	char			*seed_rand;
	char			*t_ny;
	char			*t_nx;
	short			m_step;
	short			play;
	short			**score;
	short			curr_clr;
	double			clr[NB_CLRS][4];
	int				hclr[NB_CLRS][2];
	SDL_Color		rclr[NB_CLRS][2];
	struct timeval	tval_before;
	struct timeval	tval_after;
	struct timeval	tval_result;
	char			*time;
	short			tclear;
	char			run;
	short			color;
	short			music;
}					t_env;

#endif
