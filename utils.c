/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:20:14 by victor            #+#    #+#             */
/*   Updated: 2023/05/10 14:45:34 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx_linux/mlx.h"

size_t	ft_strlen2(const char *str)
{
	size_t	i;

	if (!str)
		return (600);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

