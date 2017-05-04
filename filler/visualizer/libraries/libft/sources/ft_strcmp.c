/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:24:27 by bsouchet          #+#    #+#             */
/*   Updated: 2016/12/09 18:11:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(char *s1, char *s2, int s)
{
	int		i;

	i = 0;
	while (s1[s] && s2[i] && s1[s] == s2[i])
	{
		s++;
		i++;
	}
	if (!s2[i])
		return (1);
	return (0);
}

int			ft_strlcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		s1[i] += (s1[i] >= 65 && s1[i] <= 90) ? 32 : 0;
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int			ft_lcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0)
	{
		s1[i] += (s1[i] >= 65 && s1[i] <= 90) ? 32 : 0;
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] || s2[i])
		return (0);
	return (1);
}
