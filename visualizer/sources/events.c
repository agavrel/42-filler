/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:45:40 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/30 18:38:54 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	render_step(t_env *env)
{
	int	step;

	step = env->score[env->step][0] > env->score[env->step][1] ?
		env->score[env->step][0] : env->score[env->step][1];
	draw_board(env, -1, -1);
	draw_step(env, step, 660);
	draw_title_battle(env);
	draw_progress_bar(env);
}

static void	handle_keyboard_down(t_env *env)
{
	if ((CK_DW == SDLK_LEFT && env->step > 0) ||
	(CK_DW == SDLK_RIGHT && env->step < env->m_step))
	{
		(CK_DW == SDLK_LEFT && env->step > 0) ? --env->step : ++env->step;
		env->draw ^= 1;
		render_step(env);
	}
	else if (CK_DW == SDLK_LSHIFT || CK_DW == SDLK_RSHIFT || CK_DW == SDLK_TAB)
	{
		if (env->curr_clr == NB_CLR_R)
			env->curr_clr = 0;
		else
			++env->curr_clr;
		render_step(env);
	}
}

/*
** function modified by angavrel
*/

static void	handle_keyboard_up(t_env *env)
{
	if (CK_DW == SDLK_KP_ENTER || CK_DW == SDLK_RETURN ||
	CK_DW == SDLK_RETURN2 || CK_DW == SDLK_END)
	{
		env->draw ^= 1;
		env->play = env->draw;
	}
	else if (CK_DW == SDLK_1 || CK_DW == SDLK_2)
	{
		if (CK_DW == SDLK_1)
			(env->music ^= 1) == 1 ? system("afplay ./music/aivi_answer.mp3&") :
			system("killall afplay 2&>/dev/null >/dev/null");
		else
		{
			env->color ^= 1;
			render_step(env);
		}
	}
}

void		handle_events(t_env *env)
{
	if (env->event.window.event == SDL_WINDOWEVENT_CLOSE || (env->event.type ==
	SDL_KEYDOWN && env->event.key.keysym.sym == SDLK_ESCAPE))
	{
		system("killall afplay 2&>/dev/null >/dev/null");
		env->run = 0;
	}
	if (env->event.type == 0x300)
		handle_keyboard_down(env);
	if (env->event.type == 0x301)
		handle_keyboard_up(env);
}
