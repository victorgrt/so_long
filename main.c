/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 14:35:50 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

#define RED 0xFF0000

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
