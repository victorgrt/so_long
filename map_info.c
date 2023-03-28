/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/03/28 18:32:03 by victor           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_map	*map;
    int     fd;
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
    fd = open(map_path(av[1]), O_RDONLY);
	map = init_map(av[1], fd);
    

    printf("%d\n%d\n", map->row, map->col);
	tab = map_tab(map, fd);
    printf("valid ? %d\n", is_map_valid(map, tab));
    close(fd);
    // ft_putmap_tab(map);
	// ft_print_tab(tab);
	return (0);
}