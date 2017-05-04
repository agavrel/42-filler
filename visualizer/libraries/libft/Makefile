# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2017/03/22 13:59:06 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -O2 -g

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_atoi.c \
		  ft_atof.c \
		  ft_shtoi.c \
		  ft_rand.c \
		  ft_ftoa.c \
		  ft_clamp.c \
		  ft_free.c \
		  ft_clr.c \
		  ft_mempcpy.c \
		  ft_memset.c \
		  ft_short_bzero.c \
		  ft_memchr.c \
		  ft_nsplit.c \
		  ft_word.c \
		  ft_comment.c \
		  ft_bzero.c \
		  ft_itoa.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_assign.c \
		  ft_assign_opencl.c \
		  ft_strcmp.c \
		  ft_getstr.c \
		  ft_checkstr.c \
		  ft_del_dir_name.c \
		  ft_edit_end.c \
		  ft_strunc.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_strchr.c \
		  ft_strchr_end.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlen.c \
		  ft_color.c \
		  ft_nbrlen.c\
		  ft_strlen_w.c\
		  ft_putnbrlong.c\
		  ft_itoa_w.c\
		  ft_putchar.c\
		  ft_putchar_fd.c\
		  ft_putendl.c\
		  ft_putendl_fd.c\
		  ft_putstr.c\
		  ft_putstr_fd.c\
		  ft_putnl.c\
		  ft_vec1.c \
		  ft_vec2.c \
		  ft_vec3.c \
		  ft_dzero.c \
		  ft_printf/ft_addto.c\
		  ft_printf/ft_strf.c \
		  ft_printf/ft_printf.c\
		  ft_printf/ft_options.c\
		  ft_printf/ft_setoptions.c\
		  ft_printf/ft_apply.c\
		  ft_printf/ft_getparams.c\
		  ft_printf/option_c.c\
		  ft_printf/option_di.c\
		  ft_printf/option_p.c\
		  ft_printf/option_u.c\
		  ft_printf/option_s.c\
		  ft_printf/option_o.c\
		  ft_printf/option_b.c\
		  ft_printf/option_uni.c\
		  ft_printf/option_hexa.c\
		  ft_printf/option_mod.c\
		  ft_printf/ft_strnchr.c\
		  ft_printf/ft_sitoa.c\
		  ft_printf/ft_maths.c\
		  ft_printf/ft_nbrlen.c\
		  gnl/get_next_line.c \
		  ft_malloc_err.c \
		  ft_intlen.c \
		  ft_hue_color.c \
		  ft_isdigit.c


SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

SUB_FOLDERS	= gnl ft_printf

BUILD_DIR = $(addprefix $(DIR_O)/,$(SUB_FOLDERS))

opti:
	@$(MAKE) all -j 8

all: temporary $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

temporary: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ../libft/$(HEADER)
	@echo
	norminette ../libft/$(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all -j 8
