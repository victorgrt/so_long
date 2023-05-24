/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:21 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/22 14:01:10 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_game2ndpart(char *line, int fd, char **map, int i)
{
	free(line);
	close(fd);
	map[i] = '\0';
}

char	**create_game(t_data *game)
{
	char	**map;
	char	*line;
	int		rows;
	int		i;
	int		fd;

	rows = game->row;
	map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!map)
		return (NULL);
	i = 0;
	fd = open(game->path, O_RDONLY);
	line = get_next_line(fd);
	while (line && i < rows)
	{
		map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	create_game2ndpart(line, fd, map, i);
	return (map);
}

int	ft_check_objects(t_data *game)
{
	if (game->max_c <= 0)
		return (1);
	if (game->p != 1)
		return (1);
	if (game->e != 1)
		return (1);
	return (0);
}
