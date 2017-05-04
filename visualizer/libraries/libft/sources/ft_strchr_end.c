/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 16:45:48 by bsouchet          #+#    #+#             */
/*   Updated: 2016/11/04 15:45:53 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchr_end(char *str, char *find)
{
	int		len_str;
	int		len_find;

	len_str = ft_strlen(str);
	len_find = ft_strlen(find);
	if ((len_str == 0 || len_find == 0) ||
			len_str <= len_find)
		return (0);
	while (len_find > 0 && str[--len_str] == find[--len_find])
		;
	if (len_find == 0)
		return (1);
	return (0);
}
