/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 17:25:59 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define RED 0xFF0000
#define BLUE 0x0000FF

void	create_game2ndpart(char *line, int fd, char **map, int i)
{
	free(line);
	close(fd);
	map[i] = '\0';
}

char	**create_game(t_data *game)
{
	char	**map;
	char	*line;
	int		rows;
	int		i;
	int		fd;

	rows = game->row;
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(game->path, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < rows)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	create_game2ndpart(line, fd, map, i);
	return (map);
}

int	ft_check_map(t_data *game, char **map)
{
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
		ft_print_error("Error\nCheck map!");
	free_tab(map_test);
	close(fd);
}

int	main(int ac, char **av)
{
	t_data	game;

	parsing(ac, av, &game);
	if (init_game(&game, av[1]) == 1)
		return (0);
	mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
