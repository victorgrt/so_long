/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:05:53 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/03 21:21:32 by victor           ###   ########.fr       */
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
			ft_printf("%c", tab[i][j]);
			j++;
		}
		i++;
	}
}

// int	main(int ac, char **av)
// {
// 	t_map	*map;
// 	// char	**tab;

// 	if (ac != 2)
// 	{
// 		printf("Probleme d'arguments");
// 		return (0);
// 	}
// 	if (verif_arg(av[1]) == 0)
// 	{
// 		printf("Extension de la map INVALIDE\n");
// 		return (0);
// 	}
// 	map = init_map(av[1]);
// 	ft_putmap_tab(map);
// 	// ft_print_tab(tab);
// 	return (0);
// }