/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_directions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:03:45 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/17 15:05:37 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_data **game)
{
	int	i;

	i = 0;
	while ((*game)->map[i])
	{
		ft_printf("%s\n", (*game)->map[i]);
		i++;
	}
}

void	left(t_data **game)
{
	if ((*game)->map[(*game)->player_y][(*game)->player_x
		- 1] != '1')
	{
		if ((*game)->map[(*game)->player_y][(*game)->player_x
			- 1] == 'C')
		{
			ft_collect(game, 'l');
			return ;
		}
		else if ((*game)->map[(*game)->player_y]
			[(*game)->player_x - 1] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'l');
	}
}

void	down(t_data **game)
{
	if ((*game)->map[(*game)->player_y + 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map[(*game)->player_y + 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'd');
			return ;
		}
		else if ((*game)->map[(*game)->player_y
				+ 1][(*game)->player_x] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'd');
	}
}

void	up(t_data **game)
{
	if ((*game)->map[(*game)->player_y - 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map[(*game)->player_y - 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'u');
			return ;
		}
		else if ((*game)->map[(*game)->player_y
				- 1][(*game)->player_x] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'u');
	}
}

void	right(t_data **game)
{
	if ((*game)->map[(*game)->player_y][(*game)->player_x
		+ 1] != '1')
	{
		if ((*game)->map[(*game)->player_y][(*game)->player_x
			+ 1] == 'C')
		{
			ft_collect(game, 'r');
			return ;
		}
		else if ((*game)->map[(*game)->player_y]
			[(*game)->player_x + 1] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'r');
	}
}