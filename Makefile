# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 16:44:56 by vgoret            #+#    #+#              #
#    Updated: 2023/04/03 15:34:39 by vgoret           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ! ARGUMENTS ! #

NAME    =	so_long
CCFLAGS =	-g -Wall -Werror -Wextra #-Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
CC      =	gcc

################################################################################
# * SRC * #

SRC = main.c parsing.c ft_check_map.c ft_map.c ft_map2.c ft_printer.c map_info.c \
	player.c utils.c \
	draw_map.c \
	structure.c ft_move.c\
	src/get_next_line.c src/get_next_line_utils.c \
	textures.c \

OBJ = ${SRC:.c=.o}

################################################################################
# ? RULES ? #

all: ${NAME} ok_util

${NAME} : ${OBJ}
	@$(CC) ${OBJ} ${CCFLAGS} -I/usr/include -Imlx_linux -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $@

%.o: %.c
	@$(CC) ${CCFLAGS} -Imlx_linux -c $< -o $@

clean:
	@rm -f ${OBJ}

fclean: clean fclean_util	
	@rm -f ${PROG}
	@rm -f ${OBJ}
	@rm -f ${NAME}
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

ok_util :
	@echo "\n\\033[0;34m	░██████╗░█████╗░  ██╗░░░░░░█████╗░███╗░░██╗░██████╗░\n	██╔════╝██╔══██╗  ██║░░░░░██╔══██╗████╗░██║██╔════╝░\n	╚█████╗░██║░░██║  ██║░░░░░██║░░██║██╔██╗██║██║░░██╗░\n	░╚═══██╗██║░░██║  ██║░░░░░██║░░██║██║╚████║██║░░╚██╗\n	██████╔╝╚█████╔╝  ███████╗╚█████╔╝██║░╚███║╚██████╔╝\n	╚═════╝░░╚════╝░  ╚══════╝░╚════╝░╚═╝░░╚══╝░╚═════╝░\n"