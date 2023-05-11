/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 19:19:40 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 14:45:29 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	init_img(t_data *game)
{
	int	img_x;
	int	img_y;

	(*game).wall = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/skull.xpm", &img_x, &img_y);
	if (!(*game).wall)
		return (1);
	(*game).floor = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/water.xpm", &img_x, &img_y);
	if (!(*game).floor)
		return (1);
	(*game).exit_nc = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_nc.xpm", &img_x, &img_y);
	if (!(*game).exit_nc)
		return (1);
	(*game).exit_colored = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_colored.xpm", &img_x, &img_y);
	if (!(*game).exit_colored)
		return (1);
	(*game).player_left = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_left.xpm", &img_x, &img_y);
	if (!(*game).player_left)
		return (1);
	(*game).player_right = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_right.xpm", &img_x, &img_y);
	if (!(*game).player_right)
		return (1);
	(*game).collect = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/collect.xpm", &img_x, &img_y);
	if (!(*game).collect)
		return (1);
	return (0);
}
