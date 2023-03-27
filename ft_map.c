/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:21 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/27 16:19:42 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *name)
{
	int	i;
	int	fd;
	char	*line;
	
	i = 0;

	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		i++;
		free(line);
	}
	close(fd);
	return (i);
}

int	map_width(char *name)
{
	int	i;
	int	fd;
	char	*line;
	
	i = 0;
	fd = open(name, O_RDONLY);
	line = get_next_line(fd);
	i += ft_strlen(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line != NULL)
			i += ft_strlen(line) - 1;
		free(line);
	}
	close(fd);
	return (i);
}

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
	map->height = map_height(path);
	map->width = map_width(path);
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