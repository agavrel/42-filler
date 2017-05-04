/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:14:20 by angavrel          #+#    #+#             */
/*   Updated: 2017/03/01 16:14:27 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** function to reverse a list
*/

t_list	*ft_lstrev(t_list *lst)
{
	t_file *a;
	t_file *b;
	t_file *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}
