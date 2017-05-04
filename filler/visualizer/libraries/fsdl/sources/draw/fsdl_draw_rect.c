/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl_draw_rect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 19:26:47 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/28 21:56:19 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

void	fsdl_draw_rect(SDL_Surface *dst, SDL_Rect rect, size_t clr)
{
	int		y;

	y = rect.y;
	rect.w = rect.x + rect.w;
	rect.h = rect.y + rect.h;
	while (y < rect.h)
	{
		*((unsigned *)(dst->pixels + y * dst->pitch + rect.x *
		dst->format->BytesPerPixel)) = clr;
		*((unsigned *)(dst->pixels + y * dst->pitch + (rect.w - 1) *
		dst->format->BytesPerPixel)) = clr;
		++y;
	}
	while (++rect.x < rect.w)
	{
		*((unsigned *)(dst->pixels + rect.y * dst->pitch + rect.x *
		dst->format->BytesPerPixel)) = clr;
		*((unsigned *)(dst->pixels + (rect.h - 1) * dst->pitch + rect.x *
		dst->format->BytesPerPixel)) = clr;
	}
}
