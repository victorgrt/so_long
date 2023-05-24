/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:53 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/22 13:47:12 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_finder(t_data *game, char **map)
{
	int	i;
	int	y;

	i = -1;
	while (map[++i])
	{
		y = -1;
		while (map[i][++y])
		{
			if (map[i][y] == 'C' || (map[i][y] == 'E' && \
			(game->collected_flood != game->max_c)))
				return (0);
		}
	}
	return (1);
}

void	flood_map(t_data *game, char **map, int row, int col)
{
	int	i;
	int	j;

	i = row;
	j = col;
	if (i < 0 || j < 0 || i >= game->row || j >= game->col)
		return ;
	if (map[i][j] == '1' || map[i][j] == '2' || (map[i][j] == 'E' \
		&& game->exit_flood != 1))
	{
		if (map[i][j] == 'E')
			game->exit_flood++;
		return ;
	}
	if (map[i][j] == 'C')
	{
		game->collected_flood++;
		map[i][j] = '2';
	}
	map[i][j] = '2';
	flood_map(game, map, i + 1, j);
	flood_map(game, map, i, j + 1);
	flood_map(game, map, i - 1, j);
	flood_map(game, map, i, j - 1);
}

void	ft_flood_map(t_data *game)
{
	char	**map;

	game->exit_flood = 0;
	game->collected_flood = 0;
	map = create_game(game);
	flood_map(game, map, game->player_y, game->player_x);
	if (path_finder(game, map) == 0 || game->collected_flood != game->max_c \
		|| game->exit_flood != 1)
	{
		free_tab(map);
		free_tab(game->map);
		ft_print_error("Error\nNo path found");
	}
	free_tab(map);
}
