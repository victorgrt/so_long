/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:53 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/17 14:57:25 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_printf("%c", tab[i][j]);
			j++;
		}
		i++;
	}
}

void	flood_map(t_data *game, int row, int column)
{
	char		**mapdata;
	int			i;
	int			j;

	i = row;
	j = column;
	mapdata = game->map;
	if (i > game->row - 1 || j > game->col - 1 || j < 0 || i < 0)
		return ;
	if (mapdata[i][j] == '1' || mapdata[i][j] == '2')
		return ;
	if (mapdata[i][j] == 'C')
		game->collected += 1;
	mapdata[i][j] = '2';
	flood_map(game, i + 1, j);
	flood_map(game, i, j + 1);
	flood_map(game, i - 1, j);
	flood_map(game, i, j - 1);
}

void	get_position_exit(char **map, t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				game->exit_y = j;
				game->exit_x = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_working_map(t_data *data)
{
	int	i;
	int	j;
	int	collected;

	i = data->player_y;
	j = data->player_x;
	flood_map(data, i, j);
	collected = data->collected;
	printf("%d\t%d\n", collected, data->max_c);
	if (collected != data->max_c)
	{
		printf("Cant be done\n");
		return (1);
	}
	printf("exit[%d][%d]\n", data->exit_x, data->exit_y);
	if (data->map[data->exit_y - 1][data->exit_x] == '1' && \
		data->map[data->exit_y + 1][data->exit_x] == '1'
		&& data->map[data->exit_y][data->exit_x - 1] == '1' && \
		data->map[data->exit_y][data->exit_x + 1] == '1')
	{
		printf("The exit is surrounded by walls.\n");
		return (1);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;
// 	// char	**tab;

// 	if (ac != 2)
// 	{
// 		printf("Probleme d'arguments");
// 		return (0);
// 	}
// 	if (verif_arg(av[1]) == 0)
// 	{
// 		printf("Extension de la map INVALIDE\n");
// 		return (0);
// 	}
// 	map = init_map(av[1]);
// 	ft_putmap_tab(map);
// 	// ft_print_tab(tab);
// 	return (0);
// }