/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:36:14 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/17 14:58:47 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"
#include <stdlib.h>

#define WIN_WIDTH 640
#define WIN_HEIGHT 480

#define PLAYER_SIZE 32

#define PLAYER_COLOR 0x00FF00

// int	handle_keypress(int keycode, s_player *player, 
// void *mlx_ptr, void *win_ptr)
// {
// 	if (keycode == 53) // touche "echap" pour quitter
// 		exit(0);
// 	else if (keycode == 123) // touche "gauche"
// 		player->pos_x -= 5;
// 	else if (keycode == 124) // touche "droite"
// 		player->pos_x += 5;
// 	else if (keycode == 125) // touche "bas"
// 		player->pos_y += 5;
// 	else if (keycode == 126) // touche "haut"
// 		player->pos_y -= 5;
// 	draw_player(player, mlx_ptr, win_ptr);
// 	mlx_clear_window(mlx_ptr, win_ptr);
// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	void		*mlx_ptr;
// 	void		*win_ptr;
// 	s_player	*player;
// 	t_map		*map;
// 	char		*path;
// 	int			fd;

// 	if (ac != 2)
// 	{
// 		printf("Error\nNo Map for so_long\n ");
// 		return (0);
// 	}
// 	if (verif_arg(av[1]) == 0)
// 	{
// 		printf("Error\nExtension de la map INVALIDE\n");
// 		return (0);
// 	}
// 	/*Init map*/
// 	path = map_path(av[1]);
// 	fd = open(path, O_RDONLY);
// 	map = init_map(av[1], fd);
// 	if (map == NULL)
// 	{
// 		printf("Error\nMap pas rectangle\n");
// 		return (0);
// 	}
// 	player = malloc(sizeof(s_player));
// 	if (!player)
// 	{
// 		printf("Erreur de malloc du player\n");
// 		return (0);
// 	}
// 	player->pos_x = 0;
// 	player->pos_y = 0;
// 	if (handle_map_error(map, player) == 1)
// 		return (1);
// 	ft_print_info(map, player, path, fd);
// 	mlx_ptr = mlx_init();
// 	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "mlx test");
// 	draw_player(player, mlx_ptr, win_ptr);
// 	mlx_hook(win_ptr, 2, 1L << 0, &handle_keypress, &player);
// 	mlx_loop(mlx_ptr);
// 	return (0);
// }
