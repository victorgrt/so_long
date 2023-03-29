/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:21 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/29 02:49:28 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *name, int fd)
{
	int	i;
	char	*line;
	
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
		free(line);
	}
	return (i);
}

int	map_width(char *name, int fd)
{
	int	i;
	char	*line;
	
	i = 0;
	line = get_next_line(fd);
	i += ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			i += ft_strlen(line) - 1;
		free(line);
	}
	return (i);
}

void	ft_map_init_nb(t_map *map, char **tab)
{
	int	i;
	int	j;

	i = 0;
	// printf("reso:height%d\nwidth%d\n", map->height, map->width);
	// printf("height:%d\nwidth:%d\n", map->height, map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (tab[i][j] == 'P')
				map->nb_p++;
			else if (tab[i][j] == 'E')
				map->nb_e++;
			else if (tab[i][j] == 'C')
				map->nb_c++;
			j++;
		}
		i++;
	}
}

t_map	*init_map(char *name, int fd)
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
	get_map_info(map, fd);
	if (read_map(map) == NULL)
	{
		printf("Pas carré");
		return (NULL);
	}
	map->map = read_map(map);
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