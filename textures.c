/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/04/03 15:40:13 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures    *load_textures(t_data *game)
{
    t_textures  *textures;
    int w;
    int h;

    textures = malloc(sizeof(t_textures));
    if (!textures)
        return (NULL);
    // textures->w = game->width;
    // textures->h = game->height;
    game->textures->wall = mlx_xpm_file_to_image(game->mlx, "./ressources/wall64.xpm", &w, &h);
    if (!textures->wall)
        printf("Error: could not load wall texture.\n");

    game->textures->player = mlx_xpm_file_to_image(game->mlx, "./ressources/alien.xpm", &w, &h);
    if (!textures->player)
        printf("Error: could not load player texture.\n");

    game->textures->exit = mlx_xpm_file_to_image(game->mlx, "./ressources/door.xpm", &w, &h);
    if (!textures->exit)
        printf("Error: could not load exit texture.\n");

    game->textures->floor = mlx_xpm_file_to_image(game->mlx, "./ressouces/tile64.xpm", &w, &h);
    if (!textures->floor)
        printf("Error: could not load floor texture.\n");

    return (textures);
}
