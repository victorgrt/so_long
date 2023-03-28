/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/03/28 19:27:19 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_map_info(t_map *map, int fd)
{
    char    *line;
    
    //initialiser pos a 0 dans autre fonction?
    map->row = 0;
    map->col = -1; /*Pour savoir qu'on doit la modifier*/
    line = get_next_line(fd);
    while (line)
    {
        if (map->col == -1)
            map->col = ft_strlen(line);
        map->row++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
}

int is_map_valid(t_map *map, char **tab)
{
    int i;
    // int start;
    // int sortie;

    i = 0;
    while (i < map->col)
    {
        if (tab[0][i] != '1' || tab[map->row - 1][i] != '1')
            return (0);
        i++;
    }
    i = 0;
    while (i < map->row)
    {
        if (tab[i][0] != '1' || tab[i][map->col - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

char	**read_map(t_map *mappppp)
{
	char	**map;
	char	*line;
    int     rows = mappppp->row;
    int     cols = mappppp->col;
	int		i;
    int     fd;
    char    *path;

    path = mappppp->path;
    fd = open(path, O_RDONLY);

	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
    line = get_next_line(fd);
	while (line && i < rows)
	{
		// if (ft_strlen(line) != cols)
			// return (NULL);

		map[i] = ft_strdup(line);
        
		free(line);
		        line = get_next_line(fd);
        i++;
	}
	free(line);
	// if (i != rows)
		// return (NULL);
	map[i] = '\0';
	return (map);
}


int	main(int ac, char **av)
{
	t_map	*map;
    int     fd;
	char	**map_data;
    char    *path;

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
    path = map_path(av[1]);
    fd = open(path, O_RDONLY);
    map = init_map(av[1], fd);

    map_data = read_map(map);
if (!map_data)
    printf("Failed to read map\n");
else if (!map_data[0])
    printf("First line of map is empty\n");
else
    printf("%s\n", map_data[0]);
    printf("%s\n", map_data[1]);
    printf("%s\n", map_data[2]);
    printf("%s\n", map_data[3]);
    printf("%s\n", map_data[4]);
    printf("%s\n", map_data[5]);
    // printf("%s\n", map_data[6]);
	return (0);
}