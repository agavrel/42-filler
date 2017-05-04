/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:16:05 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/22 01:12:56 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** 						~ PARSING OPTONAL INPUTS ~
**
** here we parse the % to check for optional inputs :
** 1) flags, 2) field width, 3) precision and 4) length modifiers.
** Please refer to the man for a more accurate and full description.
** 5) the call to wildcard_length_modifier is a bonus where the '*' given
** the field_width or precision in the va_list ap.
** 6) the second call to parse_flags is to handle undefined behaviors.
*/

char	*parse_optionals(char *format, va_list ap, t_printf *p)
{
	p->flags = (t_flags) {.sharp = 0, .zero = 0, .min = 0, .plus = 0, .sp = 0};
	p->min_length = 0;
	p->precision = 1;
	p->apply_precision = 0;
	p->lm = (t_length_modifier)
		{.sshort = 0, .llong = 0, .intmax = 0, .sizet = 0};
	if (*format == '*' && ++format)
		wildcard_length_modifier(ap, p);
	format = parse_flags(format, &p->flags);
	format = field_width(format, p);
	format = precision(format, p);
	format = length_modifier(format, &p->lm);
	format = parse_flags(format, &p->flags);
	if (*format == '*' && ++format)
		wildcard_length_modifier(ap, p);
	return (format);
}

/*
** 						~ FLAGS ~
**
** flags interract between them, if there is a minus then it
** cancels the zero flag. if there is a + it cancels the sp flag.
** sharp is to add the prefix 0x for hexa for example
*/

char	*parse_flags(char *format, t_flags *flags)
{
	while (ft_strchr("#0+- ", *format))
	{
		if (*format == '#')
			flags->sharp = 1;
		else if (*format == '0')
			flags->zero = 1;
		else if (*format == '+')
			flags->plus = 1;
		else if (*format == '-')
			flags->min = 1;
		else if (*format == ' ')
			flags->sp = 1;
		++format;
	}
	if (flags->min)
		flags->zero = 0;
	if (flags->plus)
		flags->sp = 0;
	return (format);
}

/*
** 						~ FIELD WIDTH ~
**
** An optional decimal digit string (with nonzero first digit) specifying a
** minimum field width. If the converted value has fewer characters than the
** field width, it will be padded with spaces on the left (or right, if the
** left-adjustment flag has been given). Instead of a decimal digit string
** one may write "*" or "*m$" (for some decimal integer m) to specify that
** the field width is given in the next argument, or in the m-th argument,
** respectively, which must be of type int. A negative field width is taken
** as a '-' flag followed by a positive field width. In no case does a
** nonexistent or small field width cause truncation of a field; if the result
** of a conversion is wider than the field width, the field is expanded to
** contain the conversion result.
**
** 2nd if : if there is a conv. specifier after the field width for a base it
** will reset the min_length to 0 EXCEPT if it was a padding with 0s ...
*/

char	*field_width(char *format, t_printf *p)
{
	if (ft_strchr("123456789", *format))
	{
		p->min_length = MAX(1, ft_atoi(format));
		while (ft_strchr("0123456789", *format))
			++format;
	}
	return (format);
}

/*
** 						~ PRECISION ~
**
** An optional precision, in the form of a period ('.') followed by an optional
** decimal digit string. Instead of a decimal digit string one may write "*" or
** "*m$" (for some decimal integer m) to specify that the precision is given in
** the next argument, or in the m-th argument, respectively, which must be of
** type int. If the precision is given as just '.', or the precision is
** negative, the precision is taken to be zero. This gives the minimum number
** of digits to appear for d, i, o, u, x, and X conversions, the number of
** digits to appear after the radix character for a, A, e, E, f, and F
** conversions, the maximum number of significant digits for g and G
** conversions, or the maximum number of characters to be printed from a
** string for s and S conversions.
*/

char	*precision(char *format, t_printf *p)
{
	int value;

	if (ft_strchr(".", *format))
	{
		value = ft_atoi(++format);
		p->precision = MAX(value, 0);
		while (ft_strchr("0123456789", *format))
			++format;
		p->apply_precision = 1;
	}
	return (format);
}

/*
** 						~ LENGTH MODIFIER ~
** converts into short, shortshort, long, long long, int_max, size_t depending
** on the input, respectively : h, hh, l, ll, j, z
*/

char	*length_modifier(char *format, t_length_modifier *lm)
{
	while (ft_strchr("hljzL", *format))
	{
		if (*format == 'h')
		{
			lm->sshort = 1;
			if (*(format + 1) == 'h' && (lm->sshort = 2))
				++format;
		}
		if (*format == 'l')
		{
			lm->llong = 1;
			if (*(format + 1) == 'l' && (lm->llong = 2))
				++format;
		}
		if (*format == 'L')
			lm->llong = 2;
		if (*format == 'j')
			lm->intmax = 1;
		if (*format == 'z')
			lm->sizet = 1;
		++format;
	}
	return (format);
}
