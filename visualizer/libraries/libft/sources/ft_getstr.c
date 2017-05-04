/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:26:17 by bsouchet          #+#    #+#             */
/*   Updated: 2016/11/27 15:25:30 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_getstr(char *buf, int s, int e)
{
	char	*str;
	int		t_s;
	int		t_e;
	int		i;

	i = 0;
	t_s = s;
	t_e = e;
	str = NULL;
	while (t_s < e && (buf[t_s] == 32 || buf[t_s] == 9))
		t_s++;
	if (t_s == e)
		return (NULL);
	while ((t_e - 1) > s && (buf[t_e - 1] == 32 || buf[t_e - 1] == 9))
		t_e--;
	if (!(str = (char *)malloc(sizeof(char) * ((t_e - t_s) + 1))))
		return (NULL);
	while (t_s < t_e)
		str[i++] = buf[t_s++];
	str[i] = 0;
	return (str);
}
