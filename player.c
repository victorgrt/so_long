/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:27:39 by victor            #+#    #+#             */
/*   Updated: 2023/04/01 13:31:29 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos_player(t_map *map, t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}