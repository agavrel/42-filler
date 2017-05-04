/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:33:52 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/05 13:34:22 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putshort(short num)
{
	short	tmp;
	short	size;
	char	*str;

	size = 0;
	tmp = num;
	if (num == 0 && write(1, "0", 1))
		return ;
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size != 0)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return ;
	str[size--] = 0;
	while (num != 0 && (str[size--] = (num % 10) + '0') != 0)
		num /= 10;
	(size == 0) ? str[0] = '-' : 1;
	write(1, str, ft_strlen(str));
	free(str);
}

void		ft_putint(int num)
{
	int		tmp;
	int		size;
	char	*str;

	size = 0;
	tmp = num;
	if (num == 0 && write(1, "0", 1))
		return ;
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size != 0)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return ;
	str[size--] = 0;
	while (num != 0 && (str[size--] = (num % 10) + '0') != 0)
		num /= 10;
	(size == 0) ? str[0] = '-' : 1;
	write(1, str, ft_strlen(str));
	free(str);
}

void		ft_putfloat(float num)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0 && write(1, "0.00", 4))
		return ;
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size != 0)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return ;
	str[size--] = 0;
	while ((int)num != 0 && ++i > 0)
		(i != 3 && (str[size--] = ((int)num % 10) + '0')) ?
		(num /= 10) : (str[size--] = '.');
	(size == 0 && i == 2) ? str[0] = '.' : 1;
	(size == 0 && i != 2) ? str[0] = '-' : 1;
	write(1, str, ft_strlen(str));
	free(str);
}

void		ft_putdouble(double num)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0 && write(1, "0.00", 4))
		return ;
	(num < .0 && (tmp *= -1.) > 0) ? ++size : 1;
	num = tmp;
	while (tmp != 0 && ++size != 0)
		tmp /= 10;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return ;
	str[size--] = 0;
	while ((int)num != 0 && ++i > 0)
		(i != 3 && (str[size--] = ((int)num % 10) + '0')) ?
		(num /= 10) : (str[size--] = '.');
	(size == 0 && i == 2) ? str[0] = '.' : 1;
	(size == 0 && i != 2) ? str[0] = '-' : 1;
	write(1, str, ft_strlen(str));
	free(str);
}
