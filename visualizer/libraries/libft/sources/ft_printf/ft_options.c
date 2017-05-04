/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:12:32 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		set_spec(t_print *print, t_spec *spec, const char *str)
{
	int		i;
	int		ret;

	ret = 0;
	ret += set_flag(spec, str);
	ret += set_mfwi(print, spec, str + ret);
	ret += set_prec(spec, str + ret);
	ret += set_modi(spec, str + ret);
	if ((i = set_conv(spec, str + ret)) == -1)
		return (-1);
	ret += i;
	return (ret);
}

int				print_opts(t_spec *spec, t_print *print, const char *format)
{
	int		(*convf)(t_spec*, t_print*);
	int		tmp;

	if (format[0] == '%')
	{
		ft_addto('%', print);
		return (1);
	}
	if ((tmp = set_spec(print, spec, format)) == -1)
		return (-1);
	convf = print->convftab[ft_strnchr(spec->conv, OPT, 16)];
	convf(spec, print);
	return (tmp);
}
