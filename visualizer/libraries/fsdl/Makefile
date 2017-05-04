# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/02 15:48:09 by bsouchet          #+#    #+#              #
#    Updated: 2017/03/13 21:22:41 by bsouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang

NAME		= libfsdl.a

FLAGS		= -Wall -Wextra -Werror -O2 -g

DIR_S		= sources

DIR_O		= temporary

HEADER		= include

SOURCES		= draw/fsdl_fill_rect.c \
			  draw/fsdl_draw_pt.c \
			  draw/fsdl_draw_rect.c \
			  get/fsdl_pt_in_rect.c \
			  set/fsdl_fps.c

SUB_FOLDERS	= draw get set

BUILD_DIR	= $(addprefix $(DIR_O)/,$(SUB_FOLDERS))

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

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
	norminette ../fsdl/$(HEADER)
	@echo
	norminette ../fsdl/$(DIR_S)

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all -j 8
