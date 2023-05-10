/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:15:23 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/02 12:18:45 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_map(t_game *game, int row, int col)
{
	char	**mapcpy;
	int	i;
	int	j;
	
	i = row;
    j = column;
	mapcpy = game->map;
    if (i > game->rows - 1 || j > game->columns - 1 || j < 0 || i < 0)
        return ;
    if (mapcpy[i][j] == '1'  mapcpy[i][j] == '2')
        return ;
    if (mapcpy[i][j] == 'C')
            map->collected += 1;
    mapcpy[i][j] = '2';
    flood_map(map, i + 1, j);
    flood_map(map, i, j + 1);
    flood_map(map, i - 1, j);
    flood_map(map, i, j - 1);
}


//Je flood autour du player pour check si il peut bouger