/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:53:36 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/03 17:36:36 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_collect(t_data **game, char c)
{    
  int img_w;
  int img_h;
  
  (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/floor.xpm", &img_w, &img_h);
  mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
  (*game)->c++;
  if (c == 'u')
  {
	  (*game)->player_y -= 1;
    (*game)->map_struc->map[(*game)->player_y][(*game)->player_x] = '0';
  }
  if (c == 'd')
  {
		(*game)->player_y += 1;
    (*game)->map_struc->map[(*game)->player_y][(*game)->player_x] = '0';
  }
	if (c == 'r')
  {
		(*game)->player_x += 1;
    (*game)->map_struc->map[(*game)->player_y][(*game)->player_x] = '0';
  }
  if (c == 'l')
  {
    (*game)->player_x -= 1;
    (*game)->map_struc->map[(*game)->player_y][(*game)->player_x] = '0';
  }
  (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
  mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
  printf("Collected : %d\n", (*game)->c);
  return ;
}

void    ft_exit(t_data **game)
{
	int img_w;
	int img_h;

	if ((*game)->c == (*game)->max_c)
	{
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
		printf("BRAVOOOOOOOOOOOOOOOOOOOOOOOOO\nBRAVOOOOOOOOOOOOOOOOOOOOOOOOO\nBRAVOOOOOOOOOOOOOOOOOOOOOOOOO\n");
		exit (0);    
	}
	else
	{
		printf("Tu n'as pas recup tous les collectables\n");
	}
}
