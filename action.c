/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:53:36 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/10 17:36:43 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_data **game, char c)
{
	// int	img_w;
	// int	img_h;

	render_img((*game), '0', (*game)->player_x * 64, (*game)->player_y * 64);
	if (c == 'u')
	{
		(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
		(*game)->player_y -= 1;

		print_move((*game), (*game)->move, c);
		render_img((*game), 'P', (*game)->player_x * 64, (*game)->player_y * 64);
	}
	if (c == 'd')
	{
				(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
		(*game)->player_y += 1;

		print_move((*game), (*game)->move, c);
		render_img((*game), 'R', (*game)->player_x * 64, (*game)->player_y * 64);
	}
	if (c == 'r')
	{
				(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
		(*game)->player_x += 1;

		print_move((*game), (*game)->move, c);
		render_img((*game), 'R', (*game)->player_x * 64, (*game)->player_y * 64);
	}
	if (c == 'l')
	{
				(*game)->map[(*game)->player_y][(*game)->player_x] = '0';
		(*game)->player_x -= 1;

		print_move((*game), (*game)->move, c);
		render_img((*game), 'P', (*game)->player_x * 64, (*game)->player_y * 64);
	}
	(*game)->move++;
	(*game)->c++;
	ft_printf("\033[0;32mCollected : %d/%d\n\033[0m", (*game)->c, (*game)->max_c);
	if ((*game)->c == (*game)->max_c)
		render_img((*game), 'S', (*game)->exit_x * 64, (*game)->exit_y * 64);
	return ;
}

void	ft_exit(t_data *game)
{
	int	img_w;
	int	img_h;

	if (game->c == game->max_c)
	{
		// render_img(game, 'P', game->player_x * 64, game->player_y * 64);
		game->img = mlx_xpm_file_to_image(game->mlx,
				"./ressources/player_left.xpm", &img_w, &img_h);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 
			game->player_x * 64, game->player_y * 64);
		print_win(game);
		close_window(game);
		exit(0);
	}
	else
		ft_printf("\033[0;31m T'as collecté que %d pièces sur %d. \
		Retourne au travail !\n\033[0m", game->c, game->max_c);
}
