/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 13:19:18 by qle-guen          #+#    #+#             */
/*   Updated: 2017/02/28 21:55:00 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <string.h>

typedef struct			s_list
{
	void				*mem;
	size_t				size;
	struct s_list		*next;
}						t_list;

typedef int				(*t_cmp_f) (void *, void *);
typedef unsigned char	t_u8;
typedef char			t_i8;
typedef unsigned int	t_u32;
typedef int				t_i32;
typedef unsigned long	t_u64;
typedef long			t_i64;
typedef float			t_f32;
typedef double			t_f64;

# ifdef T_F32_V2
#  define T_F32_V2_ECHO
#  define T_V2

typedef struct			s_f32_v2
{
	t_f32				x;
	t_f32				y;
}						t_f32_v2;
# endif

# ifdef T_F64_V2
#  define T_F64_V2_ECHO
#  define T_V2

typedef struct			s_f64_v2
{
	t_f64				x;
	t_f64				y;
}						t_f64_v2;
# endif

# ifdef T_F64_V3
#  define T_F64_V3_ECHO
#  define T_V3

typedef struct			s_f64_v3
{
	t_f64				x;
	t_f64				y;
	t_f64				z;
}						t_f64_v3;
# endif

# ifdef T_U32_V2
#  define T_U32_V2_ECHO
#  define T_V2

typedef struct			s_u32_v2
{
	t_u32				x;
	t_u32				y;
}						t_u32_v2;
# endif

# ifdef T_I32_V2
#  define T_I32_V2_ECHO
#  define T_V2

typedef struct			s_i32_v2
{
	t_i32				x;
	t_i32				y;
}						t_i32_v2;
# endif

# ifdef T_U32_V4
#  define T_U32_V4_ECHO
#  define T_V4

typedef struct			s_u32_v4
{
	t_u32				a;
	t_u32				b;
	t_u32				c;
	t_u32				d;
}						t_u32_v4;

#  define V4L(x) ((x).a)
#  define V4U(x) ((x).b)
#  define V4R(x) ((x).c)
#  define V4D(x) ((x).d)

#  define V4X(x) ((x).a)
#  define V4Y(x) ((x).b)
#  define V4W(x) ((x).c)
#  define V4H(x) ((x).d)

#  define V4X1(x) (V4X(x))
#  define V4X2(x) (V4X(x) + V4W(x))
#  define V4Y1(x) (V4Y(x))
#  define V4Y2(x) (V4Y(x) + V4H(x))

# endif

# ifdef T_V2

#  define ABS2(t, a) (V2(t, ABS((a).x), ABS((a).y)))
#  define ADD2(a, b) ((a).x + (b).x)
#  define CPY2(t, a) V2(t, (a).x, (a).y)
#  define DIFF2(t, a, b) V2(t, (a).x-(b).x, (a).y-(b).y)
#  define DOT2(t, a, b) V2(t, (a).x*(b).x, (a).y*(b).y)
#  define EQ2(a, b) ((a).x == (b).x && (a).y == (b).y)
#  define INF2(a, b) ((a).x < (b).x && (a).y < (b).y)
#  define NEQ2(a, b) (!EQ2(a, b))
#  define SUM2(t, a, b) V2(t, (a).x+(b).x, (a).y+(b).y)
#  define V2(t, a, b) ((t##_v2){a, b})
#  define DX2(a, b) (a.x > b.x ? a.x - b.x : b.x - a.x)
#  define DY2(a, b) (a.y > b.y ? a.y - b.y : b.y - a.y)
#  define DD2(a, b) (V2(t_u32, DX2(a, b), DY2(a, b)))
# endif

# ifdef T_V3
#  define V3(t, a, b, c) ((t##_v3){a, b, c})
# endif

# ifdef T_V4

#  define CPY4(t, x) V4(t, (x).a, (x).b, (x).c, (x).d)
#  define DIFF4(t, x, y) V4(t,(x).a-(y).a,(x).b-(y).b,(x).c-(y).c,(x).d-(y).d)
#  define DOT4(t, x, y) V4(t,(x).a*(y).a,(x).b*(y).b,(x).c*(y).c,(x).d*(y).d)
#  define SUM4(t, x, y) V4(t,(x).a+(y).a,(x).b+(y).b,(x).c+(y).c,(x).d+(y).d)
#  define V4(t, a, b, c, d) ((t##_v4){a, b, c, d})

#  ifdef T_V2
#   define V4_V2(t, x, f) f(t, V2(t, (x).a, (x).b), V2(t, (x).c, (x).d))
#  endif

# endif

#endif
