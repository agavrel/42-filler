/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shtoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:26:30 by bsouchet          #+#    #+#             */
/*   Updated: 2016/12/09 16:47:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_shtoi(const char *s)
{
	unsigned int	result;
	int				c;

	result = 0;
	while (*s)
	{
		result = result << 4;
		if ((c = (*s - '0')) >= 0 && c <= 9)
			result |= c;
		else if ((c = (*s - 'A')) >= 0 && c <= 5)
			result |= (c + 10);
		else if ((c = (*s - 'a')) >= 0 && c <= 5)
			result |= (c + 10);
		else
			break ;
		++s;
	}
	return (result);
}
