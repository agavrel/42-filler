/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 14:23:48 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:16 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		conv_s(t_spec *spec, t_print *print)
{
	int		i;
	int		neg;
	char	*s;

	if (spec->hljz == E_L || spec->hljz == E_LL)
	{
		spec->conv = 'S';
		conv_ls(spec, print);
	}
	else
	{
		i = 0;
		s = (char *)get_uni_param(E_LONG, print->ap);
		if (!s)
			s = "(null)";
		neg = (spec->prec > -1 ? (unsigned)ft_min(spec->prec, ft_strlen(s)) :
				ft_strlen(s));
		(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - neg) : 0;
		while (s[i] && (spec->prec--))
			ft_addto(s[i++], print);
		(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
	}
}
