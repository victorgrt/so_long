/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 16:24:04 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_data *game, char *path1)
{
	game->path = path1;
	//col + row initialised
	game->map = create_game(game);
	game->width = game->col * 64;
	game->height = game->row * 64;
	init_objects(game);
	if (ft_check_objects(game) == 1)
	{
		free_tab(game->map);
		ft_print_error("Error\nCheck Assets of the map");
	}
	printf("c:%d\n", game->c);
	game->move = 0;

    game->mlx = mlx_init();
	init_img(game);
		// close_window3(game);
	game->win = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");

	ft_generate_window(game);
	return (0);
}

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
}
