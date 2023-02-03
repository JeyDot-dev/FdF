SRC			=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		ft_isascii.c	\
		  		ft_isprint.c		ft_strlen.c			ft_memset.c			ft_bzero.c		\
		  		ft_memcpy.c			ft_memmove.c		ft_strlcpy.c		ft_strlcat.c	\
		  		ft_toupper.c		ft_tolower.c		ft_strchr.c			ft_strrchr.c	\
		  		ft_strncmp.c		ft_memchr.c			ft_memcmp.c			ft_strnstr.c	\
		  		ft_atoi.c			ft_calloc.c			ft_strdup.c			ft_substr.c		\
		  		ft_strjoin.c		ft_strtrim.c		ft_split.c			ft_itoa.c		\
		  		ft_strmapi.c		ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c	\
		  		ft_putendl_fd.c		ft_putnbr_fd.c		ft_itoa_base.c		ft_printf.c		\
				ft_lstnew.c			ft_lstadd_front.c	ft_lstsize.c	\
				ft_lstlast.c		ft_lstadd_back.c	ft_lstdelone.c	\
				ft_lstclear.c		ft_lstiter.c		ft_lstmap.c		\
				ft_abs.c \
				get_next_line/get_next_line.c	get_next_line/get_next_line_utils.c			\

NAME			= libft.a
TESTNAME		= tst
OBJS			= ${SRC:.c=.o}
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

${NAME}		:	${OBJS}
				ar -rcs ${NAME} ${OBJS}
				ranlib ${NAME}

#bonus		:	${OBJS} ${OBJSBONUS}
#				ar -rcs ${NAME} ${OBJS} ${OBJSBONUS}

all			:	${NAME}

${TESTNAME}	:	all
				${CC} ${CFLAGS} ${addsuffix .c,$@} ${NAME}

clean		:
				${RM} ${OBJS} ${OBJSBONUS}
fclean		:	clean
				${RM} ${NAME}
allclean	:	fclean
				${RM} ./a.out
re			:	fclean all
.PHONY		:	tst
