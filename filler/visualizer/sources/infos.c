/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 17:13:21 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 06:19:59 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

static void	draw_info_part2(t_env *env)
{
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->seed_rand,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 221, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
	free(env->seed_rand);
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->name_p1,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 256, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->name_p2,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 281, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
}

void		draw_infos(t_env *env)
{
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->map_name,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	free(env->map_name);
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 171, env->s_tmp->w, env->s_tmp->h});
	SDL_FreeSurface(env->s_tmp);
	env->s_tmp = TTF_RenderText_Shaded(env->font[2], env->t_ny,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_tmp, &(SDL_Rect){0, 0, env->s_tmp->w, env->s_tmp->h},
	env->s_back, &(SDL_Rect){151, 196, env->s_tmp->w, env->s_tmp->h});
	env->map_name = ft_strjoin(" x ", env->t_nx, 'R');
	env->s_t2 = TTF_RenderText_Shaded(env->font[2], env->map_name,
	(SDL_Color){103, 103, 103, 255}, (SDL_Color){55, 55, 55, 255});
	SDL_LowerBlit(env->s_t2, &(SDL_Rect){0, 0, env->s_t2->w, env->s_t2->h},
	env->s_back, &(SDL_Rect){151 + env->s_tmp->w, 196, env->s_t2->w,
	env->s_t2->h});
	SDL_FreeSurface(env->s_t2);
	SDL_FreeSurface(env->s_tmp);
	free(env->map_name);
	free(env->t_ny);
	draw_info_part2(env);
}
