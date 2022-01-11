# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qkherzi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/06 17:21:21 by qkherzi           #+#    #+#              #
#    Updated: 2021/12/06 17:22:55 by qkherzi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC= gcc

CFLAGS= -Wall -Wextra -Werror  #-g -fsanitize=address

RM= rm -f

MLX= -lmlx -framework OpenGL -framework AppKit

SRC =	srcs/main.c\
		srcs/parse.c\
		srcs/utils.c\
		srcs/gnl_utils.c\
		srcs/gnl.c\

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)
	$(RM) $(NAME)

reset: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re reset
