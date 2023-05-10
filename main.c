/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/10 17:30:31 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define RED 0xFF0000

void	ft_generate_window(t_data *game)
{
	int	x;
	int	y;
	int	x_map;
	int	y_map;

	x_map = 0;
	x = 0;
	while (x < game->col)
	{
		y_map = 0;
		y = 0;
		while (y < game->row)
		{
			render_img(game, game->map[y][x], x_map, y_map);
			// put_image(game->map[y][x], x_map, y_map, &game);
			y++;
			y_map += 64;
		}
		x++;
		x_map += 64;
	}
}

void	free_tab(char **tableau)
{
	int	i;
	
	if (tableau == NULL || *tableau == NULL)
		return ;
	i = 0;
	while (tableau[i] != NULL)
	{
		free(tableau[i]);
		i++;
	}
	free(tableau);
}

int	close_window(t_data *game)
{
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit_colored);
	mlx_destroy_image(game->mlx, game->exit_nc);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->wall);
	mlx_loop_end(game->mlx);

	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);

	// free(game->win);
	free_tab(game->map);
	exit(0);
}

// int	main(int ac, char **av)
// {
// 	t_data	game;
// 	char	*path;
// 	int		fd;

// 	if (ac != 2)
// 	{
// 		printf("Error\nNo Map for so_long\n ");
// 		return (0);
// 	}
// 	if (verif_arg(av[1]) == 1)
// 	{
// 		printf("Error\nExtension de la map INVALIDE\n");
// 		return (0);
// 	}
//     path = map_path(av[1]);
// 	printf("al : %d\n", nb_line(path));
// 	fd = open(path, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("map not found in the folder ./maps\n");
// 		return (free(path), 0);
// 	}
// 		init_structure(&game);
// 	if (parsing(&game, av[1], fd) == 1)
// 	{
// 		printf("erreur de parsing\n");
// 		return (0);
// 	}

// 	// ft_generate_window(&game);
// 	// mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
// 	// mlx_hook(game.win, 17, 0L, (void *)close_window, &game);

// 	// mlx_loop(game.mlx);
// 	return (0);
// }
