/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 17:36:47 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/30 18:36:23 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void		get_infos(t_env *env, char *line, int fd)
{
	fd = open("/tmp/filler.dat", O_RDWR);
	get_next_line(fd, &line);
	env->map_name = ft_name(line, "");
	free(line);
	get_next_line(fd, &line);
	env->ny = ft_atoi(line, 0);
	env->t_ny = ft_strdup(line);
	free(line);
	get_next_line(fd, &line);
	env->nx = ft_atoi(line, 0);
	env->t_nx = ft_strdup(line);
	free(line);
	get_next_line(fd, &line);
	env->seed_rand = ft_strdup(line);
	free(line);
	get_next_line(fd, &line);
	env->name_p1 = ft_name(line, ".filler");
	free(line);
	get_next_line(fd, &line);
	env->name_p2 = ft_name(line, ".filler");
	free(line);
}

/*
** functions modified by angavrel line 50 56
*/

static void	stock_line(t_env *env, int y, char *line, int x)
{
	while (line[++x])
	{
		if ((line[x] == 'O' || line[x] == 'o') && !env->tab[y][x][0])
		{
			++env->tmp_p1;
			env->tab[y][x][0] = env->m_step + 1;
			env->tab[y][x][3] = env->value_clr_p1;
		}
		else if ((line[x] == 'X' || line[x] == 'x') && !env->tab[y][x][0])
		{
			++env->tmp_p2;
			env->tab[y][x][0] = -(env->m_step + 1);
			env->tab[y][x][3] = env->value_clr_p2;
		}
	}
	free(line);
}

/*
** functions modified by angavrel line and 73 74, 84 85
*/

void		get_file(t_env *env, short lns, char *line)
{
	if (lseek(env->fd,
	((env->m_step * env->size_tab + 5) * sizeof(char)), 0) < 0 && ++env->error)
		return ;
	env->tmp_p1 = 0;
	env->tmp_p2 = 0;
	while (++lns < env->ny && get_next_line(env->fd, &line) > 0)
	{
		if (ft_strcmp(line, "END_OF_BATTLE", 0) && (env->parse = 0) != -1)
		{
			free(line);
			return ;
		}
		stock_line(env, lns, line, -1);
	}
	env->tmp_p1 ? ++env->score_p1 : 0;
	env->tmp_p2 ? ++env->score_p2 : 0;
	env->score[env->m_step + 1][0] = env->score_p1;
	env->score[env->m_step + 1][1] = env->score_p2;
	(lns == env->ny && (env->error = 0) != -1 && ++env->m_step && env->draw) ?
	++env->step : ++env->error;
	(((env->error + 1) % 20) == 0) ? usleep(20000) : 0;
	lns = env->score_p1 > env->score_p2 ? env->score_p1 : env->score_p2;
	draw_step(env, lns, 684);
	draw_time(env);
}
