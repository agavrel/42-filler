/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 19:38:08 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/28 07:03:10 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ftoa(float num)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0)
		return (ft_strdup("0.00"));
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	(tmp < 10) ? ++size : 1;
	(tmp < 100) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size--] = 0;
	while ((int)num != 0 && ++i)
		(i != 3 && (str[size--] =
		((int)num % 10) + '0')) ? (num /= 10) : (str[size--] = '.');
	(i == 1 && ++i) ? str[size--] = '0' : 1;
	(i == 2 && ++i) ? str[size--] = '.' : 1;
	(i == 3 && ++i) ? str[size--] = '0' : 1;
	(size == 0) ? str[0] = '-' : 1;
	return (str);
}

char		*ft_dtoa(double num)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num > -0.01 && num < 0.01)
		return (ft_strdup("0.00"));
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	(tmp < 10) ? ++size : 1;
	(tmp < 100) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	str[size--] = 0;
	while ((int)num != 0 && ++i)
		(i != 3 && (str[size--] =
		((int)num % 10) + '0')) ? (num /= 10) : (str[size--] = '.');
	(i == 1 && ++i) ? str[size--] = '0' : 1;
	(i == 2 && ++i) ? str[size--] = '.' : 1;
	(i == 3 && ++i) ? str[size--] = '0' : 1;
	(size == 0) ? str[0] = '-' : 1;
	return (str);
}
