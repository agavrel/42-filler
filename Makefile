# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/28 18:36:22 by angavrel          #+#    #+#              #
#    Updated: 2017/04/15 03:48:02 by angavrel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = angavrel.filler

FLAGS = -Wall -Werror -Wextra
INC = -I ./incl/

### PATH ###
SRCS_PATH = srcs/
OBJ_PATH  = obj/
LIBFT_PATH = libft/

SRCS_NAME =	main.c \
			parse.c \
			valid_positions.c \
			solve.c \
			break_through.c \
			reach_borders.c \
			check_min.c \
			scoring.c \
			scoring2.c \
			get_picture.c \

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

### COMPILE ###
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C visualizer/
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -framework OpenGL -framework AppKit -lmlx -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"
	
$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
		@echo "\033[34m\033[1mCompilation of \033[0m\033[36m$(notdir $<)\033[1m\033[34m done.\033[0m"
		@mkdir -p `dirname $@`
		@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
		@make -C $(LIBFT_PATH) fclean
		@make -C visualizer/ fclean
		@/bin/rm -rf $(OBJ_PATH)
		@/bin/rm -rf filler.trace
		@/bin/rm -rf board.map
		@echo "\033[1;31m$(NAME) \033[1;0m\033[31mobjects files removed.\033[0m"

fclean: clean
		@/bin/rm -rf $(NAME)
		@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
