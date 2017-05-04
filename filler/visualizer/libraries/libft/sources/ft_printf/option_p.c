/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:12 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_p(t_spec *spec, t_print *print)
{
	int			j;
	uintmax_t	p;

	spec->hljz = E_L;
	p = get_uni_param(spec->hljz, print->ap);
	j = !(spec->prec || p) ? 0
		: (ft_max(spec->prec, ft_nbrlenbase(p, 16) + 2));
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - j) : 0;
	ft_addto('0', print);
	ft_addto('x', print);
	apply_numprec(print, spec, ft_nbrlenbase(p, 16));
	!(spec->prec || p) ? 0
		: ft_uitoabase(p, "0123456789abcdef", print, ft_nbrlenbase(p, 16));
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}
