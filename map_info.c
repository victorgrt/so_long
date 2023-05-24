/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:54:08 by victor            #+#    #+#             */
/*   Updated: 2023/05/22 14:00:33 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map_info(t_data *game, int fd)
{
	char	*line;

	game->row = 0;
	game->col = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (game->col == 0)
			game->col = ft_strlen(line);
		game->row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
}

int	is_map_closed2ndpart(t_data *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->row)
	{
		i = 0;
		while (map[j] && i < game->col - 1)
		{
			if (map[0][i] != 49)
				return (1);
			if (map[game->row - 1][i] != 49)
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	is_map_closed(t_data *game, char **map)
{
	int			i;
	int			j;
	int			size;

	i = 0;
	j = 0;
	while (j < game->row)
	{
		size = ft_strlen(map[j]);
		i = 0;
		while (map[j] && i < game->row)
		{
			if (map[i][0] != 49)
				return (1);
			if (map[i][size - 1] != '1')
				return (1);
			i++;
		}
		j++;
	}
	if (is_map_closed2ndpart(game, map) == 1)
		return (1);
	return (0);
}

int	is_map_rules(t_data *game, char **tab)
{
	int			i;
	int			j;

	i = 0;
	while (i < game->row - 1)
	{
		j = 0;
		while (j < game->col - 1)
		{
			if (tab[i][j] != 'C' && tab[i][j] != 'P'
				&& tab[i][j] != 'E' && tab[i][j] != '1'
				&& tab[i][j] != '0')
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	handle_map_error(t_data *game, char **map)
{
	if (is_map_closed(game, map) == 1)
	{
		ft_printf("Error\nMap not closed\n");
		return (1);
	}
	if (is_map_rules(game, map) == 1)
	{
		ft_printf("Error\nCheck Assets of the map\n");
		return (1);
	}
	return (0);
}
