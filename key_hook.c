/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:06:22 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/17 13:15:02 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_move(t_data *game, int last, char c)
{
	if (c == 'u')
	{
		if (game->move != last)
		{
			printf("Move : %d ↑\n", game->move);
			last++;
		}
	}
	if (c == 'l')
	{
		if (game->move != last)
		{
			printf("Move : %d ←\n", game->move);
			last++;
		}
	}
	if (c == 'r')
	{
		if (game->move != last)
		{
			printf("Move : %d →\n", game->move);
			last++;
		}
	}
	if (c == 'd')
	{
		if (game->move != last)
		{
			printf("Move : %d ⬇\n", game->move);
			last++;
		}
	}
}

void	ft_free_game(t_data *game)
{
	int	i = 0;
	
	mlx_destroy_window(game->mlx, game->win);
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	close(game->fd);
	// free(game->mlx);
	// free(game->img);
	// free(game->win);
}

int	key_hook(int keysym, t_data *game)
{
	int last;
	
	last = game->move;
	if (keysym == 113 || keysym == 65307)
	{
		ft_free_game(game);
		exit(0);
		return (0);
	}
	if (keysym == 65362 || keysym == 65364 || keysym == 65363
		|| keysym == 65361)
	{
		if (keysym == 65362)
		{
			up(&game);
			print_move(game, last, 'u');
		}
		if (keysym == 65364)
		{
			down(&game);
			print_move(game, last, 'd');
		}
		if (keysym == 65361)
		{
			left(&game);
			print_move(game, last, 'l');
		}
		if (keysym == 65363)
		{
			right(&game);
			print_move(game, last, 'r');
		}
	}

	return (0);
}

int	handle_keyrelease(int keysym)
{
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}