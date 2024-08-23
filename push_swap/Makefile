# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plgol.perso <pollivie@student.42.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 14:39:40 by plgol.perso       #+#    #+#              #
#    Updated: 2023/12/01 14:39:43 by plgol.perso      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
RM := rm -f


CFLAGS := -Wall                   					 	\
		  -Werror                 					 	\
		  -Wextra                 					 	\
		  -O2	                  					 	\
		  -march=native           					 	\
		  -ffast-math             					 	\
		  -funroll-loops          					 	\
		  -flto 										\
		  -finline-functions					 		\
		  -fomit-frame-pointer					 		\

# CFLAGS := -Wall -Werror -Wextra -glldb
# CFLAGS =  -Wall 										\
# 		  -Walloca										\
# 		  -Warray-bounds								\
# 		  -Warray-bounds-pointer-arithmetic				\
# 		  -Wassign-enum 								\
# 		  -Wbad-function-cast 							\
# 		  -Wcast-qual									\
# 		  -Wcomma 										\
# 		  -Wconversion									\
# 		  -Wextra 										\
# 		  -Wfloat-equal									\
# 		  -Wformat-security								\
# 		  -Wformat-type-confusion						\
# 		  -Wformat=2									\
# 		  -Widiomatic-parentheses						\
# 		  -Wimplicit-fallthrough						\
# 		  -Wloop-analysis								\
# 		  -Wnull-dereference							\
# 		  -Wpointer-arith								\
# 		  -Wshift-sign-overflow							\
# 		  -Wshorten-64-to-32							\
# 		  -Wstack-protector								\
# 		  -Wswitch-enum									\
# 		  -Wtautological-constant-in-range-compare		\
# 		  -Wunreachable-code-aggressive					\
# 		  -Wvla											\
# 		  -fPIE											\
# 		  -fsanitize=address 							\
# 		  -fsanitize=undefined 							\
# 		  -fstack-protector-all							\
# 		  -glldb										\
# 		  -march=native									\
# 		  -mtune=native									\

NAME := push_swap

INC_DIR := lib
SRC_DIRS := source
SRCS := $(wildcard $(addsuffix /*.c,$(SRC_DIRS)))
OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re plib

all: $(NAME)

$(NAME): $(OBJS) clib
	$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(INC_DIR) -lclib

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clib:
	$(MAKE) -C $(INC_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(INC_DIR) fclean

re: fclean all
