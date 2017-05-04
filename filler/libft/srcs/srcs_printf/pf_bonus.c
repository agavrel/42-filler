/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:55:33 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/28 06:09:41 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** bonuses done :
**   1) *   wildcard_length_modifier
**   2) n   print_len (refer to ft_printf.c : *va_arg(ap, int *) = p->len;)
**   3) m   ft_printf_putstr(strerror(errno), p)
**   4) {}  color
**   5) fF  ldtoa
*/

/*
** function that handle * : length or precision is given by va_list ap
*/

void	wildcard_length_modifier(va_list ap, t_printf *p)
{
	int		tmp;

	tmp = (int)va_arg(ap, int);
	p->flags.min = (tmp < 0) ? 1 : 0;
	tmp = ABS(tmp);
	if (!p->apply_precision)
		p->min_length = tmp;
	else
	{
		p->precision = (!p->flags.min) ? tmp : 0;
		p->apply_precision = (!tmp) ? 1 : 0;
	}
}

/*
** bonus function that handles colors
*/

char	*pf_color(char *format, t_printf *p)
{
	p->printed = 5;
	if (!ft_strncmp(format, "{red}", ft_strlen("{red}")))
		COLOR(PF_RED, 5);
	else if (!ft_strncmp(format, "{green}", ft_strlen("{green}")))
		COLOR(PF_GREEN, 7);
	else if (!ft_strncmp(format, "{yellow}", ft_strlen("{yellow}")))
		COLOR(PF_YELLOW, 8);
	else if (!ft_strncmp(format, "{blue}", ft_strlen("{blue}")))
		COLOR(PF_BLUE, 6);
	else if (!ft_strncmp(format, "{purple}", ft_strlen("{purple}")))
		COLOR(PF_PURPLE, 8);
	else if (!ft_strncmp(format, "{cyan}", ft_strlen("{cyan}")))
		COLOR(PF_CYAN, 6);
	else if (!ft_strncmp(format, "{eoc}", ft_strlen("{eoc}")))
		COLOR(PF_EOC, 5);
	else
		p->printed = 0;
	p->len += p->printed;
	return (format - 1);
}

/*
** bonus function that handles float
*/

void	pf_putdouble(va_list ap, t_printf *p)
{
	char		*s;
	double		n;

	n = (double)va_arg(ap, double);
	(p->flags.zero) ? p->precision = p->min_length : 0;
	s = pf_ldtoa(n, p);
	ft_putstr_free(s);
	p->len += MAX(p->printed, p->min_length);
}

/*
** calculates the size of what should be malloced
** the decimals malloced are calculated with p->precision
*/

char	*pf_ldtoa(double n, t_printf *p)
{
	long		tmp;
	char		*s;
	int			len;

	if (p->apply_precision && !p->precision)
		return (itoa_printf((intmax_t)n, p));
	else if (!p->apply_precision)
		p->precision = 6;
	len = (p->precision > 0) ? 1 : 0;
	tmp = (long)(ABS(n));
	while (tmp)
	{
		tmp /= 10;
		++len;
	}
	(p->flags.zero) ? p->precision = p->min_length : 0;
	p->printed = p->precision + len + ((n < 0) ? 1 : 0);
	if (!(s = (char*)malloc(sizeof(char) * (p->printed + 1))))
		return (NULL);
	ldtoa_fill(n, s, p);
	(p->flags.sp) ? s[0] = ' ' : 0;
	(n < 0) ? s[0] = '-' : 0;
	(p->flags.plus && n >= 0) ? s[0] = '+' : 0;
	return (s);
}

/*
** decimal is first calculated as the riht part, then we multiply it by
** 10 power p->precision + 1 in order to get the rounding.
*/

void	ldtoa_fill(double n, char *s, t_printf *p)
{
	int		len;
	int		accuracy;
	double	decimal;
	long	value;

	decimal = ABS(n);
	decimal = (decimal - (long)(ABS(n))) * ft_pow(10, p->precision + 1);
	decimal = ((long)decimal % 10 > 4) ? (decimal) / 10 + 1 : decimal / 10;
	len = p->printed - 1 - p->precision;
	accuracy = p->printed - 1 - len;
	s[p->printed] = '\0';
	value = (int)decimal;
	while (accuracy--)
	{
		s[len + accuracy + 1] = value % 10 + '0';
		value /= 10;
	}
	(p->precision > 0) ? s[len] = '.' : 0;
	value = (long)(ABS(n));
	while (len--)
	{
		s[len] = value % 10 + '0';
		value /= 10;
	}
	(p->apply_precision && p->flags.zero) ? s[0] = ' ' : 0;
}
