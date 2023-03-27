/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:29:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/27 15:56:16 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	verif_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r' && str[i + 4] == '\0')
			return (1);
		return (0);
	}
	return (0);
}

char	*map_path(char *name)
{
	char	*path;
	int		i;
	int		fd;

	path = malloc(sizeof(char) * 5 + ft_strlen(name));
	path[0] = 'm';
	path[1] = 'a';
	path[2] = 'p';
	path[3] = 's';
	path[4] = '/';
	i = 0;
	while (name[i])
	{
		path[i + 5] = name[i];
		i++;
	}
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		printf(" 404 Path not found\n");
		return (NULL);
	}
	close(fd);
	return (path);
}

void	print_map(char *name)
{
	int	fd;
	char	*line;

	name = map_path(name);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break ;
	}
}

/*
Generee une map
*/
// int	mapinator(char *name)
// {
// 	// int	fd;
// 	s_map	*map;
	
	
// 	if (map_path(name) == NULL)
// 		return (1);
// 	name = map_path(name);
// 	map->height = map_len(name);
// 	printf("%d\n", map_len(name));
// 	// map->map_name = name;
// 	// printf("%s\n", map->map_name);
// 	return (0);
// 	// map->map = malloc(sizeof(char *) * map_len());
// 	// if (!(map->map))
// 	// 	return (NULL);
		
// }

// int	main(int ac, char **av)
// {
// 	// int	i;

	
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
// 	//gerener ma structure map avec la map dans un double tableau et le nom -> verif que le nom existe dans maps/
// 	// mapinator(av[1]);
// 	print_map(av[1]);
// 	//printf("%s\n", map_path(av[1]));
	
// 	//map->map_name = av[1];
// 	//printf("%d", map_len());	

// 	return (0);
// }