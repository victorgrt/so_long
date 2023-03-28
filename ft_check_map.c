/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:53 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/28 15:30:09 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_tab(char **tab)
{
	int	i;
	int	j;
	

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			printf("%c", tab[i][j]);
			j++;
		}
		i++;
	}
}

// int	ft_print_tab(char **tab)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (tab[i] != NULL)
// 	{
// 		j = 0;
// 		while (tab[i][j] != '\0')
// 		{
// 			printf("%d", tab[i][j]);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

char	**ft_putmap_tab(t_map *map)
{
	char	**tab;
	char	*line;
	int		fd;
	int		i;
	int		j;

	tab = malloc(sizeof(char) * (map->height * map->width));
	if (!tab)
		return (0);
	fd = open(map->path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (line[j])
	{
		tab[i][j] = line[j];
		j++; 
	}
	while (line)
	{
		j = 0;
		line = get_next_line(fd);
		while (line[j])
		{
			tab[i][j] = line[j];
			j++;
		}
		free(line);
	}
	// printf("%s\n", tab[0]);
	// printf("%s\n", tab[1]);
	// printf("%s\n", tab[2]);
	// printf("%s\n", tab[3]);
	// printf("%s\n", tab[4]);
	// printf("%s\n", tab[5]);
	return (tab);

}

int	main(int ac, char **av)
{
	t_map	*map;
	// char	**tab;

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
	ft_putmap_tab(map);
	// ft_print_tab(tab);
	return (0);
}