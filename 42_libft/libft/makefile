SRCS =  ft_isalpha.c 	\
		ft_isdigit.c    \
		ft_isalnum.c    \
		ft_isascii.c    \
		ft_isprint.c    \
		ft_strlen.c     \
		ft_memset.c     \
		ft_bzero.c      \
		ft_memcpy.c     \
		ft_memmove.c    \
		ft_strlcpy.c    \
		ft_strlcat.c    \
		ft_toupper.c    \
		ft_tolower.c    \
		ft_strchr.c     \
		ft_strrchr.c    \
		ft_strncmp.c    \
		ft_memchr.c     \
		ft_memcmp.c     \
		ft_strnstr.c    \
		ft_atoi.c       \
		ft_calloc.c     \
		ft_strdup.c     \
		ft_substr.c     \
		ft_strjoin.c    \
		ft_strtrim.c    \
		ft_split.c      \
		ft_itoa.c       \
		ft_strmapi.c	\
		ft_striteri.c	\
		ft_putchar_fd.c \
		ft_putstr_fd.c  \
		ft_putendl_fd.c \
		ft_putnbr_fd.c  \
				
OBJS = $(SRCS:.c=.o)

BONUS = ./bonus/ft_lstadd_back.c  \
		./bonus/ft_lstadd_front.c \
		./bonus/ft_lstclear.c 	  \
        ./bonus/ft_lstdelone.c    \
		./bonus/ft_lstiter.c      \
		./bonus/ft_lstlast.c  	  \
        ./bonus/ft_lstmap.c       \
		./bonus/ft_lstnew.c       \
		./bonus/ft_lstsize.c      \

BONUS_OBJS = $(BONUS:.c=.o)

MATH = ./math/ft_abs.c		\
	   ./math/ft_absf.c	\
	   ./math/ft_asin.c	\
	   ./math/ft_atan.c 	\
	   ./math/ft_atan2.c 	\
	   ./math/ft_atocs.c 	\
	   ./math/ft_cos.c 	\
	   ./math/ft_fact.c 	\
	   ./math/ft_factf.c 	\
	   ./math/ft_log10n.c 	\
	   ./math/ft_log2n.c 	\
	   ./math/ft_pow.c 	\
	   ./math/ft_powf.c 	\
	   ./math/ft_sin.c 	\
	   ./math/ft_sqrt.c 	\
	   ./math/ft_tan.c 	\

MATH_OBJS = $(MATH:.c=.o)

SORT = ./sort/ft_sort.c \
SORT_OBJS = $(SORT:.c=.o)

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a

.PHONY: all clean fclean re bonus test

complete: all bonus math sort

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

sort: $(OBJS) $(SORT_OBJS)
	ar rcs $(NAME) $(OBJS) $(SORT_OBJS)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

math: $(OBJS) $(MATH_OBJS)
	ar rcs $(NAME) $(OBJS) $(MATH_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft_unit_test

re: fclean all
