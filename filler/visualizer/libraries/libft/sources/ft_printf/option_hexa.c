/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:04:39 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:00 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_x(t_spec *spec, t_print *print)
{
	int			i;
	int			j;
	uintmax_t	p;

	p = get_uni_param(spec->hljz, print->ap);
	i = ((spec->flags & E_SHARP && !(spec->flags & E_ZERO)) ? 2 : 0);
	i -= (p == 0 && spec->flags & E_SHARP) ? 2 : 0;
	j = !(spec->prec || p) ? 0
		: (i + ft_max(spec->prec, ft_nbrlenbase(p, 16)));
	(spec->flags & E_ZERO && p) ? apply_sharp(print, spec) : 0;
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - j) : 0;
	(!(spec->flags & E_ZERO) && p) ? apply_sharp(print, spec) : 0;
	apply_numprec(print, spec, ft_nbrlenbase(p, 16));
	!(spec->prec || p) ? 0
		: ft_uitoabase(p, "0123456789abcdef", print, ft_nbrlenbase(p, 16));
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}

void	conv_bx(t_spec *spec, t_print *print)
{
	int			i;
	int			j;
	uintmax_t	p;

	p = get_uni_param(spec->hljz, print->ap);
	i = ((spec->flags & E_SHARP && !(spec->flags & E_ZERO)) ? 2 : 0);
	i -= (p == 0 && spec->flags & E_SHARP) ? 2 : 0;
	j = !(spec->prec || p) ? 0
		: (i + ft_max(spec->prec, ft_nbrlenbase(p, 16)));
	(spec->flags & E_ZERO && p) ? apply_sharp(print, spec) : 0;
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - j) : 0;
	(!(spec->flags & E_ZERO) && p) ? apply_sharp(print, spec) : 0;
	apply_numprec(print, spec, ft_nbrlenbase(p, 16));
	!(spec->prec || p) ? 0
		: ft_uitoabase(p, "0123456789ABCDEF", print, ft_nbrlenbase(p, 16));
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}
