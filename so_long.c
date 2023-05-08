/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/08 18:35:35 by victor           ###   ########.fr       */
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

void	ft_close_free(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
}

int	init_game(t_data *game, char *path1)
{

	game->fd = open(path1, O_RDONLY);
	game->path = path1;
	get_map_info(game, game->fd); //col + row initialised
	create_game2(game);
	if (game->map == NULL)
	{
		printf("Error\nMap pas rectangulaire\n");
		return (1);
	}
	if (ft_check_map(game) == 1)
	{
		printf("Error\nMap not closed\n");
		return (1);
	}
	game->width = game->col * 64;
	game->height = game->row * 64;
	init_objects(game);
	if (ft_check_objects(game) == 1)
	{
		printf("Error\nCheck Assets of the map please\n");
		return (1);
	}
	printf("c:%d\n", game->c);
	game->move = 0;
    // game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, game->width,
	// 		game->height, "so_long");
	// ft_generate_window(game);
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
		printf("Error\nExtension de la map invalide ou map pas trouvée dans ./src\n");
		return (0);
	}
	if (parsing(av[1], &game) == 1)
	{
		printf("Erreur de parsing\n");
		return (0);
	}
	generate_window(&game);
	mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)close_window, &game);
	// mlx_string_put(game.mlx, game.win, 10, game.height - 10, RED, "MOVE :");
	// mlx_string_put(game.mlx, game.win, 100, game.height - 10, BLUE, ft_itoa(game.move));
	mlx_loop(game.mlx);
	return (0);
}

// /*	PLAN


// */