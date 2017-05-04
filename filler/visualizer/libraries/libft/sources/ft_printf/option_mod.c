/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:07:14 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:54:04 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	conv_mod(t_spec *spec, t_print *print)
{
	(!(spec->flags & E_DASH)) ? apply_mfw(print, spec, spec->mfw - 1) : 0;
	ft_addto('%', print);
	(spec->flags & E_DASH) ? apply_mfw(print, spec, spec->mfw) : 0;
}
