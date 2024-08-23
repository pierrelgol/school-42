# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/22 08:47:56 by pollivie          #+#    #+#              #
#    Updated: 2024/02/22 08:47:57 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

CFLAGS = -Wall -Wextra -Werror  -I$(INCLUDE_DIRECTORY)

# CFLAGS =  -Wall 										\
# 		  -Wextra 										\
# 		  -glldb										\
# 		  -march=native									\
# 		  -mtune=native									\
# 		  -fsanitize=address 							\
# 		  -fsanitize=undefined 							\
# 		  -fsanitize=integer							\
# 		  -fstrict-overflow								\
# 		  -Walloca										\
# 		  -Wcast-qual									\
# 		  -Wconversion									\
# 		  -Wformat=2									\
# 		  -Wformat-security								\
# 		  -Wnull-dereference							\
# 		  -Wstack-protector								\
# 		  -Wvla											\
# 		  -Wshorten-64-to-32							\
# 		  -Warray-bounds								\
# 		  -Warray-bounds-pointer-arithmetic				\
# 		  -Wimplicit-fallthrough						\
# 		  -Wloop-analysis								\
# 		  -Wshift-sign-overflow							\
# 		  -Wswitch-enum									\
# 		  -Wtautological-constant-in-range-compare		\
# 		  -Wcomma 										\
# 		  -Wassign-enum 								\
# 		  -Wbad-function-cast 							\
# 		  -Wfloat-equal									\
# 		  -Wformat-type-confusion						\
# 		  -Wpointer-arith								\
# 		  -Widiomatic-parentheses						\
# 		  -Wunreachable-code-aggressive					\
# 		  -fstack-protector-all							\
# 		  -fPIE											\
# 		  -fno-optimize-sibling-calls					\
# 		  -I$(INCLUDE_DIRECTORY)						\


LIBRARY_DIRECTORY = ./lib
SOURCE_DIRECTORY = ./source
INCLUDE_DIRECTORY = ./include

C_SOURCE_FILES = $(wildcard $(SOURCE_DIRECTORY)/*.c)
C_OBJ_FILES = $(patsubst $(SOURCE_DIRECTORY)/%.c, $(SOURCE_DIRECTORY)/%.o, $(C_SOURCE_FILES))
EXECUTABLE_NAME = pipex

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): $(C_OBJ_FILES) | lib
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBRARY_DIRECTORY) -lclib

$(C_OBJ_FILES): $(SOURCE_DIRECTORY)/%.o: $(SOURCE_DIRECTORY)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

lib:
	$(MAKE) -C $(LIBRARY_DIRECTORY)

clean:
	rm -f $(C_OBJ_FILES)
	$(MAKE) -C $(LIBRARY_DIRECTORY) clean

fclean: clean
	rm -f $(EXECUTABLE_NAME)
	$(MAKE) -C $(LIBRARY_DIRECTORY) fclean

re: fclean all

.PHONY: all clean fclean re lib

