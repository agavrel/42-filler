/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:52 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_c(t_spec *spec, t_print *print)
{
	intmax_t	p;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'C';
		conv_lc(spec, print);
	}
	else
	{
		p = get_param(spec->hljz, print->ap);
		(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - 1) : 0;
		ft_addto(p, print);
		(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
	}
}
