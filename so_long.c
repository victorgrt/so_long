/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/14 15:36:12 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		// close(fd);
		// free_tab(map_test);
		ft_print_error("Error\nCheck map!");
	}
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
