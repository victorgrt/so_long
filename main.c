/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/29 19:31:19 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx_linux/mlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>


#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 720

#define BLUE 0x0000FF
#define RED 0xFF0000
#define	GREEN 0x00ff00
#define	BLACK 0x000000
#define WHITE 0xFFFFFF

#define MLX_ERROR 1

typedef struct s_data {
    void    *mlx_win;
    void    *mlx;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_data;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	ft_draw_window(t_data img, int height, int width, int color)
{
	int	offset;
	int	x;
	int	y;

	x = 0;
	y = 0;
	offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
	while (y < width)
    {
        x = 0;
        while(x < height)
        {
            offset = (y * img.line_length + x * (img.bits_per_pixel / 8));
            *(unsigned int *)(img.addr + offset) = color;
            x++;
        }
        y++;
    }
}

int main(void)
{
    // int     x;
    // int     y;
    t_data  img;

    img.mlx = mlx_init();
    img.mlx_win = mlx_new_window(img.mlx, WINDOW_HEIGHT, WINDOW_WIDTH, "so_long");
    img.img = mlx_new_image(img.mlx, 1920, 1080);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	ft_draw_window(img, WINDOW_HEIGHT, WINDOW_WIDTH, GREEN);
    mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    mlx_loop(img.mlx);
    return (0);
}
