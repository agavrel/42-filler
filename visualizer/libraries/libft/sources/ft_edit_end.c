/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 23:11:00 by bsouchet          #+#    #+#             */
/*   Updated: 2017/01/23 11:12:04 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_edit_end(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (i + 1));
	new[i--] = 0;
	while (--j >= 0)
		new[i--] = s2[j];
	i++;
	while (i-- > 0)
		new[i] = s1[i];
	return (new);
}
