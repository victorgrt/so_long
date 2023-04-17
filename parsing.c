/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 13:29:59 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/11 15:54:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	// char	*path;
	
	i = 0;
	while (str[i])
	{
		while (str[i] != '.')
			i++;
		if (str[i + 1] == 'b' && str[i + 2] == 'e' && str[i + 3] == 'r' && str[i
			+ 4] == '\0')
		{
			if (str[0] != '.' && str[1] != '/' && str[2] != 'm' && str[3] != 'a' && str[4] != 'p'
				&& str[5] != 's' && str[6] != '/')
				str = map_path(str);
			fd = open(str, O_RDONLY);
			if (fd >= 0)
				return (0);
		}
		return (1);
	}
	return (1);
}
