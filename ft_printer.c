/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:41:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/04 12:21:10 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_print_info(t_map *map, char *path, int fd, t_data img)
{
    printf("\033[1m#--\033[0;34m %s \033[0m\033[1m--#\033[0m\n\
-fd: %d\n\
-row: %d\tcol:%d\n\
-map info:\n  P:%d\n  E:%d\n  C:%d\n\
-player[%d][%d]\n\
\033[1m#-------------------#\033[0m\n", path, fd, map->row, map->col, map->nb_p, map->nb_e, map->nb_c, img.player_x, img.player_y);
}

void    print_win(t_data *game)
{
    ft_printf("\033[0;32m██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗\n╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n\033[0m");
    ft_printf("\033[0;32mYou	won	in	only	\033[1m%d\033[0m\033[0;32m	moves,	good	job !\n", game->move);
}

void    print_loose()
{
    ft_printf("\033[0;31m██╗░░░██╗░█████╗░██╗░░░██╗  ██╗░░░░░░█████╗░░█████╗░░██████╗███████╗\n╚██╗░██╔╝██╔══██╗██║░░░██║  ██║░░░░░██╔══██╗██╔══██╗██╔════╝██╔════╝\n░╚████╔╝░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║╚█████╗░█████╗░░\n░░╚██╔╝░░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║░╚═══██╗██╔══╝░░\n░░░██║░░░╚█████╔╝╚██████╔╝  ███████╗╚█████╔╝╚█████╔╝██████╔╝███████╗\n░░░╚═╝░░░░╚════╝░░╚═════╝░  ╚══════╝░╚════╝░░╚════╝░╚═════╝░╚══════╝\n\033[0m");
}

// int main (void)
// {
//     print_win();
//     print_loose();
//     return (0);
// }