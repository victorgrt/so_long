/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/05/17 17:10:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move(t_data **game, char c)
{
	render_img((*game), '0', (*game)->player_x * 64, (*game)->player_y * 64);
	if (c == 'u')
		(*game)->player_y--;
	else if (c == 'd')
		(*game)->player_y++;
	else if (c == 'l')
		(*game)->player_x--;
	else if (c == 'r')
		(*game)->player_x++;
	else
		return ;
	(*game)->move++;
	if (c == 'r' || c == 'u')
		render_player(game, 1, 'R');
	else
		render_player(game, 2, 'P');
}

void	left(t_data **game)
{
	if ((*game)->map[(*game)->player_y][(*game)->player_x
		- 1] != '1')
	{
		if ((*game)->map[(*game)->player_y][(*game)->player_x
			- 1] == 'C')
		{
			(*game)->map[(*game)->player_y][(*game)->player_x - 1] = '0';
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
			(*game)->map[(*game)->player_y + 1][(*game)->player_x] = '0';
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
			(*game)->map[(*game)->player_y - 1][(*game)->player_x] = '0';
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
			(*game)->map[(*game)->player_y][(*game)->player_x + 1] = '0';
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
