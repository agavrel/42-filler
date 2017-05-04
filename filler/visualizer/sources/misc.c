/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:24:06 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 14:00:49 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			error(t_env *env, int t)
{
	char	*s;

	s = NULL;
	if (t == 3 && write(2, "error : ", 8) &&
	write(2, strerror(errno), ft_strlen(strerror(errno))))
		write(2, ".\n", 2);
	(!s && t != 3) ? write(2, env->err[t], ft_strlen(env->err[t])) : 1;
	(s) ? (write(2, s, ft_strlen(s)) && write(2, ".\n", 2)) : 1;
	exit(1);
	return (1);
}

int			free_elements(t_env *env)
{
	system("rm -f /tmp/filler.dat");
	system("rm -f /tmp/board.dat");
	(void)env;
	exit(0);
	return (0);
}
