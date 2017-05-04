# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 22:13:23 by bsouchet          #+#    #+#              #
#    Updated: 2017/03/28 06:35:46 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= clang

NAME		= visualizer

FLAGS		= -Wall -Wextra -Werror -fsanitize=address

SDL2_F		= -framework SDL2 -framework SDL2_ttf -framework SDL2_image -F ./frameworks/

SDL2_P		= -rpath @loader_path/frameworks/

SDL2_I		= -I ./frameworks/SDL2.framework/Headers

SDL2_TTF_I	= -I ./frameworks/SDL2_ttf.framework/Headers

SDL2_IMG_I	= -I ./frameworks/SDL2_image.framework/Headers

FSDL		= libraries/fsdl

LIBFT		= libraries/libft

DIR_S		= sources

DIR_O		= temporary

HEADER		= includes

SOURCES		= main.c \
			  init.c \
			  infos.c \
			  parser.c \
			  window.c \
			  colors.c \
			  draw.c \
			  draw2.c \
			  events.c \
			  misc.c

SRCS		= $(addprefix $(DIR_S)/,$(SOURCES))

OBJS		= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

opti:
	@$(MAKE) all -j

all: temporary $(NAME)

$(NAME): $(OBJS)
	@make -C $(FSDL)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -L $(FSDL) -lfsdl -o $@ $^ $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

temporary:
	@mkdir -p temporary

$(DIR_O)/%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -c -o $@ $<

norme:
	@make clean -C $(FSDL)
	@make norme -C $(LIBFT)
	@echo
	norminette ./$(HEADER)
	@echo
	norminette ./$(DIR_S)

clean:
	@rm -f $(OBJS)
	@make clean -C $(FSDL)
	@make clean -C $(LIBFT)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(FSDL)
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

r: $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -lft -L $(FSDL) -lfsdl -o $(NAME) $^ $(SDL2_P) $(SDL2_F) $(SDL2_I) $(SDL2_TTF_I) $(SDL2_IMG_I)

.PHONY: all, temporary, norme, clean, fclean, re
