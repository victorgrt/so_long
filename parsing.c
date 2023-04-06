/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:29:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/07 00:02:51 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing(t_data *game, char *arg, int fd)
{
	t_map	*map;
	(void) fd;

	if (verif_arg(arg) == 1)
	{
		printf("Mauvais extension, fichier attendu : .ber\n");
		return (1);
	}
	map = init_map(arg);
	if (!map)
	{
		printf("Error\nMap non-conforme\n");
		return (1);
	}
	if (handle_map_error(game) == 1)
	{
		return (1);
	}
	//verifier si map rectangle
	//verifier si map faisable
	printf("%s\n%d\t%d\t%d\n%d\t%d\n", map->path, map->nb_c, map->nb_e, map->nb_p, map->col, map->row);
	printf("%d\t%d\t%d\t%d\n", game->c, game->e, game->p, game->max_c);
	return (0);
}

char	*map_path(char *name)
{
	char	*path;
	int		i;
	int		j;

	path = malloc(sizeof(char) * 6 + ft_strlen(name));
	if (!path)
		return (NULL);
	path[0] = 'm';
	path[1] = 'a';
	path[2] = 'p';
	path[3] = 's';
	path[4] = '/';

	i = 5;
	j = 0;
	while (name[j])
	{
		path[i] = name[j];
		i++;
		j++;
	}
	path[i] = '\0';
	return (path);
}

int	verif_arg(char *str)
{
	int	i;
	int	fd;
	char	*path;
	
	i = 0;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r' && str[i
			+ 4] == '\0')
		{
			path = map_path(str);
			fd = open(path, O_RDONLY);
			free(path);
			if (fd >= 0)
				return (0);
		}
		return (1);
	}
	return (1);
}

// Generee une map
//
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
// 	//gerener ma structure map avec la map dans un double tableau et le nom
		//-> verif que le nom existe dans maps/
// 	// mapinator(av[1]);
// 	print_map(av[1]);
// 	//printf("%s\n", map_path(av[1]));

// 	//map->map_name = av[1];
// 	//printf("%d", map_len());

// 	return (0);
// }

// int	main(int ac, char **av)
// {
// 	(void) ac;
// 	char	*temp;

// 	temp = map_path(av[1]);
// 	parsing(av[1], )
// 	printf("%s\n", temp);
// 	printf("%d\n", verif_arg(temp));
// 	return (1);
// }