# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:44:56 by vgoret            #+#    #+#              #
#    Updated: 2023/04/17 15:05:55 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! ARGUMENTS ! #

NAME    =	so_long
CCFLAGS =	-g -Wall -Werror -Wextra #-Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
CC      =	gcc

################################################################################
# * SRC * #

SRC = so_long.c \
	main.c parsing.c ft_check_map.c ft_map.c ft_printer.c map_info.c \
	player.c utils.c \
	draw_map.c \
	structure.c ft_move.c ft_move_directions.c\
	src/get_next_line.c src/get_next_line_utils.c \
	textures.c action.c key_hook.c\
	ft_free.c ft_render.c\

OBJ = ${SRC:.c=.o}

################################################################################
# ? RULES ? #

NONE='\033[0m'
GREEN='\033[32m'
RED='\033[31m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'
BOLD='\033[1m'
BLUE='\033[0;34m'

all: ${NAME} title

${NAME} : ${OBJ}
	@echo ${BOLD} ${YELLOW} "○	Making Ft_printf..." ${NONE}	
	@make -C ./src/ft_printf
	@echo ${BOLD} ${BLUE} "\033[1m○	Compiling files..." ${NONE}
	$(CC) ${OBJ} ${CCFLAGS} -I/usr/include -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz ./src/ft_printf/ft_printf.a -o $@
	@echo ${BOLD} ${GREEN} "‣	Compiled !" ${NONE}

%.o: %.c
	@$(CC) ${CCFLAGS} -Imlx_linux -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean	
	@echo ${RED} ${BOLD} "‣	Deleting..." ${NONE}
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@${foreach value, $(OBJ), echo ${value};}
	@rm -f ${NAME}
	@rm -f ./src/ft_printf/ft_printf.a
	@rm -f ./src/ft_printf/*.o
	@rm -f ./a.out

re : fclean all

.PHONY : all clean fclean all re

################################################################################
# TODO  UTILS   TODO #

fclean_util : 
	@echo "\\033[1;31m DELETED\\033[0;39m"
	@tput sgr0;
	@${foreach value, $(OBJ), echo "\\033[1;31m >> \\033[0;39m" ${value};}
	@${foreach value, $(NAME), echo "\\033[1;31m >> \\033[0;39m" ${value};} 
	@echo "⣿⣷⡶⠚⠉⢀⣤⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⠠⣴⣿⣿⣿⣿⣶⣤⣤⣤\n⠿⠥⢶⡏⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠋⢀⣴⣷⣌⢿⣿⣿⣿⣿⣿⣿⣿\n⣍⡛⢷⣠⣿⣿⣿⣿⣿⣟⠻⣯⠽⣿⣿⠟⠁⣠⠿⠿⣿⣿⣎⠻⣿⣿⣿⡿⠟⣿\n⣿⣿⣦⠙⣿⣿⣿⣿⣿⣿⣷⣏⡧⠙⠁⣀⢾⣧    ⠈⣿⡟  ⠙⣫⣵⣶⠇⣋\n⣿⣿⣿⢀⣿⣿⣿⣿⣿⣿⣿⠟⠃⢀⣀⢻⣎⢻⣷⣤⣴⠟  ⣠⣾⣿⢟⣵⡆⢿\n⣿⣯⣄⢘⢻⣿⣿⣿⣿⡟⠁⢀⣤⡙⢿⣴⣿⣷⡉⠉⢀  ⣴⣿⡿⣡⣿⣿⡿⢆\n⠿⣿⣧⣤⡘⢿⣿⣿⠏  ⡔⠉⠉⢻⣦⠻⣿⣿⣶⣾⡟⣼⣿⣿⣱⣿⡿⢫⣾⣿\n⣷⣮⣝⣛⣃⡉⣿⡏  ⣾⣧⡀    ⣿⡇⢘⣿⠋    ⠻⣿⣿⣿⢟⣵⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣌⢧⣴⣘⢿⣿⣶⣾⡿⠁⢠⠿⠁⠜    ⣿⣿⣿⣿⡿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣦⡙⣿⣷⣉⡛⠋    ⣰⣾⣦⣤⣤⣤⣿⢿⠟⢋⣴⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⢿⣿⣿⣿⣿⢰⡿⣻⣿⣿⣿⣿⣿⢃⣰⣫⣾⣿⣿⣿\n⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠿⠿⠿⠛⢰⣾⡿⢟⣭⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n"

title :
	@echo "\n\\033[0;34m	░██████╗░█████╗░  ██╗░░░░░░█████╗░███╗░░██╗░██████╗░\n	██╔════╝██╔══██╗  ██║░░░░░██╔══██╗████╗░██║██╔════╝░\n	╚█████╗░██║░░██║  ██║░░░░░██║░░██║██╔██╗██║██║░░██╗░\n	░╚═══██╗██║░░██║  ██║░░░░░██║░░██║██║╚████║██║░░╚██╗\n	██████╔╝╚█████╔╝  ███████╗╚█████╔╝██║░╚███║╚██████╔╝\n	╚═════╝░░╚════╝░  ╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░\n"