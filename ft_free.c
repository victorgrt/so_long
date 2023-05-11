/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:33:00 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 16:19:57 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *game)
{
	// mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit_colored);
	mlx_destroy_image(game->mlx, game->exit_nc);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->wall);

	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);

	free_tab(game->map);
	free(game->mlx);
	exit(0);
}

int	close_window2(t_data *game)
{
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit_colored);
	mlx_destroy_image(game->mlx, game->exit_nc);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->wall);

	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);

	free_tab(game->map);
	free(game->mlx);
	exit(0);
}

void	close_window3(t_data *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player_left);
	mlx_destroy_image(game->mlx, game->player_right);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit_colored);
	mlx_destroy_image(game->mlx, game->exit_nc);
	mlx_destroy_image(game->mlx, game->collect);


	// mlx_clear_window(game->mlx, game->win);
	// mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	mlx_loop_end(game->mlx);

	free_tab(game->map);
	free(game->mlx);
	ft_print_error("Error\nTextures introuvables");
}