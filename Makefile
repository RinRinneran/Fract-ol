# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpelckma <marvin@.42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/05 12:51:58 by rpelckma          #+#    #+#              #
#    Updated: 2025/04/05 13:27:56 by rpelckma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -lm
LIBFT_PATH = inc/libft
MLX_PATH = inc/minilibx-linux

SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = inc

SRC_FILES = $(SRC_DIR)/calculations.c $(SRC_DIR)/init.c $(SRC_DIR)/main.c $(SRC_DIR)/mnk_input_handling.c $(SRC_DIR)/utls.c
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = $(LIBFT_PATH)/libft.a
MLX = $(MLX_PATH)/libmlx.a

NAME = fractol

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx -lXext -lGL -lX11
	@echo "Compilation successful, object files and $(NAME) were created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -I$(MLX_PATH) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) > /dev/null 2>&1

$(MLX):
	@$(MAKE) -C $(MLX_PATH) > /dev/null 2>&1

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean > /dev/null 2>&1
	@$(MAKE) -C $(MLX_PATH) clean > /dev/null 2>&1
	@rm -rf $(OBJ_DIR)
	@echo "Object files were deleted"

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean > /dev/null 2>&1
	@rm $(NAME)
	@echo "$(NAME) was deleted"

re: fclean all

.PHONY: all clean fclean re

