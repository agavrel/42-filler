/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:26:10 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 18:19:33 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

/*
** -------------------------- External Headers ---------------------------------
*/

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <time.h>
# include <sys/time.h>

/*
** -------------------------- Internal Libraries -------------------------------
*/

# include "../libraries/fsdl/include/fsdl.h"
# include "../libraries/libft/include/libft.h"

/*
** -------------------------- Internal Frameworks ------------------------------
*/

# include "../frameworks/SDL2.framework/headers/SDL.h"
# include "../frameworks/SDL2_ttf.framework/headers/SDL_ttf.h"
# include "../frameworks/SDL2_image.framework/headers/SDL_image.h"

/*
** --------------------------- Internal Headers --------------------------------
*/

# include "parameters.h"
# include "infos_messages.h"
# include "errors_messages.h"
# include "structures.h"

/*
** -----------------------------------------------------------------------------
** ------------------------------- Sources -------------------------------------
** -----------------------------------------------------------------------------
*/

void		init_errors(t_env *r, int i);

void		init_colors_hex(t_env *env);
void		init_colors_rgb(t_env *env);
void		init_colors_hsv(t_env *env);
int		    color(t_env *env, double value, double round, short color);

int			init_environnement(t_env *env, int x);
void		init_window_elements(t_env *env);

void		get_infos(t_env *env, char *line, int fd);
void		get_file(t_env *env, short lns, char *line);

void		handle_events(t_env *env);

void		create_board(t_env *env, int y, int x);
int			create_window(t_env *env);

void		draw_board(t_env *env, int y, int x);
void		draw_step(t_env *env, int step, int y);
void		draw_infos(t_env *env);
void		draw_title_battle(t_env *env);
void		draw_progress_bar(t_env *env);
void		draw_time(t_env *env);

int			free_elements(t_env *env);
int			error(t_env *env, int t);

/*
** added by angavrel
*/

int		    color_cpu(t_env *env, double value, double round, short color);
void	    draw_pawn(t_env *env, short *pawn, t_index i);

#endif
