/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:28:54 by victor            #+#    #+#             */
/*   Updated: 2023/04/03 21:35:07 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int init_structure(t_data *game, char *av, int fd)
{
    // int img_h;
    // int img_w;
    s_player    *player;
    
    game->map_struc = init_map(av, fd);
    if (game->map_struc->map == NULL)
    {
        printf("Error\nMap pas rectangle\n");
        return (0);
    }
    player = malloc(sizeof(s_player));
    if (!player)
    {
        printf("Erreur de malloc du player\n");
        return (0);
    }
    if (handle_map_error(game->map_struc, player) == 1)
		return (1);
    // game->map = map->map;
    get_pos_player(game->map_struc, game);
    game->c = 0;
    game->e = game->map_struc->nb_e;
    game->p = game->map_struc->nb_p;
    game->max_c = game->map_struc->nb_c;
    game->move = 0;
    game->width = game->map_struc->col * 64;
    game->height = game->map_struc->row * 64;
    // game->player_img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
    // game->player_img->addr = mlx_get_data_addr(game->player_img.img_ptr, &game->player_img.bits_per_pixel, &game->player_img.line_length, &game->player_img.endian);
    // game->floor_img->img_ptr = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
    // game->floor_img->addr = mlx_get_data_addr(game->player_img.img_ptr, &game->player_img.bits_per_pixel, &game->player_img.line_length, &game->player_img.endian);
    printf("structure : \nmove : %d\nc :%d\tp :%d\te :%d\nmax_c : %d\nwidth : %d\theight :%d\n", game->move, game->c, game->p, game->e, game->max_c, game->width, game->height);
    
    return (1);
}