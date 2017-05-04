/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_dir_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 16:53:42 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/19 18:01:48 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_name(char *file, char *extension)
{
	int		i;
	int		len;
	int		tmp;
	char	*str;

	i = 0;
	len = ft_strlen(file) - ft_strlen(extension);
	tmp = len;
	while (--len > 0 && file[len] != '/')
		i++;
	str = (char *)malloc(sizeof(char) * ++i);
	i = 0;
	while (++len < tmp)
		str[i++] = (file[len] >= 97 && file[len] <= 122) ?
		file[len] - 32 : file[len];
	str[i] = 0;
	return (str);
}
