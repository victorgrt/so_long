/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/04/17 14:37:31 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_info(t_data *game, int fd)
{
	char	*line;

	game->row = 0;
	game->col = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (game->col == 0)
			game->col = ft_strlen(line);
		game->row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	is_map_closed(t_data *game)
{
	int			i;
	int			j;
	int			size;
	char		**map;

	i = 0;
	j = 0;
	map = game->map;
	while (j < game->row)
	{
		size = ft_strlen(map[j]);
		i = 0;
		while (map[j] && i < game->row)
		{
			if (map[i][0] != 49)
				return (1);
			if (map[i][size - 1] != '1')
				return (1);
			i++;
		}
		j++;
	}
	i = 0;
	j = 0;
	while (j < game->row)
	{
		i = 0;
		while (map[j] && i < game->col - 1)
		{
			if (map[0][i] != 49)
				return (1);
			if (map[game->row - 1][i] != 49)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	is_map_rules(t_data *game)
{
	int			i;
	int			j;
	char		**tab;

	i = 0;
	tab = game->map;
	while (i < game->row - 1)
	{
		j = 0;
		while (j < game->col - 1)
		{
			if (tab[i][j] != 'C' && tab[i][j] != 'P'
				&& tab[i][j] != 'E' && tab[i][j] != '1'
				&& tab[i][j] != '0')
			{
				printf("Error\nUnknown character : %c ([%d][%d])\n", \
				tab[i][j], i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// void    flood_map(t_map map, int row, int column)
// {
//     char    **mapdata;
//     int        i;
//     int        j;

//     i = row;
//     j = column;
//     mapdata = map->c_data;
//     if (i > map->rows - 1  j > map->columns - 1  j < 0  i < 0)
//         return ;
//     if (mapdata[i][j] == '1'  mapdata[i][j] == '2')
//         return ;
//     if (mapdata[i][j] == 'C')
//             map->collected += 1;
//     mapdata[i][j] = '2';
//     flood_map(map, i + 1, j);
//     flood_map(map, i, j + 1);
//     flood_map(map, i - 1, j);
//     flood_map(map, i, j - 1);
// }

// void    ft_check_working_map(t_mapmap)
// {
//     int        i;
//     int        j;
//     int        collected;

//     ft_fill_player_position(map);
//     i = map->player_row;
//     j = map->player_column;
//     flood_map(map, i, j);
//     collected = map->collected;
//     if (collected != map->collectible)
//         ft_error("Error\nMap cannot be completed\n", map);
// }

int	handle_map_error(t_data *game)
{
	if (is_map_closed(game) == 1)
	{
		printf("Error\nMap not closed\n");
		return (1);
	}
	if (is_map_rules(game) == 1)
	{
		printf("Error\nCheck Assets of the map\n");
		return (1);
	}
	return (0);
}

/*int	main(int ac, char **av)
{
	t_map	*map;
    s_player    *player;
    int     fd;
	// char	**map_data;
    char    *path;
    // int i = 0;

	if (ac != 2)
	{
		printf("Error\nNo Map for so_long\n ");
		return (0);
	}
	if (verif_arg(av[1]) == 0)
	{
		printf("Error\nExtension de la map INVALIDE\n");
		return (0);
    }
    path = map_path(av[1]);
    printf("path:%s\n", path);
    fd = open(path, O_RDONLY);
    printf("fd:%d\n", fd);
    map = init_map(av[1], fd);
    player = malloc(sizeof(s_player));
    if (!player)
    {
        printf("erreur malloc");
        return (0);
    }
    player->pos_y = 0;
    player->pos_x = 0;
    if (map == NULL)
    {
        printf("Error\nMap pas rectangle\n");
        return (0);
    }
    if (map == NULL)
        return (0);
    printf("row:%d\n", map->row);
    printf("col:%d\n", map->col);
	if (handle_map_error(map, player) == 1)
		return (1);
    printf("map info/P:%d  E:%d  C:%d\n", map->nb_p, map->nb_e, map->nb_c);
    printf("player[%d][%d]\n", player->pos_x, player->pos_y);
	return (0);
}*/