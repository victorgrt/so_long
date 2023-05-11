/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 13:39:01 by vgoret           ###   ########.fr       */
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
	if (keysym == 65362 || keysym == 65364 || keysym == 65363
		|| keysym == 65361)
	{
		if (keysym == 65362)
		{
			up(&game);
			print_move(game, last, "↑");
		}
		if (keysym == 65364)
		{
			down(&game);
			print_move(game, last, "⬇");
		}
		if (keysym == 65361)
		{
			left(&game);
			print_move(game, last, "←");
		}
		if (keysym == 65363)
		{
			right(&game);
			print_move(game, last, "→");
		}
	}
	return (0);
}

int	handle_keyrelease(int keysym)
{
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}
