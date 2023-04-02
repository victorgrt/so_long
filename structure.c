/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/02 18:52:51 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_structure(t_data *game, t_map *map)
{
    // int img_h;
    // int img_w;

    game->map_struc = map;
    get_pos_player(map, game);
    game->c = 0;
    game->e = map->nb_e;
    game->p = map->nb_p;
    game->max_c = map->nb_c;
    game->move = 0;
    game->width = game->map_struc->col * 32;
    game->height = game->map_struc->row * 32;
    // game->player_img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
    // game->player_img->addr = mlx_get_data_addr(game->player_img.img_ptr, &game->player_img.bits_per_pixel, &game->player_img.line_length, &game->player_img.endian);
    // game->floor_img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
    // game->floor_img->addr = mlx_get_data_addr(game->player_img.img_ptr, &game->player_img.bits_per_pixel, &game->player_img.line_length, &game->player_img.endian);


    printf("structure : \nmove : %d\nc :%d\tp :%d\te :%d\nmax_c : %d\nwidth : %d\theight :%d\n", game->move, game->c, game->p, game->e, game->max_c, game->width, game->height);
    return (1);
}