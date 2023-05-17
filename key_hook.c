/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/17 17:04:10 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_data *game, int last, char *c)
{
	if (game->move != last)
	{
		ft_printf("Move : %d %s\r", game->move, c);
		last++;
	}
}

void	key_hook2ndpart(int keysym, t_data *game, int last)
{
	if (keysym == 97)
	{
		left(&game);
		print_move(game, last, "←");
	}
	if (keysym == 100)
	{
		right(&game);
		print_move(game, last, "→");
	}
}

int	key_hook(int keysym, t_data *game)
{
	int	last;

	last = game->move;
	if (keysym == 113 || keysym == 65307)
	{
		close_window2(game);
		exit(0);
		return (0);
	}
	if (keysym == 119)
	{
		up(&game);
		print_move(game, last, "↑");
	}
	if (keysym == 115)
	{
		down(&game);
		print_move(game, last, "⬇");
	}
	key_hook2ndpart(keysym, game, last);
	return (0);
}

int	handle_keyrelease(int keysym)
{
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}
