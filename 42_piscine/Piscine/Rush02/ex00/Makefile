# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 10:15:17 by pollivie          #+#    #+#              #
#    Updated: 2023/09/23 10:15:19 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = src/num_base.c   src/num_debug.c  src/num_file.c        \
      src/num_parse.c  src/num_print.c  src/num_helpers.c     \
	  src/num_stack.c  src/num_lexer.c  

OBJ = $(SRC:.c=.o)

HEADERS_DIR = lib
NAME = rush-02

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) $(OBJ) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -I $(HEADERS_DIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
