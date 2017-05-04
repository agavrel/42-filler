/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:01:42 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/01 21:52:09 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FSDL_H
# define FSDL_H

# include "../../../frameworks/SDL2.framework/headers/SDL.h"

/*
** -----------------------------------------------------------------------------
** ------------------------------ Structures -----------------------------------
** -----------------------------------------------------------------------------
*/

typedef struct	s_line
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;
}				t_line;

/*
** -------------------------------- Timer --------------------------------------
*/

typedef	struct	s_timer
{
	int			fps;
	int			current;
	int			update;
	int			limit;
	char		title[128];
	unsigned	framelimit;
}				t_timer;

/*
** -----------------------------------------------------------------------------
** ------------------------------ Functions ------------------------------------
** -----------------------------------------------------------------------------
*/

void			fsdl_draw_pixel(SDL_Surface *dst, int x, int y, size_t clr);

void			fsdl_draw_pt(SDL_Surface *dst, size_t clr, int x, int y);

void			fsdl_draw_rect(SDL_Surface *dst, SDL_Rect rect, size_t clr);

void			fsdl_fill_rect(SDL_Surface *dst, SDL_Rect r, size_t clr);

int				fsdl_pt_in_rect(SDL_Point *p, SDL_Rect r);

void			fsdl_fps_counter(t_timer *fps);
void			fsdl_fps_limit(t_timer *fps);

#endif
