/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/04/17 15:05:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_data **game, int direction)
{
	int	img_h;
	int	img_w;

	if (direction == 1)
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/player_left.xpm", &img_w, &img_h);
	else
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/player_right.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
		(*game)->player_x * 64, (*game)->player_y * 64);
}

void	move(t_data **game, char c)
{
	int	img_w;
	int	img_h;

	(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
			"./ressources/water.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
		(*game)->player_x * 64, (*game)->player_y * 64);
	if (c == 'u')
		(*game)->player_y--;
	else if (c == 'd')
		(*game)->player_y++;
	else if (c == 'l')
		(*game)->player_x--;
	else if (c == 'r')
		(*game)->player_x++;
	else
		return ;
	(*game)->move++;
	render_player(game, 1);
}
