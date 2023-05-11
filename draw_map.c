/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:12:29 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 14:34:08 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_generate_window(t_data *game)
{
	int	x;
	int	y;
	int	x_map;
	int	y_map;

	x_map = 0;
	x = 0;
	while (x < game->col)
	{
		y_map = 0;
		y = 0;
		while (y < game->row)
		{
			render_img(game, game->map[y][x], x_map, y_map);
			y++;
			y_map += 64;
		}
		x++;
		x_map += 64;
	}
}