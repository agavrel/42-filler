/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:31:22 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/29 16:40:12 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** print wide string and returns total len
** please refer to libft for ft_wcharlen and ft_wstrlen
*/

int		pf_wide_string(va_list ap, t_printf *p)
{
	wchar_t		*s;
	int			wlen;
	int			sp_padding;
	int			charlen;

	if (!(s = va_arg(ap, wchar_t *)))
		return (ft_printf_putwstr((wchar_t *)s));
	wlen = (int)(ft_wstrlen((unsigned *)s));
	(p->apply_precision) ? wlen = MIN(p->precision, wlen) : 0;
	sp_padding = MAX(p->min_length - wlen + (p->precision > 1 ? 1 : 0), 0);
	p->apply_precision = (p->min_length > p->precision) ? 0 : 1;
	if (!p->flags.min)
		ft_putnchar(sp_padding, (p->flags.zero) ? '0' : ' ', p);
	charlen = 0;
	while (*s && (wlen -= charlen) > 0)
	{
		charlen = ft_putwchar(*s, wlen);
		p->printed += charlen;
		++s;
	}
	if (p->flags.min)
		ft_putnchar(sp_padding, (p->flags.zero) ? '0' : ' ', p);
	p->printed += MAX(sp_padding, 0);
	return (p->printed);
}

/*
** print regular string and returns its len
*/

int		pf_string(va_list ap, t_printf *p)
{
	unsigned	*s;
	int			len;
	int			sp_padding;

	if (!(s = va_arg(ap, unsigned*)))
		return (ft_printf_putstr((char *)s, p));
	len = (int)(ft_strlen((char*)s));
	(p->apply_precision) ? len = MIN(p->precision, len) : 0;
	sp_padding = (p->min_length - len) > 0 ? (p->min_length - len) : 0;
	if (!p->flags.min)
		ft_putnchar(sp_padding, (p->flags.zero) ? '0' : ' ', p);
	while ((char)*s && len--)
	{
		ft_putchar_fd((char)(*s), p->fd);
		++p->printed;
		s = (unsigned *)((char*)s + 1);
	}
	if (p->flags.min)
		ft_putnchar(sp_padding, ' ', p);
	p->printed += MAX(sp_padding, 0);
	return (p->printed);
}

/*
** prints string and returns its len, if no len will print (null) and return 6
*/

int		ft_printf_putstr(char *s, t_printf *p)
{
	if (!s)
	{
		(!p->flags.zero) ? ft_putstr("(null)") :
			ft_putnchar(p->min_length, '0', p);
		return ((!p->flags.zero) ? 6 : p->min_length);
	}
	ft_putstr_fd(s, p->fd);
	return ((int)ft_strlen(s));
}

int		ft_printf_putwstr(wchar_t *s)
{
	(s == L'\0') ? ft_putstr("(null)") : ft_putwstr(s);
	return (!s ? 6 : (int)ft_wstrlen((unsigned *)s));
}
