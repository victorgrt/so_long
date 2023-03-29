/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/29 23:13:57 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx_linux/mlx.h"
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

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
    int offset;
    int x;
    int y;

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

#define TILE_SIZE 64 // Taille d'une tuile en pixels

void	ft_draw_rectangle(int x, int y, int width, int height, int color, t_data *img)
{
    int offset;
    int i;
    int j;

    j = 0;
    while (j < height)
    {
        i = 0;
        while (i < width)
        {
            offset = (y + j) * img->line_length + (x + i) * (img->bits_per_pixel / 8);
            *(unsigned int *)(img->addr + offset) = color;
            i++;
        }
        j++;
    }
}

void	draw_tile(int x, int y, char c, t_data *img)
{
    if (c == '1') // mur
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, WHITE, img);
    else if (c == '0') // sol
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, BLACK, img);
    else if (c == 'P') // joueur
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, RED, img);
    else if (c == 'C') // joueur
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, GREEN, img);
    else if (c == 'E') // joueur
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, BLUE, img);
    // ajouter d'autres conditions pour d'autres éléments de la carte
}

void	draw_map(t_map *map, t_data *img)
{
    int x;
    int y;

    y = 0;
    while (y < map->row)
    {
        x = 0;
        while (x < map->col)
        {
            draw_tile(x, y, map->map[y][x], img);
            x++;
        }
        y++;
    }
}

int	main(int ac, char **av)
{
    (void) ac;
	t_map	*map;
	t_data	img;
    char    *path;
    int     fd;

	// parsing de la map et initialisation de img et map

	img.mlx = mlx_init();
    path = map_path(av[1]);
    fd = open(path, O_RDONLY);
    map = init_map(av[1], fd);
	img.mlx_win = mlx_new_window(img.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
	img.img = mlx_new_image(img.mlx, map->col * TILE_SIZE, map->row * TILE_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	draw_map(map, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
	return (0);
}
