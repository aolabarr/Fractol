# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 15:08:51 by aolabarr          #+#    #+#              #
#    Updated: 2024/06/14 00:19:44 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
NO_LINK = -c
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c\
		ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_strrchr.c \
		ft_strncmp.c ft_strnstr.c ft_memcmp.c ft_tolower.c ft_toupper.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_strjoin_freed.c\


OBJS_DIR = ./obj
OBJS = $(addprefix $(OBJS_DIR)/,$(SRC:.c=.o))
NAME = libft.a

$(NAME): $(OBJS_DIR) $(OBJS)
	ar -cr $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR)/%.o: %.c
	$(CC) $(NO_LINK) $(CFLAGS) $< -o $@

$(OBJS_DIR):
	mkdir obj

fclean: clean
	rm -f $(NAME) *.out

clean:
	@if [ -d $(OBJS_DIR) ]; then rm -rf $(OBJS_DIR); fi
	rm -f *.o

re: fclean all 

.PHONY: all fclean clean re


#.SILENT:
