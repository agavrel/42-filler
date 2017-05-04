/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:13:35 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/30 16:35:28 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	update_filler(t_env *env)
{
	int	step;

	step = env->score[env->step][0] > env->score[env->step][1] ?
		env->score[env->step][0] : env->score[env->step][1];
	env->value_clr_p1 = ft_rand(6300, 7843);
	env->value_clr_p2 = ft_rand(6300, 7647);
	if (env->parse)
		get_file(env, -1, NULL);
	if (env->draw)
	{
		draw_board(env, -1, -1);
		draw_step(env, step, 660);
		draw_title_battle(env);
		draw_progress_bar(env);
		if (!env->parse && !env->play)
			env->draw = 0;
		if (env->play && env->step < env->m_step)
			++env->step;
	}
}

static int	global_loop(t_env *env)
{
	while (env->run)
	{
		if (SDL_PollEvent(&env->event))
			handle_events(env);
		update_filler(env);
		SDL_UpdateWindowSurface(env->win);
	}
	return (free_elements(env));
}

int			create_window(t_env *env)
{
	TTF_Init();
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
		return (error(env, 29));
	if (!(env->w_icon = IMG_Load(WIN_ICON)))
		return (error(env, 32));
	if (init_environnement(env, -1) == -1)
		return (-1);
	if (!(env->win = SDL_CreateWindow("Filler Visualizer",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, env->win_w, env->win_h, 0)))
		return (error(env, 30));
	SDL_SetWindowIcon(env->win, env->w_icon);
	init_window_elements(env);
	draw_board(env, -1, -1);
	draw_title_battle(env);
	draw_progress_bar(env);
	draw_infos(env);
	gettimeofday(&env->tval_before, NULL);
	return (global_loop(env));
}
