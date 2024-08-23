# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Plgol <plgol@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/16 17:46:51 by Plgol             #+#    #+#              #
#    Updated: 2023/07/16 17:46:54 by Plgol            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRC_DIR = src
SRC     = $(SRC_DIR)/ft_printf.c \
          $(SRC_DIR)/ft_fsm.c \
          $(SRC_DIR)/ft_putnbr_base.c \
          $(SRC_DIR)/ft_print_fmt_i32.c \
          $(SRC_DIR)/ft_print_fmt_u32.c \
          $(SRC_DIR)/ft_print_fmt_i8.c \
          $(SRC_DIR)/ft_print_fmt_str.c \
          $(SRC_DIR)/ft_print_fmt_ptr.c \
          $(SRC_DIR)/ft_print_fmt_lhex.c \
          $(SRC_DIR)/ft_print_fmt_uhex.c

OBJ_DIR = obj
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

INC_DIR = lib
INC     = -I $(INC_DIR)
LIB     = $(INC_DIR)/ft_printf.h

STATIC_NAME = libftprintf.a

.PHONY: all clean fclean re

all: $(STATIC_NAME)

$(STATIC_NAME): $(OBJS)
		ar rcs $(STATIC_NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJS): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir -p $(OBJ_DIR)

bonus : all

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(STATIC_NAME)

re: fclean all
