/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/04/08 22:10:35 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	set_img(t_data *game)
{
	game->img.height = 64;
	game->img.width = 64;
	game->img.floor = "./ressources/water.xpm";
	game->img.wall = "./ressources/brick.xpm";
	game->img.collect = "./ressources/collect.xpm";
	game->img.player = "./ressources/alien.xpm";
	game->img.exit = "./ressources/door.xpm";
	game->img.img_wall = mlx_xpm_file_to_image(game->mlx, game->img.wall,
			&(game->img.width), &(game->img.height));
	game->img.img_floor = mlx_xpm_file_to_image(game->mlx, game->img.floor,
			&(game->img.width), &(game->img.height));
	game->img.img_exit = mlx_xpm_file_to_image(game->mlx, game->img.exit,
			&(game->img.width), &(game->img.height));
	game->img.img_collect = mlx_xpm_file_to_image(game->mlx,
			game->img.collect, &(game->img.width), &(game->img.height));
	game->img.img_player = mlx_xpm_file_to_image(game->mlx,
			game->img.player, &(game->img.width), &(game->img.height));
}*/

/*t_textures	*load_textures(t_data *game)
{
	t_textures	*textures;
	int			w;
	int			h;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	// textures->w = game->width;
	// textures->h = game->height;
	game->textures->wall = mlx_xpm_file_to_image(game->mlx,
			"./ressources/wall64.xpm", &w, &h);
	if (!textures->wall)
		ft_printf("Error: could not load wall texture.\n");
	game->textures->player = mlx_xpm_file_to_image(game->mlx,
			"./ressources/alien.xpm", &w, &h);
	if (!textures->player)
		ft_printf("Error: could not load player texture.\n");
	game->textures->exit = mlx_xpm_file_to_image(game->mlx,
			"./ressources/door.xpm", &w, &h);
	if (!textures->exit)
		ft_printf("Error: could not load exit texture.\n");
	game->textures->floor = mlx_xpm_file_to_image(game->mlx,
			"./ressouces/tile64.xpm", &w, &h);
	if (!textures->floor)
		ft_printf("Error: could not load floor texture.\n");
	return (textures);
}*/
