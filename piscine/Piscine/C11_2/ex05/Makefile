# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pollivie <pollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 10:15:17 by pollivie          #+#    #+#              #
#    Updated: 2023/09/28 10:10:21 by pollivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_do-op.c ft_helper.c
NAME = do-op
OBJS =  ${SRCS:.c=.o}

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all : ${NAME}

clean : 
	${RM} ${OBJS}

fclean : clean
		${RM} ${NAME}

re : fclean all
