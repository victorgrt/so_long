/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/05/14 16:36:00 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fail_xpm(t_data *game, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tab(game->map);
	ft_print_error("Error\nTexture introuvable");
}

void	init_img2ndpart(t_data *game)
{
	int	img_x;
	int	img_y;

	(*game).exit_colored = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/exit_colored.xpm", &img_x, &img_y);
	game->textures[3] = game->exit_colored;
	if (!(*game).exit_colored)
		fail_xpm(game, 3);
	(*game).player_left = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/player_left.xpm", &img_x, &img_y);
	game->textures[5] = game->player_left;
	if (!(*game).player_left)
		fail_xpm(game, 4);
	(*game).player_right = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/player_right.xpm", &img_x, &img_y);
	game->textures[5] = game->player_right;
	if (!(*game).player_right)
		fail_xpm(game, 5);
	(*game).collect = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/collectable.xpm", &img_x, &img_y);
	game->textures[6] = game->collect;
	if (!(*game).collect)
		fail_xpm(game, 6);
}

void	init_img(t_data *game)
{
	int	img_x;
	int	img_y;

	(*game).wall = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/64wall2.xpm", &img_x, &img_y);
	game->textures[0] = game->wall;
	if (!(*game).wall)
		fail_xpm(game, 0);
	(*game).floor = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/64floor.xpm", &img_x, &img_y);
	game->textures[1] = game->floor;
	if (!(*game).floor)
		fail_xpm(game, 1);
	(*game).exit_nc = mlx_xpm_file_to_image((*game).mlx, \
		"./textures/exit_nc.xpm", &img_x, &img_y);
	game->textures[2] = game->exit_nc;
	if (!(*game).exit_nc)
		fail_xpm(game, 2);
	init_img2ndpart(game);
}
