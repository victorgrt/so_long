/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/05 11:58:24 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define RED 0xFF0000

void	draw_map(t_map *map, t_data *img, t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->row)
	{
		x = 0;
		while (x < map->col)
		{
			if (map->map[y][x] == 'P')
			{
				draw_player(game, img);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *game, t_data *img)
{
	if (game->player_x < 0 || game->player_x >= WINDOW_WIDTH
		|| game->player_y < 0 || game->player_y >= WINDOW_HEIGHT)
		return ;
	mlx_pixel_put(img->mlx, img->win, img->player_x, img->player_y, RED);
}

void	render_image(t_data **game, int x, int y, char *path)
{
	int	tryx;
	int	tryy;

	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, path, &tryx, &tryy);
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, x, y);
}

void	put_image(char c, int x, int y, t_data **game)
{
	if (c == '1')
	{
		render_image(game, x, y, "./ressources/wall64.xpm");
	}
	if (c == '0')
		render_image(game, x, y, "./ressources/tile64.xpm");
	if (c == 'C')
		render_image(game, x, y, "./ressources/collect.xpm");
	if (c == 'E')
		render_image(game, x, y, "./ressources/door.xpm");
	if (c == 'P')
		render_image(game, x, y, "./ressources/alien.xpm");
}

void	ft_generate_window(t_data *game)
{
	int	x;
	int	y;
	int	x_map;
	int	y_map;

	x_map = 0;
	x = 0;
	while (x < game->map_struc->col)
	{
		y_map = 0;
		y = 0;
		while (y < game->map_struc->row)
		{
			put_image(game->map_struc->map[y][x], x_map, y_map, &game);
			y++;
			y_map += 64;
		}
		x++;
		x_map += 64;
	}
}

int	close_window(t_data *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int ac, char **av)
{
	t_data	game;
	char	*path;
	int		fd;
    
	if (ac != 2)
	{
		printf("Error\nNo Map for so_long\n ");
		return (0);
	}
	if (verif_arg(av[1]) == 0)
	{
		printf("Error\nExtension de la map INVALIDE\n");
		return (0);
	}
    path = map_path(av[1]);
	fd = open(path, O_RDONLY);
	init_structure(&game, av[1], fd);
	ft_generate_window(&game);
	mlx_hook(game.win, 2, (1L << 0), key_hook, &game);
	mlx_hook(game.win, 17, 0L, (void *)close_window, &game);

	mlx_loop(game.mlx);
	return (0);
}
