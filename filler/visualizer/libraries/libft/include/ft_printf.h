/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 16:28:33 by qfremeau          #+#    #+#             */
/*   Updated: 2017/01/13 23:26:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>

# define BUFFSIZE 1024
# define OPT "sSpdDioOuUxXcCb%"

enum			e_hljz
{
	E_NO = 0,
	E_HH,
	E_H,
	E_L,
	E_LL,
	E_J,
	E_Z
};

enum			e_type
{
	E_INT = 0,
	E_CHAR,
	E_SHORT,
	E_LONG,
	E_LLONG,
	E_INTMAX,
	E_SIZE_T
};

enum			e_flags
{
	E_SHARP = 1 << 4,
	E_ZERO = 1 << 3,
	E_DASH = 1 << 2,
	E_SPACE = 1 << 1,
	E_PLUS = 1
};

typedef struct	s_spec
{
	char		flags;
	int			mfw;
	int			prec;
	char		hljz;
	char		conv;
}				t_spec;

typedef	struct	s_print
{
	char		buf[BUFFSIZE];
	t_spec		*spec;
	va_list		ap;
	void		*convftab[16];
	int			pos;
	int			ret;
	int			fd;
}				t_print;

int				set_flag(t_spec *spec, const char *str);
int				set_mfwi(t_print *print, t_spec *spec, const char *str);
int				set_prec(t_spec *spec, const char *str);
int				set_modi(t_spec *spec, const char *str);
int				set_conv(t_spec *spec, const char *str);

intmax_t		get_param(int type, va_list ap);
uintmax_t		get_uni_param(int type, va_list ap);
void			apply_sharp(t_print *print, t_spec *spec);
void			apply_plusspace(t_print *print, t_spec *spec, int s);
void			apply_mfw(t_print *print, t_spec *spec, int mfw);
void			apply_numprec(t_print *print, t_spec *spec, int len);

int				print_opts(t_spec *spec, t_print *print, const char *format);
void			conv_b(t_spec *spec, t_print *print);
void			conv_s(t_spec *spec, t_print *print);
void			conv_ls(t_spec *spec, t_print *print);
void			conv_p(t_spec *spec, t_print *print);
void			conv_d(t_spec *spec, t_print *print);
void			conv_ld(t_spec *spec, t_print *print);
void			conv_i(t_spec *spec, t_print *print);
void			conv_o(t_spec *spec, t_print *print);
void			conv_lo(t_spec *spec, t_print *print);
void			conv_u(t_spec *spec, t_print *print);
void			conv_lu(t_spec *spec, t_print *print);
void			conv_x(t_spec *spec, t_print *print);
void			conv_bx(t_spec *spec, t_print *print);
void			conv_c(t_spec *spec, t_print *print);
void			conv_lc(t_spec *spec, t_print *print);
void			conv_mod(t_spec *spec, t_print *print);

char			*ft_strf(const char *format, ...);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

void			ft_addto(char c, t_print *print);

int				ft_strnchr(char c, char *ptr, int n);
int				ft_nbrlenbase(uintmax_t nb, int base);
int				ft_bitlen(intmax_t p);
int				ft_min(int a, int b);
int				ft_max(int a, int b);
uintmax_t		ft_abs(intmax_t nb);
void			ft_sitoa(intmax_t p, t_print *print, int l);
void			ft_uitoabase(uintmax_t p, char *base, t_print *print, int l);

#endif
