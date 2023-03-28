/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/03/28 22:13:09 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_map_info(t_map *map, int fd)
{
    char    *line;
    
    //initialiser pos a 0 dans autre fonction?
    map->row = 0;
    map->col = 0; /*Pour savoir qu'on doit la modifier*/
    line = get_next_line(fd);
    while (line)
    {
        if (map->col == 0)
            map->col = ft_strlen(line);
        map->row++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
}

// int is_map_closed(t_map *map, char **tab)
// {
//     int i = 0;
//     // int rows = 0;
//     // int cols = 0;

//     while (i < map->col)
//     {
//         if (tab[0][i] ==)
//     }
//     return (0);
// }

// int is_map_valid(t_map *map, char **tab)
// {

//     if (is_map_closed(map, tab) == 1)
//         return (1);
//     // else if (is_map_rect(map, tab) == 1)
//     //     return (1);
//     // else if (is_map_doable(map, tab) == 1)
//     //     return (1);
//     // else if (is_map_rect(map, tab) == 1)
//     //     return (1);
    
    
//     return (0);

//     // while (i < map->col)
//     // {
//     //     if (tab[0][i] != '1' || tab[map->row - 1][i] != '1')
//     //         return (0);
//     //     i++;
//     // }
//     // i = 0;
//     // while (i < map->row)
//     // {
//     //     if (tab[i][0] != '1' || tab[i][map->col - 1] != '1')
//     //         return (0);
//     //     i++;
//     // }
//     // return (1);
// }

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
		if (ft_strlen(line) != cols && i < rows - 1) //attention a derniere ligne un peu moins grande
			return (NULL);
		map[i] = ft_strdup(line);
        // printf("map[%d]:%s\n", i, map[i]);
        // printf("%smap[%d][%d]:%d\t", map[i], i, cols, map[i][cols-1]);
		free(line);
		line = get_next_line(fd);
        i++;
	}
	free(line);
	if (i != rows)
		return (NULL);
    map[i] = '\0';
	return (map);
}


int	main(int ac, char **av)
{
	t_map	*map;
    int     fd;
	char	**map_data;
    char    *path;
    int i = 0;

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
    printf("path:%s\n", path);
    fd = open(path, O_RDONLY);
    printf("fd:%d\n", fd);
    map = init_map(av[1], fd);
    printf("row:%d\n", map->row);
    printf("col:%d\n", map->col);
    map_data = read_map(map);
    if (!map_data)
        printf("error");
    while (i < map->row)
    {
        printf("%s\t%d\n", map_data[i], ft_strlen(map_data[i]));
        i++;
        // return (0);
    }
    // printf("%s\n", map_data[0]);

    // printf("%d\n", is_map_valid(map, map_data));
	return (0);
}