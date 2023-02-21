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
#1;bold 2;low intensity 4;Underline 5;Blink 8;invis 9;strike
BLK	= \033[30m
RED	= \033[31m
GRN	= \033[32m
BRN	= \033[33m
BLU	= \033[34m
PUR	= \033[35m
CYN	= \033[36m
LGR	= \033[37m
RST	= \033[0m

NAME		:=	fdf
UNAME_S 	:= $(shell uname -s)

SRC_D		:=	src/
BUILD_D		:=	.build/
LIB_D		:=	libft/ mlx/
INC			:=	libft	mlx inc

LIB			:=	ft	mlx
INC			:=	inc/ mlx/ libft/
SRC			:=	fdf.c									\
				color/color_utils.c 	color/extract_single_color.c\
				color/line_gradient.c 	color/rgbo_color.c\
				draw/draw_line.c 		draw/draw_map.c\
				draw/draw_pixel.c						\
				pts/ft_isometric.c		pts/parse_map.c\
				pts/pts_utils.c							\
				utils/dup_list.c 		utils/img_utils.c\
				utils/list_utils.c						\
				hook/hook_functions.c 	hook/hook_utils.c\
				hook/hook_utils2.c
FRAMEWORK	:=	OpenGL	AppKit

SRC			:=	$(SRC:%=$(SRC_D)%)
OBJ 		:=	$(SRC:$(SRC_D)%.c=$(BUILD_D)%.o)
DEPS        :=	$(OBJ:.o=.d)

ifeq ($(UNAME_S),Linux)
INC		 	:=	libft	inc	minilibx-linux /usr/include/
LIB_D		:=	minilibx-linux/ libft/ /usr/lib/
LIB			:=	mlx_Linux ft Xext X11 m z
LIBS_LINUX	:=	ft mlx_Linux
FRAMEWORK	:=	
endif
RM			:=	rm -rf
CC			:=	gcc
DIR_DUP     =	mkdir -p "$(@D)"
#-MMD -MP = Used to add dependencies during precomp. (for .h)
CPPFLAGS    :=	-MMD -MP $(addprefix -I,$(INC))
CFLAGS		:=	-Wextra -Werror -Wall -g
# -(r)eplace the older objects, -(c)reate if no lib, -s index stuff
AR          :=	ar
ARFLAGS     :=	-r -c -s
LDFLAGS     :=	$(addprefix -L,$(dir $(LIB_D)))
LDLIBS      :=	$(addprefix -l,$(LIB))
LDFMWK		:=	$(addprefix -framework ,$(FRAMEWORK))
MAKEFLAGS   += --no-print-directory
#-----------------------------all------------------------------------
all		:	$(NAME)
#-----------------------------NAME-----------------------------------
$(NAME)	:	$(OBJ)
			$(MAKE) complib
			${CC} $(OBJ) $(LDFLAGS) $(LDLIBS) $(LDFMWK) -o $(NAME)
			$(info MAKING $(NAME).....)
			echo "\033[5;32m\t\tFinished compiling $(NAME) !!! $(CLR)"
#------------------------OBJ COMPILATION-----------------------------
info		:
			echo $(LDFLAGS) $(LDLIBS) $(LDFMWK)
$(BUILD_D)%.o	:	$(SRC_D)%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(CPPFLAGS) -O2 -c $< -o $@
			echo created $(@F)

-include	${DEPS}
#----------------------------COMPLIB---------------------------------
complib	:
	$(info COMPILING THE LIBS)
ifeq ($(UNAME_S),Linux)
	@$(MAKE) -s -C minilibx-linux
	@$(MAKE) -s -C libft
endif
ifeq ($(UNAME_S),Darwin)
	@$(MAKE) -s -C libft
	@$(MAKE) -s -C mlx
endif
#----------------------------CLEAN-----------------------------------
clean	:
	$(RM) $(OBJ) $(DEPS)
	$(MAKE) -C libft clean
ifeq ($(UNAME_S),Darwin)
	$(MAKE) -C mlx clean
else
	$(MAKE) -C minilibx-linux clean
endif
	$(info CLEANING...)
	echo "$(CYN) \t\tALL CLEANED $(RST)"
#----------------------------FCLEAN----------------------------------
fclean	:	clean
	$(RM) $(NAME)
	$(MAKE) -C libft fclean
ifeq ($(UNAME_S),Darwin)
	$(MAKE) -C mlx clean
else
	$(MAKE) -C minilibx-linux clean
endif
	echo "\033[5;36m \t\tALL F*NG CLEANED !!! $(RST)"
	$(info ALL F*NG CLEANING)
#------------------------------RE------------------------------------
re		:	fclean all

.PHONY	:	all clean fclean re
.SILENT :
