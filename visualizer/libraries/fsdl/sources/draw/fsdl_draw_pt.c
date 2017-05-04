/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl_draw_pt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:37:41 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/05 00:08:48 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void	fsdl_draw_pt(SDL_Surface *dst, size_t clr, int x, int y)
{
	*((unsigned *)(dst->pixels + y * dst->pitch + x *
	dst->format->BytesPerPixel)) = clr;
}
