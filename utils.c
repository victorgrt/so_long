/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:20:14 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 17:26:05 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen2(s);
	dup = malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	if (dup[i - 1] == '\n')
	{
		dup[i - 1] = '\0';
		return (dup);
	}
	dup[i] = '\0';
	return (dup);
}
