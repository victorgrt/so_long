/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:12:06 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 14:40:11 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_img(t_data *game, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).wall, x, y);
	if (c == '0')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).floor, x, y);
	if (c == 'C')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).collect, x, y);
	if (c == 'E')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_nc, x, y);
	if (c == 'S')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).exit_colored, x, y);
	if (c == 'P')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_left, x, y);
	if (c == 'R')
		mlx_put_image_to_window((*game).mlx, (*game).win, (*game).player_right, x, y);
}

void	render_player(t_data **game, int direction, char c)
{
	if (direction == 1)
		render_img((*game), c, (*game)->player_x * 64, (*game)->player_y * 64);
	else
		render_img((*game), c, (*game)->player_x * 64, (*game)->player_y * 64);
}

/*int	main(int ac, char **av)
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
	if (init_game(&game, map_path(av[1])) == 1)
		return (0);
	init_sprites(&game);
	ft_render_map(&game);
	// mlx_hook(game.win, 17, 0L, (void *)close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}*/