# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aolabarr <aolabarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/07/07 15:38:29 by aolabarr         ###   ########.fr        #
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

INC_DIR = .
LIBFT_DIR = ./lib/libft
LIBMLX_DIR = ./lib/minilibx-linux
MATH_DIR = /usr/local/lib

SRC =	fractol_main.c \
		fractol_parse.c \
		fractol_render.c \
		fractol_equations.c \
		fractol_keys.c \
		fractol_utils.c \
		fractol_libx.c \
		fractol_events.c \
		fractol_palette.c \
		fractol_interpol.c \
				
SRC_BONUS = fractol_main_bonus.c \
			fractol_render_bonus.c \
			fractol_newton_bonus.c \
			fractol_complex_bonus.c \
			

SRC_BONUS_AUX = fractol_palette.c\
				fractol_libx.c \
				fractol_keys.c \
				fractol_events.c \
				fractol_interpol.c \
				fractol_utils.c \
				fractol_parse.c \

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS:.c=.o))
OBJS_BONUS_AUX = $(addprefix $(OBJ_DIR_BONUS)/,$(SRC_BONUS_AUX:.c=.o))

all: lib $(OBJ_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L$(MATH_DIR) -lm -lft -lmlx_Linux -lX11 -lXext -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

bonus: lib $(OBJ_DIR_BONUS) $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_BONUS_AUX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_BONUS_AUX) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -L$(MATH_DIR) -lm -lft -lmlx_Linux -lX11 -lXext -o $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c 
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR_BONUS)/%.o: $(SRC_DIR)/%.c
	$(CC) $(NO_LINK) $(CFLAGS) -I$(INC_DIR) $< -o $@

$(OBJ_DIR_BONUS):
	mkdir $(OBJ_DIR_BONUS)

sanitizer: lib $(OBJ_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(SFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIMLX_DIR) -lm -lft -llibx-Linux -o $(NAME)

lib:
	make -C $(LIBFT_DIR)
	make -C $(LIBMLX_DIR) 2> /dev/null

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
