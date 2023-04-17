/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/17 14:40:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_objects(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	game->p = 0;
	game->e = 0;
	game->max_c = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	while (i < game->row)
	{
		j = 0;
		while (j < game->col - 1)
		{
			if (game->map[i][j] == 'P')
			{
				game->player_y = i;
				game->player_x = j;
				game->p += 1;
			}
			if (game->map[i][j] == 'C')
				game->max_c++;
			if (game->map[i][j] == 'E')
			{
				game->exit_x = j;
				game->exit_y = i;
				game->e++;
			}
			j++;
		}
		i++;
	}
	game->c = 0;
	game->collected = 0;
	printf("c:%d\tmax_c:%d\te:%d\tp:%d\nexit[%d][%d]\n", game->c,
		game->max_c, game->e, game->p, game->exit_x, game->exit_y);
}

int	init_structure(t_data *game)
{
	if (handle_map_error(game) == 1)
	{
		free(game->mlx);
		free(game->win);
		return (1);
	}
	get_pos_player(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * 64,
			game->row * 64, "so_long");
	init_objects(game);
	game->move = 0;
	game->width = game->col * 64;
	game->height = game->row * 64;
	return (0);
}
