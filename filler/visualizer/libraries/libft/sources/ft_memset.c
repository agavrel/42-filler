/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:39:56 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/28 09:04:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void	memset_carry(unsigned char *s, unsigned long c64, size_t n)
{
	if (n & 16)
	{
		*(unsigned long *)(s + 0) = c64;
		*(unsigned long *)(s + 8) = c64;
		s += 16;
	}
	if (n & 8)
	{
		*(unsigned long *)s = c64;
		s += 8;
	}
	if (n & 4)
	{
		*(unsigned int *)s = (unsigned int)c64;
		s += 4;
	}
	if (n & 2)
	{
		*(unsigned short *)s = (unsigned short)c64;
		s += 2;
	}
	if (n & 1)
		*s = (unsigned char)c64;
}

void		*ft_memset(void *p, int c, size_t n)
{
	unsigned long	c64;
	unsigned char	*s;

	s = p;
	while (n && (uintptr_t)s % 8)
	{
		*s++ = (unsigned char)c;
		n--;
	}
	if (!n)
		return (p);
	c64 = ((unsigned long)-1) / 0xFF * (unsigned char)c;
	while (n >= 32)
	{
		*(unsigned long *)(s + 0) = c64;
		*(unsigned long *)(s + 8) = c64;
		*(unsigned long *)(s + 16) = c64;
		*(unsigned long *)(s + 24) = c64;
		s += 32;
		n -= 32;
	}
	memset_carry(s, c64, n);
	return (p);
}
