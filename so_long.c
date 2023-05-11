/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:13:31 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 13:39:49 by vgoret           ###   ########.fr       */
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

void	render_img(t_data *game, char c, int x, int y)
{
	if (c == '1')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).wall, x, y);
	}
	if (c == '0')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).floor, x, y);
	}
	if (c == 'C')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).collect, x, y);
	}
	if (c == 'E')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_nc, x, y);
	}
	if (c == 'S')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_colored, x, y);
	}
	if (c == 'P')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_left, x, y);
	}
	if (c == 'R')
	{
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_right, x, y);
	}
	
}

void	init_img(t_data *game)
{
	int	img_x;
	int	img_y;

	(*game).wall = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/skull.xpm", &img_x, &img_y);
	(*game).floor = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/water.xpm", &img_x, &img_y);
	(*game).exit_nc = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_nc.xpm", &img_x, &img_y);
	(*game).exit_colored = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/exit_colored.xpm", &img_x, &img_y);
	(*game).player_left = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_left.xpm", &img_x, &img_y);
	(*game).player_right = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/player_right.xpm", &img_x, &img_y);
	(*game).collect = mlx_xpm_file_to_image((*game).mlx, 
		"./ressources/collect.xpm", &img_x, &img_y);
}

int	init_game(t_data *game, char *path1)
{


	game->path = path1;
	//col + row initialised
	game->map = create_game(game);
	game->width = game->col * 64;
	game->height = game->row * 64;
	init_objects(game);
	if (ft_check_objects(game) == 1)
	{
		free_tab(game->map);
		ft_print_error("Error\nCheck Assets of the map");
	}
	printf("c:%d\n", game->c);
	game->move = 0;
    game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width,
			game->height, "so_long");
	init_img(game);
	ft_generate_window(game);
	return (0);
}

void	ft_print_error(char *str)
{
	perror(str);
	exit(0);
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
	printf("%d\t%d\n", game->col, game->row);
	map_test = create_game(game);
	// i = 0;
	// old = ft_strlen(map_test[i]);
	// while (i < game->row)
	// {
	// 	if (old != ft_strlen(map_test[i]))
	// 	{
	// 		ft_print_error("Error\nMap pas RECT");
	// 	}
	// 	i++;
	// 	// free_tab(map_test);
	// 	// ft_print_error("Error\nMap pas rectangulaire");
	// }
	if (ft_check_map(game, map_test) == 1)
	{
		// free_tab(map_test);
		ft_print_error("Error\nCheck map!");
	}
	// free_tab(map_test);
	free_tab(map_test);
	close(fd);
	/*Floading*/
	
	/*Free mon double tableau*/
}

int	main(int ac, char **av)
{
	t_data	game;

	/*Paring*/
	parsing(ac, av, &game);
	// if (ac != 2)
	// {
	// 	printf("Check Arguments\n");
	// 	return (0);
	// }
	// if (verif_arg(av[1]) == 1)
	// {
	// 	printf("Error\nExtension de la map invalide ou dossier source manquant\n");
	// 	return (0);
	// }
	/*Initialisation*/
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