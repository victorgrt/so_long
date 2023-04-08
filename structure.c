/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/08 13:45:09 by vgoret           ###   ########.fr       */
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
				game->e++;
			j++;
		}
		i++;
	}
	game->c = 0;
	//printf("c:%d\tmax_c:%d\te:%d\tp:%d\n", game->c, game->max_c, game->e, game->p);
}

int init_structure(t_data *game)
{
    // int img_h;
    // int img_w;
    
    // game->map = create_map(game);
    if (game->map == NULL)
    {
		printf("Error\nMap pas rectangle\n");
		return (1);
	}
    if (handle_map_error(game) == 1)
    {
	    free(game->mlx);
        free(game->win);
    	return (1);
    }
    // game->map = map->map;
    get_pos_player(game);
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * 64,
			game->row * 64, "so_long");
	init_objects(game);
    game->move = 0;
    game->width = game->col * 64;
    game->height = game->row * 64;
    // printf("structure : \nmove : %d\nc :%d\tp :%d\te :%d\nmax_c : %d\nwidth : %d\theight :%d\n", game->move, game->c, game->p, game->e, game->max_c, game->width, game->height);
    return (0);
}