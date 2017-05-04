/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl_pt_in_rect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 16:07:45 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/07 23:00:40 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

int		fsdl_pt_in_rect(SDL_Point *point, SDL_Rect rect)
{
	if (point->x > (rect.x + rect.w) || point->y > (rect.y + rect.h) ||
		point->x < rect.x || point->y < rect.y)
		return (0);
	return (1);
}
