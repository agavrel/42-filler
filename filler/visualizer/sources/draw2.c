/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 06:31:49 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/28 18:19:17 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

/*
** function added by angavrel
** radius_ratio is the size that we want for the lozenge
*/

int		ft_draw_lozenge(double radius, double radius_ratio, int y, int x)
{
	double rad;

	rad = radius * radius_ratio;
	if (((ft_abs(x) + ft_abs(y)) < ft_abs(rad))
	|| ((x > -rad && x < -rad * 1.5) || (x < rad && x > rad * 1.5)
	|| (y > -rad && y < -rad * 1.5) || (y < rad && y > rad * 1.5)))
		return (1);
	else
		return (0);
}

/*
** function modified by angavrel
*/

void	draw_pawn(t_env *env, short *pawn, t_index i)
{
	if (pawn[0] < 0 && pawn[0] >= -env->step)
		fsdl_draw_pt(env->s_back, color_cpu(env, (double)pawn[0], (double)env->step,
		env->color), i.x + pawn[1], i.y + pawn[2] + 25);
	else if (pawn[0] > 0 && pawn[0] <= env->step)
	{
		if (ft_draw_lozenge(env->radius, 0.25, i.y, i.x))
			fsdl_draw_pt(env->s_back, color_cpu(env, -pawn[0],
			env->step, env->color), i.x + pawn[1], i.y + pawn[2] + 25);
		else
			fsdl_draw_pt(env->s_back, color(env, pawn[0], env->step, env->color),
			i.x + pawn[1], i.y + pawn[2] + 25);
	}
	else
		fsdl_draw_pt(env->s_back, 0x454545, i.x + pawn[1], i.y + pawn[2] + 25);
}

/*
** function modified by angavrel
*/

void	draw_board(t_env *env, int y, int x)
{
	t_index	i;

	while (++y < env->ny)
	{
		x = -1;
		while (++x < env->nx)
		{
			i.y = -env->radius;
			while (++i.y < env->radius)
			{
				i.x = -env->radius;
				while (++i.x < env->radius)
					if (((i.x * i.x) + (i.y * i.y)) <= env->r_radius * 1.60)
						draw_pawn(env, env->tab[y][x], i);
			}
		}
	}
}
