/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_w.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfremeau <qfremeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 14:14:43 by qfremeau          #+#    #+#             */
/*   Updated: 2016/06/23 14:19:45 by qfremeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	switch_hexa(int x)
{
	if (0 <= x && x <= 9)
		return (48 + x);
	if (x >= 10 && x <= 15)
	{
		x = x - 10;
		return (97 + x);
	}
	return (0);
}

char		*ft_hexa_itoa(unsigned long long n)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x >= 16)
	{
		x /= 16;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 16;
			str[size] = switch_hexa(x);
			n /= 16;
			size--;
		}
	}
	return (str);
}

char		*ft_octal_itoa(unsigned long long n)
{
	char				*str;
	int					size;
	unsigned long long	x;

	x = n;
	size = 0;
	while (x > 7)
	{
		x /= 8;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 8;
			str[size] = 48 + x;
			n /= 8;
			size--;
		}
	}
	return (str);
}

char		*ft_unsigned_itoa(unsigned long int n)
{
	char				*str;
	int					size;
	unsigned long int	x;

	x = n;
	size = 0;
	while (x >= 10)
	{
		x /= 10;
		size++;
	}
	str = (char *)malloc(sizeof(str) * (size + 1));
	if (str)
	{
		str[size + 1] = '\0';
		while (size >= 0)
		{
			x = n % 10;
			str[size] = 48 + x;
			n = n / 10;
			size--;
		}
	}
	return (str);
}
