/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/04/10 17:04:17 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_data** game, int direction)
{
	int	img_h;
	int	img_w;

	if (direction == 1)
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
			"./ressources/player_left.xpm", &img_w, &img_h);
	else
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
			"./ressources/player_right.xpm", &img_w, &img_h);	
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
		(*game)->player_x * 64, (*game)->player_y * 64);
}

void	move(t_data **game, char c)
{
	int	img_w;
	int	img_h;
	
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx,
			"./ressources/water.xpm", &img_w, &img_h);
	mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,
		(*game)->player_x * 64, (*game)->player_y * 64);
	if (c == 'u')
		(*game)->player_y--;
	else if (c == 'd')
		(*game)->player_y++;
	else if (c == 'l')
		(*game)->player_x--;
	else if (c == 'r')
		(*game)->player_x++;
	else
		return ;
	(*game)->move++;
	render_player(game, (c == 'u' || c == 'l') ? 1 : 2); /*Si la condition (c == 'u' || c == 'l') est vraie, la valeur renvoyée est 1.Sinon, la valeur renvoyée est 2.*/
}

void	printmap(t_data **game)
{
	int	i;

	i = 0;
	while ((*game)->map[i])
	{
		ft_printf("%s\n", (*game)->map[i]);
		i++;
	}
}

void	left(t_data **game)
{
	if ((*game)->map[(*game)->player_y][(*game)->player_x
		- 1] != '1')
	{
		if ((*game)->map[(*game)->player_y][(*game)->player_x
			- 1] == 'C')
		{
			ft_collect(game, 'l');
			return ;
		}
		else if ((*game)->map[(*game)->player_y]
			[(*game)->player_x - 1] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'l');
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n",
	// 		(*game)->map[(*game)->player_y][(*game)->player_x - 1]);
	// }
}

void	down(t_data **game)
{
	if ((*game)->map[(*game)->player_y + 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map[(*game)->player_y + 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'd');
			return ;
		}
		else if ((*game)->map[(*game)->player_y
				+ 1][(*game)->player_x] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'd');
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n",
	// 		(*game)->map[(*game)->player_y + 1][(*game)->player_x]);
	// }
}



void	up(t_data **game)
{

	if ((*game)->map[(*game)->player_y - 1]
		[(*game)->player_x] != '1')
	{
		if ((*game)->map[(*game)->player_y - 1]
			[(*game)->player_x] == 'C')
		{
			ft_collect(game, 'u');
			return ;
		}
		else if ((*game)->map[(*game)->player_y
				- 1][(*game)->player_x] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'u');
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n", (*game)->map_struc
	//map[(*game)->player_y - 1][(*game)->player_x]);
	// }
}

void	right(t_data **game)
{

	if ((*game)->map[(*game)->player_y][(*game)->player_x
		+ 1] != '1')
	{
		if ((*game)->map[(*game)->player_y][(*game)->player_x
			+ 1] == 'C')
		{
			ft_collect(game, 'r');
			return ;
		}
		else if ((*game)->map[(*game)->player_y]
			[(*game)->player_x + 1] == 'E')
		{
			ft_exit(*game);
			return ;
		}
		move(game, 'r');
	}
	// else
	// {
	// 	ft_printf("Erreur : next char = %d\n", (*game)->map_struc
	//map[(*game)->player_y][(*game)->player_x + 1]);
	// }
}
