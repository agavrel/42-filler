/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 12:02:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	apply_sharp(t_print *print, t_spec *spec)
{
	if (spec->flags & (1 << 4))
	{
		if (spec->conv == 'o')
			ft_addto('0', print);
		else if (ft_strchr("xX", spec->conv))
		{
			ft_addto('0', print);
			ft_addto(spec->conv, print);
		}
	}
}

void	apply_plusspace(t_print *print, t_spec *spec, int s)
{
	if (!s)
		ft_addto('-', print);
	else if (spec->flags & 1)
		ft_addto('+', print);
	else if (spec->flags & (1 << 1))
		ft_addto(' ', print);
	else
		--spec->mfw;
}

void	apply_mfw(t_print *print, t_spec *spec, int mfw)
{
	while (mfw-- > 0)
		ft_addto(spec->flags & (1 << 3) ? '0' : ' ', print);
}

void	apply_numprec(t_print *print, t_spec *spec, int len)
{
	while ((spec->prec - len) > 0)
	{
		ft_addto('0', print);
		spec->prec--;
	}
}
