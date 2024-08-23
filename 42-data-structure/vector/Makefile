# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 09:32:51 by pollivie          #+#    #+#              #
#    Updated: 2024/06/13 09:32:51 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC = clang
AR = ar
CFLAGS = -Wall -Wextra -Werror -O2 -Iinclude
LIB_NAME = libvector.a
SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = dep

SRC = $(wildcard $(SRC_DIR)/*.c)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

DEPS = $(OBJ:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	@echo "Creating static library $@..."
	$(AR) rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(DEP_DIR)
	@echo "Compiling $< to $@..."
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	@mkdir -p $@

-include $(DEPS)

make: all

re: fclean all

clean:
	@echo "Cleaning object files..."
	rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@echo "Cleaning the library..."
	rm -f $(LIB_NAME)

.PHONY: all make re clean fclean
