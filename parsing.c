/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:29:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/21 01:30:38 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*map_path(char *name)
{
	char	*path;
	int		i;
	int		j;

	path = malloc(sizeof(char) * 6 + ft_strlen(name));
	if (!path)
		return (NULL);
	path[0] = 'm';
	path[1] = 'a';
	path[2] = 'p';
	path[3] = 's';
	path[4] = '/';
	i = 5;
	j = 0;
	while (name[j])
	{
		path[i] = name[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

int	verif_arg(char *str)
{
	int	i;
	int	fd;

	i = 0;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r' && str[i
				+ 4] == '\0')
		{
			if (str[0] != '.' && str[1] != '/' && str[2] != 'm'
				&& str[3] != 'a' && str[4] != 'p'
				&& str[5] != 's' && str[6] != '/')
				str = ft_strjoin2("./maps/", str);
			fd = open(str, O_RDONLY);
			free(str);
			if (fd >= 0)
				return (0);
		}
		return (1);
	}
	return (1);
}


int	create_game2(t_data *game)
{
	char	**tab;
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
	tab = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!tab)
		return (1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < rows)
	{
		if (ft_strlen(line) != cols && i < rows - 1)
			return (1);
		tab[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if (i != rows)
		return (1);
	tab[i] = '\0';
	j = 0;
	old = ft_strlen(tab[0]);
	while (j < game->row)
	{
		if (ft_strlen(tab[j]) != old)
			return (1);
		j++;
	}
	game->map = tab;
	return (0);
}

int	parsing(char *param, t_data *game)
{
	char	*temp;
	if (verif_arg(param) == 1)
	{
		printf("Error\nExtension de la map invalide ou map pas trouvée dans ./src\n");
		return (1);
	}
	temp = ft_strjoin2("./maps/", param);
	game->path = temp;
	if (init_game(game, game->path) == 1)
		return (1);
	// if (create_game2(game) == 1)
	// {
	// 	printf("Error\nProblème lors de la creation de la map\n");
	// 	return (1);
	// }
	// if (game->map == NULL)
	// {
	// 	printf("Error\nMap pas rectangulaire\n");
	// 	return (1);
	// }
	game->fd = open(game->path, O_RDONLY);
	free(temp);
	if (is_map_closed(game) == 1)
		return (free(temp), 1);
	if (is_map_rules(game) == 1)
		return (free(temp), 1);
	return (0);
}

void	generate_window(t_data *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	ft_generate_window(game);
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
	{
		printf("Check Arguments\n");
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
	// free(game.mlx);
	// free(game.img);
	// free(game.win);
	ft_free(game.map);
	return (0);
}