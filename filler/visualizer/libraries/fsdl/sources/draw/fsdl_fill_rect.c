/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl_fill_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:20:23 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/09 20:37:23 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void	fsdl_fill_rect(SDL_Surface *dst, SDL_Rect rect, size_t clr)
{
	short	x;
	short	y;

	y = rect.y - 1;
	rect.w = rect.x + rect.w;
	rect.h = rect.y + rect.h;
	while (++y < rect.h)
	{
		x = (rect.x - 1);
		while (++x < rect.w)
			*((unsigned *)(dst->pixels + y * dst->pitch + x *
			dst->format->BytesPerPixel)) = clr;
	}
}
