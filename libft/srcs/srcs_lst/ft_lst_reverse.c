/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:37:37 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/18 19:38:13 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function to reverse a list
*/

t_list	*ft_lstrev(t_list *lst)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	a = NULL;
	b = lst;
	c = lst->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}
