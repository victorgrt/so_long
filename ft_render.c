/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 23:12:06 by victor            #+#    #+#             */
/*   Updated: 2023/03/29 23:13:02 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
    void    *mlx_win;
    void    *mlx;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void	*put_image(t_data *image, int x, int y, int TILE_SIZE)
{
    x = x*TILE_SIZE;
    y = y*TILE_SIZE;
	image->img = mlx_xpm_file_to_image(image->mlx,
			"./ressources/collect.xpm", &y, &x);
	mlx_put_image_to_window(image->mlx, image->mlx_win, image->img, x, y);
	return (image->img);
}