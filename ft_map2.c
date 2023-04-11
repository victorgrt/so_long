/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:04:00 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/11 15:05:51 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_size(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		i++;
		// if (line[i] == '\n')
		// {
		// 	i--;
		// 	break ;
		// }
	}
	return (i);
}

// int	ft_check_rectangle(t_map *map)
// {
// 	int	size;
// 	int	size2;
// 	int	fd;
// 	int	i;
// 	char	*line;

// 	i = 0;
// 	fd = open(map->path, O_RDONLY);
// 	line = get_next_line(fd);
// 	i++;
// 	size = get_size(line);
// 	printf("size:%d\n", size);
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		i++;
// 		printf("line:%s\n", line);
// 		size2 = get_size(line);
// 		printf("size2:%d\n", size2);
// 		if (i == map->height)
// 			size2++;
// 		if (size != size2)
// 		{
// 			("Pas RECT");
// 			return (1);
// 		}
// 		free(line);
// 	}
// 	return (0);
// }

char	**map_tab(t_map *map, int fd)
{
	int i;
	char	*line;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * (map->row + 1));
	if (!tab)
		return (NULL);
	i = 0;
	line = get_next_line(fd);
	while (line && i < map->row)
	{
		if (ft_strlen(line) != map->col)
			return (NULL);
		tab[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	if (i != map->row)
		return (NULL);
	tab[i] = NULL;
	map->map = tab;
	return (tab);
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;
// 	// char	**tab;

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
// 	map = init_map(av[1]);
// 	// tab = map_tab(map->path, map);
// 	// ft_check_rect(tab, map);
// 	// printf("%d\n", tab[0][0]);
// 	// ft_check_rectangle(map);
// 	// ft_check_compo(tab, map);
// 	printf("p:%d\nc:%d\ne:%d\n", map->nb_p, map->nb_c, map->nb_e);
// 	return (0);
// }