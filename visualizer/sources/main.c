/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:38:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/25 18:11:42 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int			main(void)
{
	t_env	env;

	usleep(20000);
	init_errors(&env, 0);
	env.fd = open("/tmp/board.dat", O_RDWR | O_SYNC);
	lseek(env.fd, 0L, 0);
	get_infos(&env, NULL, 0);
	return (create_window(&env));
}
