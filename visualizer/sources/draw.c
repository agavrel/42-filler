/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:24:36 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/30 16:36:45 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

/*
** function modified by angavrel
*/

void	draw_title_battle(t_env *env)
{
	fsdl_fill_rect(env->s_back, (SDL_Rect){env->tclear, 50, 480, 27}, 0x3e3e3e);
	env->p1 = ft_strf("%s (%d)", env->name_p1, env->score[env->step][0]);
	env->p2 = ft_strf("%s (%d)", env->name_p2, env->score[env->step][1]);
	env->s_p1 = TTF_RenderText_Shaded(env->font[0], env->p1,
	env->rclr[env->curr_clr][0], (SDL_Color){62, 62, 62, 255});
	env->s_p2 = TTF_RenderText_Shaded(env->font[0], env->p2,
	env->rclr[env->curr_clr][1], (SDL_Color){62, 62, 62, 255});
	if (!env->s_title)
		env->s_title = (env->m_title -
		(double)(env->s_p1->w + env->s_p2->w + env->s_versus->w) / 2.0f);
	SDL_LowerBlit(env->s_p1, &(SDL_Rect){0, 0, env->s_p1->w, env->s_p1->h},
	env->s_back, &(SDL_Rect){env->s_title, 45, env->s_p1->w, env->s_p1->h});
	SDL_LowerBlit(env->s_versus, &(SDL_Rect){0, 0, env->s_versus->w,
	env->s_versus->h}, env->s_back, &(SDL_Rect){env->s_title + env->s_p1->w,
	47, env->s_versus->w, env->s_versus->h});
	SDL_LowerBlit(env->s_p2, &(SDL_Rect){0, 0, env->s_p2->w, env->s_p2->h},
	env->s_back, &(SDL_Rect){env->s_title + env->s_p1->w + env->s_versus->w,
	45, env->s_p2->w, env->s_p2->h});
	SDL_FreeSurface(env->s_p1);
	SDL_FreeSurface(env->s_p2);
	free(env->p1);
	free(env->p2);
}

/*
** function modified by angavrel to display score as env>step
*/

void	draw_progress_bar(t_env *env)
{
	fsdl_fill_rect(env->s_back, (SDL_Rect){env->p_bar_rs, 730,
	env->p_bar_rw, 15}, 0x393939);
	env->p_p1 = (double)((double)env->score[env->step][0] /
	((double)env->score_p1 + (double)env->score_p2)) * (double)env->p_bar_rw;
	env->p_p2 = (double)((double)env->score[env->step][1] /
	((double)env->score_p1 + (double)env->score_p2)) * (double)env->p_bar_rw;
	env->p_empty = env->p_bar_rw - env->p_p1 - env->p_p2;
	fsdl_fill_rect(env->s_back, (SDL_Rect){env->p_bar_rs,
	730, env->p_p1, 15}, env->hclr[env->curr_clr][0]);
	fsdl_fill_rect(env->s_back, (SDL_Rect){env->p_bar_rs + env->p_p1 +
	env->p_empty, 730, env->p_p2, 15}, env->hclr[env->curr_clr][1]);
}

void	draw_step(t_env *env, int step, int y)
{
	env->t_nx = ft_itoa(step);
	fsdl_fill_rect(env->s_back, (SDL_Rect){152, y + 6, 45, 11}, 0x373737);
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->t_nx,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, y, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
}

/*
** function modified by angavrel
*/

void	draw_time(t_env *env)
{
	gettimeofday(&env->tval_after, NULL);
	timersub(&env->tval_after, &env->tval_before, &env->tval_result);
	env->time = ft_strf("%ld.%06ld", (long int)env->tval_result.tv_sec,
	(long int)env->tval_result.tv_usec);
	fsdl_fill_rect(env->s_back, (SDL_Rect){152, 715, 80, 11}, 0x373737);
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->time,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 709, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
	free(env->time);
}
