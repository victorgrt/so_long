/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/04 16:31:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_structure(t_data *game, char *av, int fd)
{
    // int img_h;
    // int img_w;
    
    game->map_struc = init_map(av, fd);
    int i = 0;
    while (game->map_struc->map[i])
    {
        printf("%s\n", game->map_struc->map[i]);
        i++;
    }
    if (game->map_struc->map == NULL)
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
    get_pos_player(game->map_struc, game);
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map_struc->col * 64,
			game->map_struc->row * 64, "so_long");
    game->c = 0;
    game->e = game->map_struc->nb_e;
    game->p = game->map_struc->nb_p;
    game->move = 0;
    game->width = game->map_struc->col * 64;
    game->height = game->map_struc->row * 64;
    // printf("structure : \nmove : %d\nc :%d\tp :%d\te :%d\nmax_c : %d\nwidth : %d\theight :%d\n", game->move, game->c, game->p, game->e, game->max_c, game->width, game->height);
    return (0);
}