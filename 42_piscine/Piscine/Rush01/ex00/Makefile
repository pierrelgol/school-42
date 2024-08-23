# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/17 20:14:13 by pollivie          #+#    #+#              #
#    Updated: 2023/09/17 20:14:15 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC     = cc
CFLAGS = -Wall -Werror -Wextra -ggdb
SRC    = src/*.c
LIB    = lib/*.h
NAME   = bin/rush-01

.PHONY all:

all: $(NAME)

$(NAME): $(SRC) $(LIB)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean:
	rm -f $(NAME)

fclean: clean

	rm -f *.o $(NAME)

re: fclean all


