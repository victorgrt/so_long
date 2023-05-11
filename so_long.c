/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 14:58:29 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define RED 0xFF0000
#define BLUE 0x0000FF

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
	if (line == NULL)
	{
		free(map);
		return (NULL);
	}
	while (line && i < rows)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	map[i] = '\0';
	// free_tab(map);
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



char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen2(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	if (dup[i - 1] == '\n')
	{
		dup[i - 1] = '\0';
		return (dup);
	}
	dup[i] = '\0';
	return (dup);
}


void	parsing(int ac, char **av, t_data *game)
{
	char	**map_test;
	int		fd;
	// int		i;
	// int		old;

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
		ft_print_error("Error\nCheck map!");
	}
	free_tab(map_test);
	close(fd);
	/*Floading*/
	
	/*Free mon double tableau*/
}

int	main(int ac, char **av)
{
	t_data	game;

	parsing(ac, av, &game);
	if (init_game(&game, av[1]) == 1)
		return (0);
	

	mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)close_window, &game);
	// mlx_string_put(game.mlx, game.win, 10, game.height - 10, RED, "MOVE :");
	// mlx_string_put(game.mlx, game.win, 100, game.height - 10, BLUE, ft_itoa(game.move));
	mlx_loop(game.mlx);
	return (0);
}

/*	PLAN


*/