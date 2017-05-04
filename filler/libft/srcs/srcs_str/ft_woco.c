/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_woco.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:27:49 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:35:56 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** nice function inspired from N. Alliot to count occurence of
** character in a word
*/

int		ft_woco(const char *s, char c)
{
	int		n;
	int		i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			++n;
		++i;
	}
	return (n);
}
