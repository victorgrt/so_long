/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:21 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/06 17:20:56 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(char *name)
{
	t_map	*map;
	char	*path;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	path = map_path(name);
	if (path == NULL)
		return (NULL);
	map->path = path;
	map->nb_c = 0;
	map->nb_e = 0;
	map->nb_p = 0;
	// get_map_info(map, fd);
	// if (read_map(map, fd) == NULL)
	// 	return (NULL);
	// map->map = read_map(map, fd);
	// map->height = map_height(path);
	// map->width = map_width(path);
	// map->map = map_tab(map->path, map);
	// ft_map_init_nb(map, map->map);
	// map->map = map_tab(path);

	return (map);
}

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	nb_line(char *path)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(path, O_RDONLY);
	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	close(fd);
	return (i);
}

// char	**create_map(t_data *game)
// {
// 	int	fd;
// 	int	i;
// 	char	*temp;

// 	game->map = malloc(sizeof(*game) * nb_line(game->path) + 1);
// 	if (!game->map_struc->map)
// 		return (NULL);
// 	fd = open(game->map_struc->path, O_RDONLY);
// 	i = 0;
// 	while (i < nb_line(game->map_struc->path))
// 	{
// 		temp = ft_strdup(get_next_line(fd));
// 		game->map_struc->map[i] = temp;
// 		i++;
// 	}
// 	close(fd);
// 	return(game->map_struc->map);
// }

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 	{
// 		printf("Probleme d'arguments");
// 		return (0);
// 	}
// 	if (verif_arg(av[1]) == 0)
// 	{
// 		printf("Extension de la map INVALIDE\n");
// 		return (0);
// 	}
// 	init_map(av[1]);
// 	return (0);
// }