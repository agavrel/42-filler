/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:31:41 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/29 16:46:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		create_board(t_env *env, int y, int x)
{
	env->tab = (short ***)malloc(sizeof(short **) * env->ny);
	while (++y < env->ny)
	{
		x = -1;
		env->tab[y] = (short **)malloc(sizeof(short *) * env->nx);
		while (++x < env->nx)
		{
			env->tab[y][x] = (short *)malloc(sizeof(short) * 4);
			env->tab[y][x][0] = 0;
			env->tab[y][x][1] = ((env->size * x) + env->sx) + 265.0;
			env->tab[y][x][2] = ((env->size * y) + env->sy);
			env->tab[y][x][3] = 0;
		}
	}
}

void		init_window_elements(t_env *env)
{
	env->cursor = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
	env->s_ui = IMG_Load("./assets/images/ui.png");
	env->font[0] = TTF_OpenFont("./assets/font/KohinoorDev-Bold.ttf", 24);
	env->font[1] = TTF_OpenFont("./assets/font/KohinoorDev-Regular.ttf", 22);
	env->font[2] = TTF_OpenFont("./assets/font/KohinoorDev-Regular.ttf", 16);
	env->s_back = SDL_GetWindowSurface(env->win);
	SDL_LowerBlit(env->s_ui, &(SDL_Rect){0, 0, env->win_w, env->win_h},
	env->s_back, &(SDL_Rect){0, 0, env->win_w, env->win_h});
	env->s_versus = TTF_RenderText_Shaded(env->font[1], "  VERSUS  ",
	(SDL_Color){107, 107, 107, 255}, (SDL_Color){62, 62, 62, 255});
	fsdl_fill_rect(env->s_back, (SDL_Rect){env->p_bar_s, 723,
	env->p_bar_w, 29}, 0x353535);
	SDL_SetCursor(env->cursor);
}

static void	init_values(t_env *env, double ratio, double bigger)
{
	env->t1 = round(D(D(D(WIN_W) - 365.0) / D(env->nx)));
	env->t2 = round(D(D(D(WIN_H) - 160.0) / D(env->ny)));
	env->size = (env->t1 <= env->t2) ? env->t1 : env->t2;
	env->sx = ((WIN_W - 265.0f - ((env->nx - 1) * env->size)) / 2.0f);
	env->sy = ((WIN_H - ((env->ny - 1) * env->size)) / 2.0f);
	if (env->sx >= 55.0f && (env->win_w -= (env->sx - 55.0f) * 2.0f) > -1)
		env->sx = 55.0f;
	ratio = (bigger > 140) ? 0.640f : ((0.00240f * bigger) + 0.40f);
	env->radius = (D(env->size) * ratio);
	env->dmtr = (D(env->radius) * 2.0f);
	env->r_radius = (D(env->radius) * D(env->radius));
	env->m_title = ((env->win_w - 265.0f) / 2.0f) + 265.0f;
	env->p_bar_w = env->win_w - 265.0f - (env->sx * 2.0f) + env->dmtr;
	env->p_bar_rw = env->win_w - 265.0f - (env->sx * 2.0f) + env->dmtr - 14.0f;
	env->p_bar_s = 265.0f + env->sx - env->radius;
	env->p_bar_rs = 265.0f + env->sx + 7 - env->radius;
	env->score_max = env->nx * env->ny;
	env->score_mmax = (env->nx * env->ny) * 2;
	env->size_tab = (((env->nx + 1) * env->ny) + 5);
	env->s_title = 0;
	env->m_step = 0;
	env->score_p1 = -1;
	env->score_p2 = -1;
	env->curr_clr = ft_rand(0, 4);
	env->tclear = env->m_title - 195;
}

int			init_environnement(t_env *env, int x)
{
	env->run = 1;
	env->play = 0;
	env->draw = 1;
	env->step = 0;
	env->parse = 1;
	env->win_w = WIN_W;
	env->win_h = WIN_H;
	env->music = 0;
	env->color = 1;
	init_colors_hsv(env);
	init_colors_hex(env);
	init_colors_rgb(env);
	init_values(env, 0, (env->nx >= env->ny) ? env->ny : env->nx);
	env->font = (TTF_Font **)malloc(sizeof(TTF_Font *) * 3);
	if (!(env->score = (short **)malloc(sizeof(short *) * env->score_mmax)))
		return (error(env, 0));
	while (++x < env->score_mmax)
	{
		if (!(env->score[x] = (short *)malloc(sizeof(short) * 2)))
			return (error(env, 0));
		env->score[x][0] = 0;
		env->score[x][1] = 0;
	}
	create_board(env, -1, -1);
	return (0);
}

void		init_errors(t_env *r, int i)
{
	if (!(r->err = (char **)malloc(sizeof(char *) * 3)))
		exit(2);
	i = (s(&r->err[0], MSG0) && s(&r->err[1], MSG1) && s(&r->err[2], MSG2))
	? 1 : 1;
}
