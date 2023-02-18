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

SRC_COLOR	=	color_utils.c extract_single_color.c \
				line_gradient.c rgbo_color.c
SRC_DRAW	=	draw_line.c draw_map.c draw_pixel.c
SRC_PTS		=	ft_isometric.c parse_map.c pts_utils.c
SRC_UTILS	=	dup_list.c img_utils.c list_utils.c
SRC_HOOK	=	hook_functions.c hook_utils.c hook_utils2.c

SRC_DIR		=	src/
OBJ_DIR		=	obj/

SRC			=	${SRC_DIR}fdf.c \
				${addprefix ${SRC_DIR}color/,${SRC_COLOR}} \
				${addprefix ${SRC_DIR}draw/,${SRC_DRAW}} \
				${addprefix ${SRC_DIR}pts/,${SRC_PTS}} \
				${addprefix ${SRC_DIR}utils/,${SRC_UTILS}}\
				${addprefix ${SRC_DIR}hook/,${SRC_HOOK}}

OBJ 		=	${SRC:%.c=%.o}
OBJF		=	${addprefix ${OBJ_DIR},${notdir ${OBJ}}}

HEADER_DIR	=	libft	mlx inc
LIB_DIR		=	libft/ mlx/
LIB_FILES	=	ft mlx

HEADERS		=	${addprefix -I,${HEADER_DIR}}
LIBS		=	${addprefix -L,${LIB_DIR}} ${addprefix -l,${LIB_FILES}}

INCS_LINUX 			=	libft		minilibx-linux
HEADERS_LINUX		=	${addprefix -I,${INCS_LINUX}} -Iinc
LIB_DIR_LINUX		=	${addprefix -L,${INCS_LINUX}}
LIBS_LINUX			=	-lft -lmlx_Linux

FRAMEWORKS	=	OpenGL	AppKit
FS			=	${addprefix -framework ,${FRAMEWORKS}}
CFLAGS		=	-Wextra -Werror -Wall

RM			=	rm -rf
CC			=	gcc

#--------------------------------------------------------------------------------

%.o		:	%.c
			${CC} ${CFLAGS} ${HEADERS} -c $< -o ${addprefix ${OBJ_DIR},${notdir $@}}

all		:	${NAME}

${NAME}	:	complib ${OBJ}
			${CC} ${OBJF} ${LIBS} ${FS} -o ${NAME}

complib	:
			@${MAKE} -s -C libft
			@${MAKE} -s -C mlx

linux	:	fclean cleanlinux	
			@${MAKE} -s -C minilibx-linux
			@${MAKE} -s -C libft
			${CC} ${CFLAGS} ${HEADERS_LINUX} -I/usr/include -O2  -c ${SRC}
			$(CC) ${addsuffix .o,${notdir ${basename ${SRC}}}}  -Lminilibx-linux -lmlx_Linux -Llibft -lft  -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

cleanlinux :
			${RM} ${NAME}
			${MAKE} -C libft fclean
			${MAKE} -C minilibx-linux clean
			${RM} ${addsuffix .o,${notdir ${basename ${SRC}}}}
clean	:
			${RM} ${OBJ}
			${MAKE} -C ./libft clean
			${MAKE} -C ./mlx clean

fclean	:	clean
			${RM} ${NAME} ./mlx/libmlx.a
			${MAKE} -C ./libft fclean

re		:	fclean all

.PHONY	:	all clean fclean re
