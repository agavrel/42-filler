/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setoptions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:25:35 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:36 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		set_flag(t_spec *spec, const char *str)
{
	int i;

	i = 0;
	spec->flags = 0;
	while (ft_strchr("#0-+ ", str[i]))
	{
		if (str[i] == '#')
			spec->flags |= (1 << 4);
		if (str[i] == '0' && (!(spec->flags & (1 << 2))))
			spec->flags |= (1 << 3);
		if (str[i] == '-')
		{
			spec->flags |= (1 << 2);
			spec->flags &= ~(1 << 3);
		}
		if (str[i] == ' ' && (!(spec->flags & 1)))
			spec->flags |= (1 << 1);
		if (str[i] == '+')
		{
			spec->flags |= 1;
			spec->flags &= ~(1 << 1);
		}
		i++;
	}
	return (i);
}

int		set_mfwi(t_print *print, t_spec *spec, const char *str)
{
	int		i;

	i = 0;
	spec->mfw = 0;
	if (str[i] == '*')
	{
		++i;
		spec->mfw = va_arg(print->ap, int);
	}
	else
		while (ft_strchr("0123456789", str[i]))
		{
			spec->mfw *= 10;
			spec->mfw += (str[i] - '0');
			++i;
		}
	return (i);
}

int		set_prec(t_spec *spec, const char *str)
{
	int		i;

	i = 0;
	spec->prec = -1;
	if (str[i] == '.')
	{
		++i;
		spec->flags &= ~(1 << 3);
		spec->prec = 0;
		while (ft_strchr("1234567890", str[i]))
		{
			spec->prec *= 10;
			spec->prec += (str[i] - '0');
			++i;
		}
	}
	return (i);
}

int		set_modi(t_spec *spec, const char *str)
{
	int		i;

	i = 0;
	while (ft_strchr("hljz", str[i]))
	{
		spec->hljz = (str[i] == 'h' && spec->hljz == E_H) ? E_HH : spec->hljz;
		spec->hljz = (str[i] == 'h' && spec->hljz == E_NO) ? E_H : spec->hljz;
		spec->hljz = (str[i] == 'l' && spec->hljz == E_NO) ? E_L : spec->hljz;
		spec->hljz = (str[i] == 'l' && spec->hljz == E_L) ? E_LL : spec->hljz;
		spec->hljz = (str[i] == 'j') ? E_J : spec->hljz;
		spec->hljz = (str[i] == 'z') ? E_Z : spec->hljz;
		i++;
	}
	return (i);
}

int		set_conv(t_spec *spec, const char *str)
{
	int		i;

	i = 0;
	if (!(ft_strchr(OPT, str[i])))
		return (-1);
	spec->conv = str[i];
	return (1);
}
