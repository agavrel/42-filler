/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 16:25:00 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/30 21:23:10 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

/*
** progress bar color
*/

void	init_colors_hex(t_env *env)
{
	env->hclr[0][0] = 0xa5c82d;
	env->hclr[0][1] = 0x3c9ac3;
	env->hclr[1][0] = 0xc8892e;
	env->hclr[1][1] = 0x7a55c9;
	env->hclr[2][0] = 0x28c8a0;
	env->hclr[2][1] = 0xc95251;
	env->hclr[3][0] = 0x2d8ec8;
	env->hclr[3][1] = 0xc9a736;
	env->hclr[4][0] = 0x15ca1b;
	env->hclr[4][1] = 0xca1521;
}

/*
** players name color
*/

void	init_colors_rgb(t_env *env)
{
	env->rclr[0][0] = (SDL_Color){165, 200, 45, 255};
	env->rclr[0][1] = (SDL_Color){60, 154, 195, 255};
	env->rclr[1][0] = (SDL_Color){200, 137, 46, 255};
	env->rclr[1][1] = (SDL_Color){121, 84, 201, 255};
	env->rclr[2][0] = (SDL_Color){40, 200, 160, 255};
	env->rclr[2][1] = (SDL_Color){201, 82, 81, 255};
	env->rclr[3][0] = (SDL_Color){45, 142, 200, 255};
	env->rclr[3][1] = (SDL_Color){201, 167, 54, 255};
	env->rclr[4][0] = (SDL_Color){21, 201, 27, 255};
	env->rclr[4][1] = (SDL_Color){201, 21, 21, 255};
}

/*
** board color 
*/

void	init_colors_hsv(t_env *env)
{
	env->clr[0][0] = 73.55;
	env->clr[0][1] = 0.7750;
	env->clr[0][2] = 198.22;
	env->clr[0][3] = 0.6923;
	env->clr[1][0] = 35.39;
	env->clr[1][1] = 0.77;
	env->clr[1][2] = 259.00;
	env->clr[1][3] = 0.58;
	env->clr[2][0] = 165.10;
	env->clr[2][1] = 0.801;
	env->clr[2][2] = 0.53;
	env->clr[2][3] = 0.5969;
	env->clr[3][0] = 202.50;
	env->clr[3][1] = 0.7750;
	env->clr[3][2] = 46.00;
	env->clr[3][3] = 0.73;
	env->clr[4][0] = 100;
	env->clr[4][1] = 0.75;
	env->clr[4][2] = 5;
	env->clr[4][3] = 0.75;
}

/*
** functions modified by angavrel
*/

int		color_cpu(t_env *env, double value, double round, short color)
{
	t_hsv	hsv;
	double	turn_ratio_p2;

	turn_ratio_p2 = -(double)(value / round);
	hsv.h = !color ? fmod(env->clr[env->curr_clr][2] + 360 - 100 *
	turn_ratio_p2, 360) : env->clr[env->curr_clr][2];
	hsv.s = 0.5 + fmod(5.0f * turn_ratio_p2, 0.5f);
	hsv.v = 1 - fmod(1.0f * turn_ratio_p2, 0.2f);
	return (ft_hsv_to_hex(hsv));
}

int		color(t_env *env, double value, double round, short color)
{
	t_hsv	hsv;
	double	turn_ratio;

	turn_ratio = (double)(value / round);
	hsv.h = !color ? fmod(env->clr[env->curr_clr][0] + 100 *
	turn_ratio, 360) : env->clr[env->curr_clr][0];
	hsv.s = 0.5 + fmod(5.0f * turn_ratio, 0.5f);
	hsv.v = 1 - fmod(1.0f * turn_ratio, 0.2f);
	return (ft_hsv_to_hex(hsv));
}
