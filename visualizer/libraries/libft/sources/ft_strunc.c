/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 13:04:37 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/05 13:15:37 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strunc(char *str, int len)
{
	int		i;
	int		t;
	char	*new;

	i = -1;
	t = 0;
	new = NULL;
	if ((t = ft_strlen(str)) <= len)
		len = t;
	new = (char *)malloc(sizeof(char) * (len + 1));
	new[len] = 0;
	(len != t) ? (len -= 3) : 1;
	while (++i < len)
		new[i] = str[i];
	if (len == t)
		return (new);
	new[i++] = '.';
	new[i++] = '.';
	new[i] = '.';
	return (new);
}
