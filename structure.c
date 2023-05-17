/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/05/17 14:41:18 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_data *game, char *path1)
{	
	game->path = path1;
	game->map = create_game(game);
	game->width = (game->col - 1) * 64;
	game->height = game->row * 64;
	game->p = 0;
	game->e = 0;
	game->max_c = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	init_objects(game);
	game->c = 0;
	game->collected = 0;
	game->collected_flood = 0;
	ft_flood_map(game);
	if (game->collected_flood != game->max_c)
	{
		printf("collected %d\n", game->collected_flood);
		free_tab(game->map);
		ft_print_error("Error\nMap not Doable");
	}
	if (ft_check_objects(game) == 1)
	{
		free_tab(game->map);
		ft_print_error("Error\nCheck Assets of the map");
	}
	game->move = 0;
	game->mlx = mlx_init();
	init_img(game);
	game->win = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	ft_generate_window(game);
	return (0);
}

void	init_objects(t_data *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->row)
	{
		j = -1;
		while (++j < game->col - 1)
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
		}
	}
}
