/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/04/02 19:19:50 by victor           ###   ########.fr       */
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
    textures->w = game->width;
    textures->h = game->height;
    textures->wall = mlx_xpm_file_to_image(game->mlx, "./ressources/wall.xpm", &w, &h);
    if (!textures->wall)
        printf("Error: could not load wall texture.\n");

    textures->player = mlx_xpm_file_to_image(game->mlx, "./ressources/player2.xpm", &w, &h);
    if (!textures->player)
        printf("Error: could not load player texture.\n");

    textures->exit = mlx_xpm_file_to_image(game->mlx, "./ressources/door.xpm", &w, &h);
    if (!textures->exit)
        printf("Error: could not load exit texture.\n");

    textures->floor = mlx_xpm_file_to_image(game->mlx, "./ressouces/floor.xpm", &w, &h);
    if (!textures->floor)
        printf("Error: could not load floor texture.\n");

    return (textures);
}
