# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 03:39:13 by pollivie          #+#    #+#              #
#    Updated: 2023/09/23 03:39:15 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_cat.c
NAME = ft_cat

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(SRC) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

