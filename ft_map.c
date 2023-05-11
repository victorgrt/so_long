/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:26:21 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/11 14:12:32 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	nb_line(char *path)
{
	int		fd;
	int		i;
	char	*temp;

	fd = open(path, O_RDONLY);
	i = 0;
	temp = get_next_line(fd);
	while (temp)
	{
		temp = get_next_line(fd);
		free(temp);
		i++;
	}
	close(fd);
	return (i);
}

int	get_size(char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
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
