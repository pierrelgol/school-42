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
CFLAGS = -Wall -Wextra -Werror

srcs = ft_display_file.c
name = ft_display_file
obj = $(srcs:.c=.o)

.PHONY: all clean fclean re

$(name) : $(obj)
	$(CC) $(CFLAGS) $(obj) -o $@

all : $(name)

clean :
	rm -f $(obj)

fclean : clean
	rm -f $(name)

re : fclean all
