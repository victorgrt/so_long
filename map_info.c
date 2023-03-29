/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/03/29 22:50:27 by victor           ###   ########.fr       */
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

int is_map_closed(t_map *map)
{
    int i;
    int j;

    // printf("\n");
    // col = map->col;
    i = 0;
    j = 0;
    while (j < map->row)
    {
        // printf("%s\t[%d]\tlen :%d\t\n", map->map[j], j, ft_strlen(map->map[j]));
        int size = ft_strlen(map->map[j]);
        i = 0;
        while (map->map[j] && i < map->row)
        {
            // printf("ici %d\n", map->map[map->row-1][i]);
            //droite et gauche done
            if (map->map[i][0] != 49)
            {
                // printf("ici : %d\ti : %d\tj :%d\n", map->map[j][i], i, j);
                return (1);
            }
            // printf("size:%d\t%d\n", size, map->map[j][size-1]);
            if (map->map[i][size - 1] != '1')
            {
                // printf("la : %d\ti : %d\tj :%d\n", map->map[j][i], i, size);
                return (1);
            }
            i++; 
        }
        j++;
    }
    i = 0;
    j = 0;
    while (j < map->col)
    {
        i = 0;
        while (map->map[j] && i < map->col - 1)
        {
            // printf("ici %d\n", map->map[map->row-1][i]);
            //droite et gauche done
            if (map->map[0][i] != 49)
            {
                // printf("ici : %d\ti : %d\tj :%d\n", map->map[j][i], i, j);
                return (1);
            }
            if (map->map[map->row-1][i] != 49)
            {
                // printf("ici : %d\ti : %d\tj :%d\n", map->map[j][i], i, j);
                return (1);
            }
            i++;
        }
        j++;
    }
    return (0);
}

int is_map_rules(t_map *map, s_player *player)
{
    int i;
    int j;

    i = 0;
    while (i < map->row - 1)
    {
        j = 0;
        while (j < map->col - 1)
        {
            // printf("%c\n", map->map[i][j]);
            if (map->map[i][j] == 'P')
            {
                player->pos_y = i;
                player->pos_x = j;
                map->nb_p += 1;
            }
            if (map->map[i][j] == 'C')
                map->nb_c++;
            if (map->map[i][j] == 'E')
                map->nb_e++;
            if (map->map[i][j] != 'C' && map->map[i][j] != 'P' && map->map[i][j] != 'E' && map->map[i][j] != '1' && map->map[i][j] != '0')
            { 
                printf("Error\nUnknown character : %c ([%d][%d])\n", map->map[i][j], i, j);
                return (1);
            }
            j++;
        }
        i++;
    }
	// printf("p%d\te%d\tc%d\n", map->nb_p, map->nb_e, map->nb_c);
    if (map->nb_p != 1)
        return (1);
    if (map->nb_e != 1)
        return (1);
    if (map->nb_c <= 0)
        return (1);
    return (0);
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
    int j = 0;
    // printf("%s\n", map[0]);
    int old = ft_strlen(map[0]);
    // printf("%d\n", old);
    while (j < mappppp->row)
    {
        // printf("%d\n", ft_strlen(map[j]));
        if (ft_strlen(map[j]) != old)
            return (NULL);
        j++;
    }
	return (map);
}

int handle_map_error(t_map *map, s_player *player)
{
    if (is_map_closed(map) == 1)
    {
        printf("Error\nMap not closed\n");
        return (1);
    }
    if (is_map_rules(map, player) == 1)
    {
        printf("Error\nCheck Assets of the map\n");
        return (1);
    }

    return (0);
}

int	main(int ac, char **av)
{
	t_map	*map;
    s_player    *player;
    int     fd;
	// char	**map_data;
    char    *path;
    // int i = 0;

	if (ac != 2)
	{
		printf("Error\nNo Map for so_long\n ");
		return (0);
	}
	if (verif_arg(av[1]) == 0)
	{
		printf("Error\nExtension de la map INVALIDE\n");
		return (0);
    }
    path = map_path(av[1]);
    printf("path:%s\n", path);
    fd = open(path, O_RDONLY);
    printf("fd:%d\n", fd);
    map = init_map(av[1], fd);
    player = malloc(sizeof(s_player));
    if (!player)
    {
        printf("erreur malloc");
        return (0);
    }
    player->pos_y = 0;
    player->pos_x = 0;
    if (map == NULL)
    {
        printf("Error\nMap pas rectangle\n");
        return (0);
    }
    if (map == NULL)
        return (0);
    printf("row:%d\n", map->row);
    printf("col:%d\n", map->col);
	if (handle_map_error(map, player) == 1)
		return (1);
    printf("map info/P:%d  E:%d  C:%d\n", map->nb_p, map->nb_e, map->nb_c);
    printf("player[%d][%d]\n", player->pos_x, player->pos_y);
	return (0);
}