NAME	= libft.a
SRCS	= ${MEMS} ${STRS} ${OTHERS} ${ISFTS} ${PUTS}
MEMS	= ft_memccpy.c ft_memmove.c ft_memcpy.c ft_memset.c ft_memchr.c ft_memcmp.c
STRS	= ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strjoin.c ft_strtrim.c ft_strmapi.c
OTHERS	= ft_tolower.c ft_toupper.c ft_bzero.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_split.c ft_itoa.c
ISFTS	= ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c
PUTS	= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnbr_fd.c
BONUS	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
CC		= gcc
OBJS	= ${SRCS:.c=.o}
BONOBJS	= ${BONUS:.c=.o}
HEADER	= libft.h
CFLAGS	= -Wall -Wextra -Werror $(IDIR)
RM		= rm -f

all:		${NAME}

$(NAME):	${SRCS} ${HEADER}
			${CC} ${CFLAGS} -c ${SRCS}
			ar rc $(NAME) ${OBJS}

bonus:
			${CC} ${CFLAGS} -c ${BONUS}
			ar rc $(NAME) ${BONOBJS}

clean:
			${RM} ${OBJS} ${BONOBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all