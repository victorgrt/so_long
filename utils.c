/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:20:14 by victor            #+#    #+#             */
/*   Updated: 2023/03/28 21:51:43 by victor           ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen2(s);
	dup = malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		// if (dup[i] == '\n')
		// 	dup[i] = '\0';
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
