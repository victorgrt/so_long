/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 14:09:40 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_data *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).wall, x, y);
	if (c == '0')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).floor, x, y);
	if (c == 'C')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).collect, x, y);
	if (c == 'E')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_nc, x, y);
	if (c == 'S')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_colored, x, y);
	if (c == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_left, x, y);
	if (c == 'R')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_right, x, y);
}

void	init_img(t_data *game)
{
	int	img_x;
	int	img_y;

	(*game).wall = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/skull.xpm", &img_x, &img_y);
	(*game).floor = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/water.xpm", &img_x, &img_y);
	(*game).exit_nc = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_nc.xpm", &img_x, &img_y);
	(*game).exit_colored = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_colored.xpm", &img_x, &img_y);
	(*game).player_left = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_left.xpm", &img_x, &img_y);
	(*game).player_right = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_right.xpm", &img_x, &img_y);
	(*game).collect = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/collect.xpm", &img_x, &img_y);
}
