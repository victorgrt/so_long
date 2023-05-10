/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:39:11 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/02 13:39:30 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_copy_mapdata(t_game *game, char *onelign)
{
	char		**c_mapdata;
	char		*c_onelign;

	c_onelign = malloc(ft_strlen(onelign) + 1);
	ft_strlcpy(c_onelign, onelign, ft_strlen(onelign) + 1);
	c_mapdata = ft_split(c_onelign, '\n');
	map->c_data = c_mapdata;
	free(c_onelign);
}