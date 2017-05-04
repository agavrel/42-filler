/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparams.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 12:03:58 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:16 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	get_param(int type, va_list ap)
{
	if (type == E_INT)
		return ((intmax_t)va_arg(ap, int));
	if (type == E_CHAR)
		return ((intmax_t)(char)va_arg(ap, int));
	if (type == E_SHORT)
		return ((intmax_t)(short)va_arg(ap, int));
	if (type == E_LONG)
		return ((intmax_t)va_arg(ap, long));
	if (type == E_LLONG)
		return ((intmax_t)va_arg(ap, long long));
	if (type == E_SIZE_T)
		return ((intmax_t)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, intmax_t));
	return (-1);
}

uintmax_t	get_uni_param(int type, va_list ap)
{
	if (type == E_INT)
		return ((uintmax_t)va_arg(ap, unsigned int));
	if (type == E_CHAR)
		return ((uintmax_t)(unsigned char)va_arg(ap, unsigned int));
	if (type == E_SHORT)
		return ((uintmax_t)(unsigned short)va_arg(ap, unsigned int));
	if (type == E_LONG)
		return ((uintmax_t)va_arg(ap, unsigned long));
	if (type == E_LLONG)
		return ((uintmax_t)va_arg(ap, unsigned long long));
	if (type == E_SIZE_T)
		return ((uintmax_t)va_arg(ap, size_t));
	if (type == E_INTMAX)
		return (va_arg(ap, uintmax_t));
	return (-1);
}
