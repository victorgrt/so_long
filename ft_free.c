/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:33:00 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/03 12:41:13 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
}

// void	free_map(char **map)
// {
// 	int	i;

// 	i = 0; 
// }

/*Je dois free ma map
Destroy mes images 
Destroy ma fenetre
Free les pointeurs de la MLX
Free ma structure*/