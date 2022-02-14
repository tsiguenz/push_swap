# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsiguenz <tsiguenz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 13:22:09 by tsiguenz          #+#    #+#              #
#    Updated: 2022/02/14 20:26:21 by tsiguenz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Paths

OBJ_PATH = obj/

# Names

SRC = main.c parsing.c

OBJ_NAME = $(SRC:.c=.o)

# Files

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# Flags

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LIBFT = -Llibft -lft
INC = -Iinclude -Ilibft

# Rules

$(NAME): $(OBJ)
	@make -C libft/ --no-print-directory
	@echo "Build $(NAME)"
	@$(CC) $(CFLAGS) $(OBJ) $(INC) $(LIBFT) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: $(NAME)

clean:
	@make clean -C libft/ --no-print-directory
	@echo "Delete $(OBJ_PATH)"
	@rm -rf $(OBJ_PATH)

fclean:	clean
	@make fclean -C libft/ --no-print-directory
	@echo "Delete $(NAME)"
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
