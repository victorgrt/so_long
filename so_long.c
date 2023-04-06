/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/07 00:04:39 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**create_game(t_data *game)
{
	char	**map;
	char	*line;
	int		rows;
	int		cols;
	int		i;
	int		fd;
	int		j;
	int		old;

	rows = game->row;
	cols = game->col;
	fd = open(game->path, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line && i < rows)
	{
		if (ft_strlen(line) != cols && i < rows - 1)
			return (NULL);
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if (i != rows)
		return (NULL);
	map[i] = '\0';
	j = 0;
	old = ft_strlen(map[0]);
	while (j < game->row)
	{
		if (ft_strlen(map[j]) != old)
			return (NULL);
		j++;
	}
	return (map);
}

int	ft_check_map(t_data *game)
{
	if (is_map_closed(game) == 1)
		return (1);
	if (is_map_rules(game) == 1)
		return (1);
	return (0);
}

int	ft_check_objects(t_data *game)
{
	if (game->max_c <= 0)
		return (1);
	if (game->p != 1)
		return (1);
	if (game->e != 1)
		return (1);
	return (0);
}

int	init_game(t_data *game, char *path1)
{

	game->fd = open(path1, O_RDONLY);
	game->path = path1;
	get_map_info(game, game->fd); //col + row initialised

	game->map = create_game(game);
	if (ft_check_map(game) == 1)
	{
		printf("Error\nMap not closed\n");
		return (1);
	}
	// printf("%d\n", ft_check_map(game));
	game->width = game->col * 144;
	game->height = game->row * 144;
	init_objects(game);
	if (ft_check_objects(game) == 1)
	{
		printf("Error\nCheck Assets of the map please\n");
		return (1);
	}
	// ft_check_objects(game);
	game->move = 0;


	
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->col * 144,
			game->row * 144, "so_long");

	print_map(game);
	
	return (0);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		printf("Check Arguments\n");
		return (0);
	}
	if (verif_arg(av[1]) == 1)
	{
		printf("Error\nExtension de la map INVALIDE ou map pas trouvee dans ./src\n");
		return (0);
	}
	if (init_game(&game, map_path(av[1])) == 1)
		return (0);

	ft_generate_window(&game);
	mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)close_window, &game);
	mlx_loop(game.mlx);

	return (0);
}

/*	PLAN


*/