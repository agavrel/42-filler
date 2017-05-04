/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 04:42:05 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/28 06:25:39 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_joinall(size_t size, ...)
{
	size_t	len;
	size_t	tmp;
	va_list	ap;
	va_list	ap2;
	char	*s;

	va_start(ap, size);
	va_copy(ap2, ap);
	len = 0;
	tmp = size;
	while (tmp--)
		len += ft_strlen(va_arg(ap2, char *));
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (size--)
		s = ft_strnjoin(s, va_arg(ap, char *), len);
	va_end(ap);
	return (s);
}
