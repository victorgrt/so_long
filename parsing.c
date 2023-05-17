/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:29:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/17 16:43:08 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_arg(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

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

int	ft_check_map(t_data *game, char **map)
{
	if (map[0] == NULL)
		return (1);
	if (is_map_closed(game, map) == 1)
	{
		free_tab(map);
		return (1);
	}
	if (is_map_rules(game, map) == 1)
	{
		free_tab(map);
		return (1);
	}
	return (0);
}

void	parsing(int ac, char **av, t_data *game)
{
	char	**map_test;
	int		fd;

	if (ac != 2)
		ft_print_error("Error\nTrop d'arguments");
	if (verif_arg(av[1]) == 1)
		ft_print_error("Error\nFailed to open the map");
	game->path = av[1];
	fd = open(av[1], O_RDONLY);
	get_map_info(game, fd);
	map_test = create_game(game);
	if (ft_check_map(game, map_test) == 1)
		ft_print_error("Error\nCheck map");
	free_tab(map_test);
	close(fd);
}
