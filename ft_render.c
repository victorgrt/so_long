/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:12:06 by victor            #+#    #+#             */
/*   Updated: 2023/04/17 15:01:22 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	ft_sprite(void *mlx, char *path)
{
	t_textures	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		printf("Sprite NULL\t%s\n", path);
	return (sprite);
}

void	init_sprites(t_data *game)
{
	void	*mlx;

	mlx = game->mlx;
	game->wall = ft_sprite(mlx, WALL);
	game->player_left = ft_sprite(mlx, PLAYER_L);
	game->player_right = ft_sprite(mlx, PLAYER_R);
	game->exit = ft_sprite(mlx, EXIT);
	game->collect = ft_sprite(mlx, COLLECT);
	game->floor = ft_sprite(mlx, FLOOR);
}

void	ft_render_sprite(t_data *game, t_textures sprite, int y, int x)
{
	mlx_put_image_to_window (game->mlx, game->win, \
		sprite.xpm_ptr, 64 * x, 64 * y);
}

void	ft_chose_sprite(t_data *game, int y, int x)
{
	char	c;

	c = game->map[y][x];
	if (c == '1')
		ft_render_sprite(game, game->wall, y, x);
	else if (c == '0')
		ft_render_sprite(game, game->floor, y, x);
	else if (c == 'C')
		ft_render_sprite(game, game->collect, y, x);
	else if (c == 'E')
		ft_render_sprite(game, game->exit, y, x);
	else if (c == 'P')
		ft_render_sprite(game, game->player_right, y, x);
}

int	ft_render_map(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->row)
	{
		x = 0;
		while (x < game->col)
		{
			ft_chose_sprite(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
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