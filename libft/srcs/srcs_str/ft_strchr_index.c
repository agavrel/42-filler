/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:38:34 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 16:10:04 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** returns character's index (position) in a string
*/

int		ft_strchr_index(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		++i;
	}
	return (-1);
}
