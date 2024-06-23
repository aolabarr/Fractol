# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/06/23 12:44:16 by aolabarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
NAME_BONUS = fractol_bonus
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror -g3
SFLAGS =  -fsanitize=address

OBJ_DIR = ./obj
SRC_DIR = ./src
OBJ_DIR_BONUS = ./obj_bonus
SRC_DIR_BONUS = ./src_bonus

INC_DIR = ./lib
LIBFT_DIR = ./lib/libft
LIBMLX_DIR = ./lib/minilibx-linux
MATH_DIR = /usr/local/lib

SRC =	fractol_main.c\
		fractol_mandel.c\
		fractol_mandel_2.c\
		fractol_utils.c\
		fractol_mem.c \
		fractol_libx.c\
		fractol_color.c\
		fractol_events.c\
		
SRC_BONUS = 

SRC_BONUS_AUX = 

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
# OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS:.c=.o))
# OBJS_BONUS_AUX = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS_AUX:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L$(MATH_DIR) -lm -lft -lmlx_Linux -lX11 -lXext -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIMLX_DIR) -lm -lft -llibx-Linux -o $(NAME)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBMLX_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)
	make clean -C $(LIBMLX_DIR)

clean:
	@if [ -d $(OBJ_DIR) ]; then rm -rf $(OBJ_DIR); fi
	@if [ -d $(OBJ_DIR_BONUS) ]; then rm -rf $(OBJ_DIR_BONUS); fi
	make clean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all fclean clean re lib sanitizer bonus


#.SILENT:
