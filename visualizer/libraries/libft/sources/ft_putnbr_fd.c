/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 22:19:54 by qfremeau          #+#    #+#             */
/*   Updated: 2017/02/28 21:58:05 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		x = n * -1;
	}
	else
		x = n;
	if (x >= 10)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
		ft_putchar_fd(x + '0', fd);
}

void		ft_putshort_fd(short num, int fd)
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
	write(fd, str, ft_strlen(str));
	free(str);
}

void		ft_putint_fd(int num, int fd)
{
	int		tmp;
	int		size;
	char	*str;

	size = 0;
	tmp = num;
	if (num == 0 && write(fd, "0", 1))
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
	write(fd, str, ft_strlen(str));
	free(str);
}

void		ft_putfloat_fd(float num, int fd)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0 && write(fd, "0.00", 4))
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
	write(fd, str, ft_strlen(str));
	free(str);
}

void		ft_putdouble_fd(double num, int fd)
{
	short	i;
	int		tmp;
	short	size;
	char	*str;

	i = 0;
	size = 1;
	tmp = (int)round(num * 100);
	if (num == .0 && write(fd, "0.00", 4))
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
	write(fd, str, ft_strlen(str));
	free(str);
}
