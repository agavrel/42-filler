/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_uni.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:10:17 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	adduni(wchar_t p, int nbbi, t_print *print)
{
	if (nbbi >= 1 && nbbi <= 7)
		ft_addto(p, print);
	else if (nbbi >= 8 && nbbi <= 11)
	{
		ft_addto(((3 << 6) | (p >> 6)), print);
		ft_addto(((1 << 7) | (63 & p)), print);
	}
	else if (nbbi >= 12 && nbbi <= 16)
	{
		ft_addto((7 << 5) | (p >> 12), print);
		ft_addto((1 << 7) | (63 & (p >> 6)), print);
		ft_addto((1 << 7) | (63 & p), print);
	}
	else if (nbbi >= 17 && nbbi <= 21)
	{
		ft_addto((15 << 4) | (p >> 18), print);
		ft_addto((1 << 7) | (63 & (p >> 12)), print);
		ft_addto((1 << 7) | (63 & (p >> 6)), print);
		ft_addto((1 << 7) | (63 & p), print);
	}
}

static int	ft_wstrlen(wchar_t *p)
{
	int		i;

	i = 0;
	while (p[i])
		++i;
	return (i);
}

static int	nboc(int nbbi)
{
	if (nbbi >= 1 && nbbi <= 7)
		return (1);
	else if (nbbi >= 8 && nbbi <= 11)
		return (2);
	else if (nbbi >= 12 && nbbi <= 16)
		return (3);
	else if (nbbi >= 17 && nbbi <= 21)
		return (4);
	return (0);
}

void		conv_lc(t_spec *spec, t_print *print)
{
	wchar_t	p;
	int		nbbi;

	p = (wchar_t)get_uni_param(spec->hljz, print->ap);
	nbbi = ft_bitlen(p);
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw -
		nboc(nbbi)) : 0;
	adduni(p, nbbi, print);
	((spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw) : 0;
}

void		conv_ls(t_spec *spec, t_print *print)
{
	wchar_t	*p;
	int		i;
	int		nbbi;
	int		j;

	i = 0;
	p = (wchar_t*)get_uni_param(E_LONG, print->ap);
	if (!p)
		p = L"(null)";
	nbbi = ft_bitlen(p[i]);
	j = (spec->prec <= -1) ? nboc(nbbi) : 0;
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw -
		ft_wstrlen(p) - j) : 0;
	while (p[i] && (spec->prec > 0 || spec->prec <= -1))
	{
		nbbi = ft_nbrlenbase(p[i], 2);
		spec->prec -= nboc(nbbi);
		adduni(p[i], nbbi, print);
		i++;
	}
	((spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw) : 0;
}
