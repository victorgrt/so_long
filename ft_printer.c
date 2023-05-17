/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:41:54 by victor            #+#    #+#             */
/*   Updated: 2023/05/17 16:30:58 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_error(char *str)
{
	perror(str);
	exit(0);
}

void	print_win(t_data *game)
{
	ft_printf("\033[0;32m██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗\n\
╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n\
░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n\
░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n\
░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n\
░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n\033[0m");
	ft_printf("\033[0;32mYou	won	in	only	\033[1m%d\033[0m\033[0;32m	moves\
		,	good	job !\033[0m\n", game->move);
}

void	print_loose(void)
{
	ft_printf("\033[0;31m██╗░░░██╗░█████╗░██╗░░░██╗  ██╗░░░░░░█████╗░░█████╗░░████\
	██╗███████╗\n╚██╗░██╔╝██╔══██╗██║░░░██║  ██║░░░░░██╔══██╗██╔══██╗██╔════╝██╔══\
	══╝\n░╚████╔╝░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║╚█████╗░█████╗░░\n░░╚\
	██╔╝░░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║░╚═══██╗██╔══╝░░\n░░░██║░░░╚██\
	███╔╝╚██████╔╝  ███████╗╚█████╔╝╚█████╔╝██████╔╝███████╗\n░░░╚═╝░░░░╚════╝░░╚══\
	═══╝░  ╚══════╝░╚════╝░░╚════╝░╚═════╝░╚══════╝\n\033[0m");
}

void	print_map(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		ft_printf("%s\tlen : %d\n", game->map[i], ft_strlen(game->map[i]));
		i++;
	}
	ft_printf("fd:%d\t path:%s\nrow:%d\tcol:%d\nc:%d\tp:%d\te:%d\nplayer[%d][%d]\n", \
	game->fd, game->path, game->row, game->col, game->max_c, game->p, game->p, \
	game->player_x, game->player_y);
	ft_printf("check : %d\n", ft_check_objects(game));
}
