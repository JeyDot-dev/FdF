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

SRC			=	fdf.c	draw_line.c	tests.c	ft_isometric.c	parse_map.c\
				draw_map.c	pts_utils.c
OBJS 		=	${SRC:.c=.o}

INCS 		=	libft		mlx
HEADERS		=	${addprefix -I,${INCS}}
LIB_DIR		=	${addprefix -L,${INCS}}
LIBS		=	-lft -lmlx

INCS_LINUX 			=	libft		minilibx-linux
HEADERS_LINUX		=	${addprefix -I,${INCS_LINUX}}
LIB_DIR_LINUX		=	${addprefix -L,${INCS_LINUX}}
LIBS_LINUX			=	-lft -lmlx_Linux

FRAMEWORKS	=	OpenGL	AppKit
FS			=	${addprefix -framework ,${FRAMEWORKS}}
CFLAGS		=	-Wextra -Werror -Wall

RM			=	rm -rf
CC			=	gcc

#--------------------------------------------------------------------------------

%.o		:	%.c
			${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

all		:	${NAME}

			


${NAME}	:	complib ${OBJS}
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

linux	:	fclean	
			@${MAKE} -s -C minilibx-linux
			@${MAKE} -s -C libft
			${CC} ${CFLAGS} ${HEADERS_LINUX} -I/usr/include -O2  -c ${SRC} 
			$(CC) $(OBJS) -Lminilibx-linux -lmlx_Linux -Llibft -lft  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
