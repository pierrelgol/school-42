# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/22 12:01:48 by pollivie          #+#    #+#              #
#    Updated: 2023/09/22 12:01:50 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

srcs = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

name = libft.a

obj	=  ${srcs:.c=.o}

HEADERS	= includes/

.c.o	:
		${CC} ${CFLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

${name} : ${obj}
		ar rc ${name} ${obj}

all : ${name}

clean :
		rm -f ${obj}

fclean :
		rm -f ${name} ${obj}

re : fclean all
