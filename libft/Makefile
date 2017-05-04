# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/12 13:55:55 by angavrel          #+#    #+#              #
#    Updated: 2017/03/28 06:07:10 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I ./incl/

FLAGS = -Wall -Wextra -Werror

### FILES ###
SRCS_BOOL =		ft_error.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isblank.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_is_power_of_2.c \
				ft_is_power_of_x.c \
				ft_isascii.c \
				ft_iswascii.c \
				ft_intarray_is_sorted.c \
				ft_is_integer.c \
				ft_is_alrdy_contained.c \

SRCS_COLOR =	ft_hex2rgb.c \
				ft_hsv2hex.c \
				ft_hsv2rgb.c \
				ft_rgb2hex.c \
				ft_shade_color.c \

SRCS_IO =		ft_putchar.c \
				ft_putendl_fd.c \
				ft_putnbr_base.c \
				ft_putstr_fd.c \
				ft_putwstr.c \
				ft_putchar_fd.c \
				ft_puthex.c \
				ft_putnbr_fd.c \
				ft_putstr_free.c \
				ft_putendl.c \
				ft_putnbr.c \
				ft_putstr.c \
				ft_putwchar.c \
				get_next_line.c \

SRCS_LST =		ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstswap.c \

SRCS_MATHS =	ft_abs.c \
				ft_atoi.c \
				ft_clamp.c \
				ft_fclamp.c \
				ft_pow.c \
				ft_rand.c \
				ft_range.c \
				ft_round.c \
				ft_htoi.c \
				ft_get_median.c \
				ft_nbrlen.c \

SRCS_MATRIX =	ft_copy_matrix.c \
				ft_factor_matrix_free.c \
				ft_free_matrix.c \
				ft_identity_matrix.c \
				ft_matrix_global_rotation.c \
				ft_matrix_rotation.c \
				ft_matrix_scaling.c \
				ft_matrix_to_vector.c \
				ft_matrix_z_scaling.c \
				ft_print_matrix.c \
				ft_sum_matrix.c \

SRCS_VECTOR =	ft_vector_len.c \
				ft_vector_mult.c \
				ft_vector_scaling.c \
				ft_vector_add.c \
				ft_vector_sub.c \
		

SRCS_MEM =		ft_bubblesort_array.c \
				ft_bzero.c \
				ft_intnew.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c \
				ft_memswap.c \
				ft_strnew.c \
				ft_swap.c \
				ft_free_chartab.c \

SRCS_PRINTF	=	ft_printf.c \
				pf_bonus.c \
				pf_character.c \
				pf_number.c \
				pf_parsing.c \
				pf_string.c \

SRCS_STR =		ft_str2lower.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strctrim.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strdupfree.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strjoinfree.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strlencmp.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strnequ.c \
				ft_strnjoin.c \
				ft_strnjoinfree.c \
 				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_strchr_index.c \
				ft_exit_error.c \
				ft_woco.c \
				ft_name.c \
				ft_joinall.c \

SRCS_TOA =		ft_itoa.c \
				ft_itoa_base.c \
				ft_ldtoa.c \
				ft_lltoa_base.c \
				ft_ulltoa_base.c \

SRCS_UNICODE =	ft_wcharlen.c \
				ft_wstrdup.c \
				ft_wstrjoin.c \
				ft_wstrlen.c \
				ft_wstrsub.c \

SRC_IMG		=	ft_init_img.c \
				ft_put_pixel.c \

### PATH ###
SRCS_PATH = srcs/
SRCS =	$(addprefix $(SRCS_PATH)srcs_bool/, $(SRCS_BOOL)) \
		$(addprefix $(SRCS_PATH)srcs_color/, $(SRCS_COLOR)) \
	   	$(addprefix $(SRCS_PATH)srcs_io/, $(SRCS_IO)) \
	   	$(addprefix $(SRCS_PATH)srcs_lst/, $(SRCS_LST)) \
	   	$(addprefix $(SRCS_PATH)srcs_maths/, $(SRCS_MATHS)) \
	   	$(addprefix $(SRCS_PATH)srcs_matrix/, $(SRCS_MATRIX)) \
	   	$(addprefix $(SRCS_PATH)srcs_vector/, $(SRCS_VECTOR)) \
	   	$(addprefix $(SRCS_PATH)srcs_mem/, $(SRCS_MEM)) \
	   	$(addprefix $(SRCS_PATH)srcs_printf/, $(SRCS_PRINTF)) \
	   	$(addprefix $(SRCS_PATH)srcs_str/, $(SRCS_STR)) \
	   	$(addprefix $(SRCS_PATH)srcs_toa/, $(SRCS_TOA)) \
	   	$(addprefix $(SRCS_PATH)srcs_unicode/, $(SRCS_UNICODE)) \
	   	$(addprefix $(SRCS_PATH)srcs_img/, $(SRCS_IMG)) \

OBJ_PATH  = obj/
OBJ = 	$(addprefix $(OBJ_PATH)srcs_bool/, $(SRCS_BOOL:.c=.o)) \
		$(addprefix $(OBJ_PATH)srcs_color/, $(SRCS_COLOR:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_io/, $(SRCS_IO:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_lst/, $(SRCS_LST:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_maths/, $(SRCS_MATHS:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_matrix/, $(SRCS_MATRIX:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_vector/, $(SRCS_VECTOR:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_mem/, $(SRCS_MEM:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_printf/, $(SRCS_PRINTF:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_str/, $(SRCS_STR:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_toa/, $(SRCS_TOA:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_unicode/, $(SRCS_UNICODE:.c=.o)) \
	   	$(addprefix $(OBJ_PATH)srcs_img/, $(SRCS_IMG:.c=.o)) \

### COMPILE ###
UP	=	"\033[A"
CUT	=	"\033[K"

all:	$(NAME)
		
$(NAME):$(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"
		@mkdir -p `dirname $@`
		@gcc -c $(FLAGS) $(INC) $< -o $@
		@printf $(UP)$(CUT)

clean:
		@/bin/rm -rf $(OBJ_PATH)
		@echo "\033[1;31m$(NAME) \033[1;0m\033[31mobjects files removed.\033[0m"

fclean:	clean
		@/bin/rm -rf $(NAME)
		@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re:		fclean all

.PHONY:	all, clean, fclean, re
