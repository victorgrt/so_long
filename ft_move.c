/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/05/11 14:05:26 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



void	move(t_data **game, char c)
{
	render_img((*game), '0', (*game)->player_x * 64, (*game)->player_y * 64);
	if (c == 'u')
		(*game)->player_y--;
	else if (c == 'd')
		(*game)->player_y++;
	else if (c == 'l')
		(*game)->player_x--;
	else if (c == 'r')
		(*game)->player_x++;
	else
		return ;
	(*game)->move++;
	if (c == 'r')
		render_player(game, 1, 'R');
	else	
		render_player(game, 2, 'P');
}
