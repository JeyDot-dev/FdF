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
Name		=	fdf

Src			=	fdf.c
Objs 		=	${SRC:.c=.o}

INCS 		=	./libft		./mlx
HEADERS		=	${addprefix -I,${INCS}}
LIB_DIR		=	${addprefix -L,${INCS}}
LIBS		=	-lft -lmlx

FRAMEWORKS	=	OpenGL	AppKit
FS			=	${addprefix -framework ,${FRAMEWORKS}}

RM			=	rm -rf
CC			=	gcc

CFLAGS		=	-Wextra -Werror -Wall
#--------------------------------------------------------------------------------

%.o		:	%.c
			${CC} ${CFLAGS} ${HEADERS} -c $< -o %@

all		:	${NAME}

${NAME}	:	${OBJS} complib
			${CC} ${OBJS} ${LIB_DIR} ${LIBS} ${FS} -o ${NAME}

complib	:
			make -C ./libft all
			make -C ./mlx all

clean	:	
			${RM} ${OBJS}
			make -C ./libft clean
			make -C ./mlx clean

fclean	:	
			clean
			${RM} ${NAME} ./mlx/libmlx.a
			make -C ./libft fclean

re		:	fclean all

.PHONY	:	all clean fclean re
