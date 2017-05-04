/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:35:08 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:40:14 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_digits(char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

/*
** checks that the string is an integer
*/

int			ft_is_integer(char *str)
{
	char	*max_int;
	char	*min_int;
	int		len;

	max_int = "2147483647";
	min_int = "-2147483648";
	len = ft_strlen(str);
	if (!str || len > 11)
		return (0);
	else if (check_digits(str))
	{
		if (len == 10 && ft_strcmp(max_int, str) < 0)
			return (0);
		return (1);
	}
	else if (*str == '-' && check_digits(str + 1))
	{
		if (len == 11 && ft_strcmp(min_int, str) < 0)
			return (0);
		return (1);
	}
	return (0);
}
