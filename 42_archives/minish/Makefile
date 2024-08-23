# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/04 11:07:46 by pollivie          #+#    #+#              #
#    Updated: 2024/07/04 11:07:46 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = clang
CFLAGS = -Wall                   		 \
         -Wextra                         \
         -Werror                         \
         -Iinclude                       \
         -DDEBUG=0                       \
         -g3                             \
         -fsanitize=address              \
         -fsanitize=undefined            \
         -fsanitize=null                 \
         -fsanitize=return               \
         -fno-omit-frame-pointer         

LIBS = -lreadline

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = .obj
TARGET = minishell

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re

