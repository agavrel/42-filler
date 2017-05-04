/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:18:44 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/29 16:37:32 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 						~ PRINTF LOOP ~
**
** printf will return p.len: the total len of what was displayed by printf
** if there is a % we will parse user input, else we will display it.
*/

int		ft_printf(char *format, ...)
{
	va_list		ap;
	t_printf	p;

	va_start(ap, format);
	p.len = 0;
	p.fd = 2;
	while (*format)
	{
		if (*format == '%')
		{
			if (!format[1] || (format[1] == ' ' && (!format[2]
			|| (!format[3] && format[2] == 'h'))))
				break ;
			p.printed = 0;
			format = parse_optionals(++format, ap, &p);
			if (*format == '%')
				p.len += percent_char(&p);
			format = conversion_specifier(format, ap, &p);
		}
		else
			pf_putchar(*format, &p);
		++format;
	}
	va_end(ap);
	return (p.len);
}

/*
** 						~ CONVERSION SPECIFIER ~
**
** A character that specifies the type of conversion to be applied
** if the character following % is a % then is it acts as an ESC char
** The conversion specifiers and their meanings are:
** 1) d, i, D : signed int
** 2) o, u, x, X : unsigned octal, uns. decimal, uns. hexa lower and uppercase
** 3) b, B for unsigned binary
** 3) c, C : char and large char
** 4) s : pointer to a string
** 5) n : the number of characters written so far is stored into the integer
** indicated by the int * pointer argument. No argument is converted.
** 6) m : Print output of strerror(errno). no arg. required
** 7) {} : adds color
** if the character is uppercase then p->cs.uppercase will be set to 1.
*/

char	*conversion_specifier(char *format, va_list ap, t_printf *p)
{
	(ft_strchr("CDSUOB", *format)) ? p->lm.llong = 1 : 0;
	p->cs.upcase = (*format == 'X') ? 1 : 0;
	(*format == 'x' || *format == 'X') ? pf_putnb_base(16, ap, p) : 0;
	(*format == 'u' || *format == 'U') ? pf_putnb_base(10, ap, p) : 0;
	(*format == 'o' || *format == 'O') ? pf_putnb_base(8, ap, p) : 0;
	(*format == 'b' || *format == 'B') ? pf_putnb_base(2, ap, p) : 0;
	(ft_strchr("dDi", *format)) ? pf_putnb(ap, p) : 0;
	(*format == 'c' || *format == 'C') ? pf_character(ap, p) : 0;
	(*format == 's' && !p->lm.llong) ? p->len += pf_string(ap, p) : 0;
	if (*format == 'S' || (*format == 's' && p->lm.llong))
		p->len += pf_wide_string(ap, p);
	(*format == 'p') ? p->len += print_pointer_address(ap, p) : 0;
	(*format == 'n') ? *va_arg(ap, int *) = p->len : 0;
	(*format == 'm') ? p->len += ft_printf_putstr(strerror(errno), p) : 0;
	(*format == 'f' || *format == 'F') ? pf_putdouble(ap, p) : 0;
	if (*format == '{')
		return (pf_color(format, p));
	if (!ft_strchr("sSpdDibBoOuUxXcC%nmfF", *format))
		cs_not_found(format, p);
	return (format);
}

/*
** function used to adjust length for padding due to the flag -
*/

void	ft_putnchar(int len, char c, t_printf *p)
{
	char	*s;

	if (!(s = (char *)malloc(sizeof(char) * len + 1)))
		return ;
	s[len] = '\0';
	while (len--)
		s[len] = c;
	ft_putstr_fd(s, p->fd);
	free(s);
}

/*
** function that displays pointer address
*/

int		print_pointer_address(va_list ap, t_printf *p)
{
	int				sp_padding;
	char			*s;
	void			*pointer;

	pointer = va_arg(ap, void *);
	p->flags.sharp = 0;
	p->min_length -= (p->flags.zero ? 2 : 0);
	s = itoa_base_printf((uintmax_t)pointer, 16, p);
	sp_padding = (p->printed > p->min_length - 2) ? 0 :
		p->min_length - 2 - p->printed;
	if (!p->flags.min)
		ft_putnchar(sp_padding, ((p->flags.zero) ? '0' : ' '), p);
	ft_putstr_fd("0x", p->fd);
	ft_putstr_fd(s, p->fd);
	free(s);
	if (p->flags.min)
		ft_putnchar(sp_padding, ((p->flags.zero) ? '0' : ' '), p);
	return (MAX(p->printed + 2, p->min_length));
}

/*
** function if no conversion specifier was found.
*/

void	cs_not_found(char *format, t_printf *p)
{
	if (!p->flags.min && p->min_length > 1)
		ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ', p);
	p->min_length > 1 ? p->len += p->min_length - 1 : 0;
	pf_putchar(*format, p);
	if (p->flags.min && p->min_length > 1)
		ft_putnchar(p->min_length - 1, p->flags.zero ? '0' : ' ', p);
}
