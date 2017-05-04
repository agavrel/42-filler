/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:56 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/29 16:38:20 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** handles %%
*/

int		percent_char(t_printf *p)
{
	if (!p->flags.min && p->min_length - 1 > 0)
		ft_putnchar(p->min_length - 1, (p->flags.zero) ? '0' : ' ', p);
	ft_putwchar('%', 4);
	if (p->flags.min)
		ft_putnchar(p->min_length - 1, (p->flags.zero) ? '0' : ' ', p);
	return (MAX(p->min_length, 1));
}

/*
** returns a single character len and display it
** refer to libft for putwchar amd wcharlen functions
*/

void	pf_character(va_list ap, t_printf *p)
{
	unsigned	c;
	int			len;

	c = va_arg(ap, unsigned);
	len = (p->lm.llong) ? ft_wcharlen(c) : 1;
	if (!p->flags.min)
		ft_putnchar(p->min_length - MIN(len, p->min_length),
		(p->flags.zero) ? '0' : ' ', p);
	(p->lm.llong) ? ft_putwchar(c, 4) : ft_putchar(c);
	if (p->flags.min)
		ft_putnchar(p->min_length - MIN(len, p->min_length), ' ', p);
	p->len += MAX(p->min_length, len);
}

/*
** write a single regular character and adds 1 to p->len
*/

void	pf_putchar(char c, t_printf *p)
{
	write(p->fd, &c, 1);
	++p->len;
}
