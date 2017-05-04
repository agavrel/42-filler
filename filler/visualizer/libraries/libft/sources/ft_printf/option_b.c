/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 10:44:15 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:48 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	apply_precbin(t_spec *spec, t_print *print, int len)
{
	int	i;
	int	c;

	c = 0;
	i = 4 * spec->prec - len;
	while (i-- > 0)
	{
		if (!(c % 4) && c)
			ft_addto(' ', print);
		ft_addto('0', print);
		++c;
	}
	if (c)
		ft_addto(' ', print);
}

static void	apply_param(t_spec *spec, t_print *print, int h)
{
	int	i;

	i = (spec->flags & E_SHARP) ? 1 : 0;
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw -
		(h + (i * (h / 4)) - 1)) : 0;
}

void		conv_b(t_spec *spec, t_print *print)
{
	uintmax_t	p;
	uintmax_t	tmp;
	int			len;
	int			i;
	int			tmplen;

	p = get_param(spec->hljz, print->ap);
	len = ft_bitlen(p);
	tmplen = (4 - (len % 4));
	apply_param(spec, print, len + tmplen);
	i = tmplen - 1;
	(spec->prec > 0) ? apply_precbin(spec, print, len + tmplen) : 0;
	while (tmplen--)
		ft_addto('0', print);
	while (len-- && ++i)
	{
		tmp = p;
		tmplen = len;
		while (tmplen--)
			tmp /= 2;
		(((spec->flags & E_SHARP) || spec->prec > -1) && !(i % 4)) ?
			ft_addto(' ', print) : 0;
		ft_addto(tmp % 2 + '0', print);
	}
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}
