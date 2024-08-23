# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie.student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/13 16:41:30 by pollivie          #+#    #+#              #
#    Updated: 2024/08/13 16:41:31 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
SRC_DIRS := $(shell find . -type d -name src)
INC_DIRS := $(shell find . -type d -name include | sed 's/^/-I/')
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')
OBJS := $(SRCS:.cpp=.o)
NAME := program

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC_DIRS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
