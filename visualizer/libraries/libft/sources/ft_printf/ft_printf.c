/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 11:45:23 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/09 15:53:32 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_print_init(t_print *print, t_spec *spec)
{
	print->convftab[0] = &conv_s;
	print->convftab[1] = &conv_ls;
	print->convftab[2] = &conv_p;
	print->convftab[3] = &conv_d;
	print->convftab[4] = &conv_ld;
	print->convftab[5] = &conv_i;
	print->convftab[6] = &conv_o;
	print->convftab[7] = &conv_lo;
	print->convftab[8] = &conv_u;
	print->convftab[9] = &conv_lu;
	print->convftab[10] = &conv_x;
	print->convftab[11] = &conv_bx;
	print->convftab[12] = &conv_c;
	print->convftab[13] = &conv_lc;
	print->convftab[14] = &conv_b;
	print->convftab[15] = &conv_mod;
	print->pos = 0;
	print->ret = 0;
	spec->hljz = 0;
	spec->flags = 0;
	spec->mfw = 0;
	print->spec = spec;
	ft_bzero(print->buf, BUFFSIZE);
}

static	int		ft_print_error(t_print *print)
{
	write(print->fd, print->buf, print->pos);
	va_end(print->ap);
	return (-1);
}

static	int		ft_printf_process(const char *format, t_print *print,
	t_spec *spec)
{
	int			i;
	int			tmp;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_addto(format[i], print);
		else if ((tmp = print_opts(spec, print, format + i + 1)) == -1)
			return (ft_print_error(print));
		else
			i += tmp;
		++i;
	}
	return (0);
}

int				ft_printf(const char *format, ...)
{
	t_print		print;
	t_spec		spec;

	print.fd = 1;
	va_start(print.ap, format);
	ft_print_init(&print, &spec);
	if (ft_printf_process(format, &print, &spec) == -1)
		return (-1);
	write(1, print.buf, print.pos);
	va_end(print.ap);
	return (print.ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	t_print		print;
	t_spec		spec;

	print.fd = fd;
	va_start(print.ap, format);
	ft_print_init(&print, &spec);
	if (ft_printf_process(format, &print, &spec) == -1)
		return (-1);
	write(fd, print.buf, print.pos);
	va_end(print.ap);
	return (print.ret);
}
