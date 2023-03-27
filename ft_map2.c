/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:04:00 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/27 17:56:12 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
1111111111111	S'assurer qu'on est entre des murs
1000000C00001	1 sortie, <=1 item, 1 position de depart
1P0011E000001
1111111111111
*/

int	ft_check_compo(char	**tab, t_map *map)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	i = 0;
	j = 0;
	p = 0;
	e = 0;
	c = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (tab[i][j] == 'p')
				p++;
			else if (tab[i][j] == 'e')
				e++;
			else if (tab[i][j] == 's')
				c++;
			j++;
		}
		i++;
	}
	if (e != 1)
	{
		printf("Probleme E");
		return (1);
	}
	else if (c < 1)
	{
		printf("Pas assez de C");
		return (1);
	}
	else if (p != 1)
	{
		printf("Probleme P");
		return (1);
	}
	return (0);
}

int	ft_check_rectangle(t_map *map)
{
	int		size;
	int		size2;
	int		fd;
	char	*line;
	// char	*first;
	
	fd = open(map->path, O_RDONLY);
	line = get_next_line(fd);
	// first = line;
	printf("line1=%s", line);
	size2 = ft_strlen(line);
	printf("len1=%d\n", size2);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			size = ft_strlen(line);
			printf("%s\n", line);
			printf("size .. %d\n", size);
			if (size != size2)
			{
				printf("Pas RECT");
				return (1);
			}
		}
		// if (line)
		// {
		// 	printf("strlen=%d\n", ft_strlen(line));
		// 	printf("%s\n", line);		
		// }
		free(line);
	}
	// size = ft_stl
	printf("Map rectangulaire\n");
	return (0);
}

// int	map_check(char **tab)
// {
// 	int	i;

// 	i = 0;
// 	ft_check_rectangle(tab);
// }

char	**map_tab(char *path, t_map *map)
{
	// int	row;
	// int	col;
	int fd;
	int i;
	char	*line;
	char	**tab;

	tab = malloc(sizeof(char) * (map->height + map->width));
	if (!tab)
		return (NULL);
	// row = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab[i] = line;
		i++;
		line = get_next_line(fd);
		// free(line);
	}
	// while (line[i] != '\0')
	// {
	// 	tab[0][i] = line[i];
	// 	i++;	
	// }d
	printf("%d\n", map->height);
	printf("%d\n", map->width);
	printf("%s", tab[0]);
	printf("%s", tab[1]);
	printf("%s", tab[2]);
	printf("%s", tab[3]);
	printf("%s", tab[4]);
	printf("%s", tab[5]);
	printf("%s", tab[6]);
	
	// printf("%d", tab[0][1]);
	// while ()
	return (NULL);
}

int	main(int ac, char **av)
{
	t_map	*map;
	char	**tab;

	if (ac != 2)
	{
		printf("Probleme d'arguments");
		return (0);
	}
	if (verif_arg(av[1]) == 0)
	{
		printf("Extension de la map INVALIDE\n");
		return (0);
	}
	map = init_map(av[1]);
	tab = map_tab(map->path, map);
	// ft_check_rectangle(map);
	ft_check_compo(tab, map);
	return (0);
}