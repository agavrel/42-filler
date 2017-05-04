/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:07 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_o(t_spec *spec, t_print *print)
{
	int			i;
	uintmax_t	p;
	int			j;
	int			k;

	p = get_param(spec->hljz, print->ap);
	i = (spec->flags & E_SHARP && !(spec->flags & E_ZERO));
	(spec->flags & E_ZERO) ? apply_sharp(print, spec) : 0;
	j = ((spec->prec == -1) ? i : 0);
	k = !(spec->prec || p) ? 0 : (j + ft_max(spec->prec, ft_nbrlenbase(p, 8)));
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - k) : 0;
	(!(spec->flags & E_ZERO)) ? apply_sharp(print, spec) : 0;
	apply_numprec(print, spec, i + ft_nbrlenbase(p, 8));
	!(spec->prec || p) ? 0
		: ft_uitoabase(p, "01234567", print, ft_nbrlenbase(p, 8));
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}

void	conv_lo(t_spec *spec, t_print *print)
{
	spec->hljz = ((spec->flags == E_L) ? E_LL : E_L);
	spec->conv = 'o';
	conv_o(spec, print);
}
