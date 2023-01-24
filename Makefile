#									 #
#			 _______                 #
#			 \  ___ `'.              #
#		 _.._ ' |--.\  \       _.._  #
#	   .' .._|| |    \  '    .' .._| #
#	   | '    | |     |  '   | '     #
#	 __| |__  | |     |  | __| |__   #
#	|__   __| | |     ' .'|__   __|  #
#	   | |    | |___.' /'    | |     #
#	   | |   /_______.'/     | |     #
#	   | |   \_______|/      | |     #
#	   | |                   | |     #
#	   |_|                   |_|     #
#/''''''''''''''''''''''''''''''''''\#	   
NAME		=	fdf

SRC			=	fdf.c
OBJS 		=	${SRC:.c=.o}

INCS 		=	libft		mlx
HEADERS		=	${addprefix -I,${INCS}}
LIB_DIR		=	${addprefix -L,${INCS}}
LIBS		=	-lft -lmlx

FRAMEWORKS	=	OpenGL	AppKit
FS			=	${addprefix -framework ,${FRAMEWORKS}}
CFLAGS		=	-Wextra -Werror -Wall

RM			=	rm -rf
CC			=	gcc

#--------------------------------------------------------------------------------

%.o		:	%.c
			${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

all		:	${NAME}

${NAME}	:	${OBJS} complib
			${CC} ${OBJS} ${LIB_DIR} ${LIBS} ${FS} -o ${NAME}

complib	:
			@${MAKE} -s -C libft
			@${MAKE} -s -C mlx

clean	:	
			${RM} ${OBJS}
			@${MAKE} -s -C ./libft clean
			@${MAKE} -s -C ./mlx clean

fclean	:	clean	
			${RM} ${NAME} ./mlx/libmlx.a
			${MAKE} -C ./libft fclean

re		:	fclean all

.PHONY	:	all clean fclean re
