/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/04/04 16:47:15 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printmap(t_data **game)
{
	int	i;

	i = 0;
	while ((*game)->map_struc->map[i])
	{
		ft_printf("%s\n", (*game)->map_struc->map[i]);
		i++;
	}
}

void	left(t_data **game)
{
	int	img_w;
	int	img_h;

	if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x
		- 1] != '1')
	{
		if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x
			- 1] == 'C')
		{
			ft_collect(game, 'l');
			return ;
		}
		else if ((*game)->map_struc->map[(*game)->player_y]
			[(*game)->player_x - 1] == 'E')
		{
			ft_exit(game);
			return ;
		}
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/tile64.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->player_x -= 1;
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->move++;
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n",
	// 		(*game)->map_struc->map[(*game)->player_y][(*game)->player_x - 1]);
	// }
}

void	down(t_data **game)
{
	int	img_w;
	int	img_h;

	if ((*game)->map_struc->map[(*game)->player_y + 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map_struc->map[(*game)->player_y + 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'd');
			return ;
		}
		else if ((*game)->map_struc->map[(*game)->player_y
				+ 1][(*game)->player_x] == 'E')
		{
			ft_exit(game);
			return ;
		}
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/tile64.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->player_y += 1;
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->move++;
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n",
	// 		(*game)->map_struc->map[(*game)->player_y + 1][(*game)->player_x]);
	// }
}

void	up(t_data **game)
{
	int	img_w;
	int	img_h;

	if ((*game)->map_struc->map[(*game)->player_y - 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map_struc->map[(*game)->player_y - 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'u');
			return ;
		}
		else if ((*game)->map_struc->map[(*game)->player_y
				- 1][(*game)->player_x] == 'E')
		{
			ft_exit(game);
			return ;
		}
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/tile64.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->player_y -= 1;
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->move++;
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n", (*game)->map_struc
	// 		->map[(*game)->player_y - 1][(*game)->player_x]);
	// }
}

void	right(t_data **game)
{
	int	img_w;
	int	img_h;

	if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x
		+ 1] != '1')
	{
		if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x
			+ 1] == 'C')
		{
			ft_collect(game, 'r');
			ft_printf("Collectabless>>>>>>>>>> %d/%d\n", (*game)->c,
				(*game)->max_c);
			return ;
		}
		else if ((*game)->map_struc->map[(*game)->player_y]
			[(*game)->player_x + 1] == 'E')
		{
			ft_exit(game);
			return ;
		}
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/tile64.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->player_x += 1;
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
				"./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
			(*game)->player_x * 64, (*game)->player_y * 64);
		(*game)->move++;
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n", (*game)->map_struc
	// 		->map[(*game)->player_y][(*game)->player_x + 1]);
	// }
}
