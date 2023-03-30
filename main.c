/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/30 15:58:22 by vgoret           ###   ########.fr       */
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
#define EVENT_KEY_PRESS 2
#define EVENT_EXIT 17 //croix fermer
#define KEY_Q 12
#define KEY_ESC 53 

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
    else if (c == 'C') // collectable
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, GREEN, img);
    else if (c == 'E') // Exit
        ft_draw_rectangle(x * TILE_SIZE, y * TILE_SIZE,
            TILE_SIZE, TILE_SIZE, BLUE, img);
}

void	draw_map(t_map *map, t_data *img, s_player *player)
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
            if (map->map[y][x] == 'P')
            {
                player->pos_x = x;
                player->pos_y = y;
                draw_player(player, img->mlx, img->mlx_win, img);
            }
            x++;
        }
        y++;
    }
}

void	draw_player(s_player *player, void *mlx_ptr, void *win_ptr, t_data *img)
{
    if (player->pos_x < 0 || player->pos_x >= WINDOW_WIDTH || player->pos_y < 0 || player->pos_y >= WINDOW_HEIGHT)
        return;
    // printf("la[%d][%d]\n", player->pos_x, player->pos_y);
    mlx_pixel_put(mlx_ptr, win_ptr, img->player_x, img->player_y, RED);
}


int	handle_keypress(int keysym, t_data *img, s_player *player, t_map *map)
{
    // get_pos_player(map, player);

	if (keysym == XK_Escape || keysym == 113)
    {
		mlx_destroy_window(img->mlx, img->mlx_win);
        return (0);
    }
    if (keysym == XK_Left || keysym == XK_Right || keysym == XK_Up || keysym == XK_Down)
    {
        if (keysym == XK_Left)
        {   
            printf("before:[%d][%d]\n", img->player_x, img->player_y);
            img->player_x += -1;
            printf("after:[%d][%d]\n", img->player_x, img->player_y);
		}
		if (keysym == XK_Right)
        {   
            printf("before:[%d][%d]\n", img->player_x, img->player_y);
             img->player_x +=1;
            printf("after:[%d][%d]\n", img->player_x, img->player_y);
		}
		if (keysym == XK_Up)
        {   
            printf("before:[%d][%d]\n", img->player_x, img->player_y);
             img->player_y -=1;
            printf("after:[%d][%d]\n", img->player_x, img->player_y);
		}
		if (keysym == XK_Down)
        {   
            printf("before:[%d][%d]\n", img->player_x, img->player_y);
             img->player_y +=1;
            printf("after:[%d][%d]\n", img->player_x, img->player_y);
		}
        ft_draw_window(*img, WINDOW_HEIGHT, WINDOW_WIDTH, BLACK);
        draw_map(map, img, player);
        mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    }
    
	printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(int ac, char **av)
{
    (void) ac;
	t_map	*map;
	t_data	img;
    s_player    *player;
    int     height = 0;
    int     width = 0;
    char    *path;
    int     fd;
    
	// parsing de la map et initialisation de img et map
    if (ac != 2)
	{
		printf("Error\nNo Map for so_long\n ");
		return (0);
	}
	if (verif_arg(av[1]) == 0)
	{
		printf("Error\nExtension de la map INVALIDE\n");
		return (0);
    }

    /*Init map*/
    path = map_path(av[1]);
    fd = open(path, O_RDONLY);
    map = init_map(av[1], fd);
    if (map == NULL)
    {
        printf("Error\nMap pas rectangle\n");
        return (0);
    }
    player = malloc(sizeof(s_player));
    if (!player)
    {
        printf("Erreur de malloc du player\n");
        return (0);
    }
    if (handle_map_error(map, player) == 1)
		return (1);
    ft_print_info(map, path, fd, img);
    get_pos_player(map, player);
    
        //init mlx
	img.mlx = mlx_init();
    height = TILE_SIZE * map->row;
    width = TILE_SIZE * map->col;
    img.player_x = player->pos_x;
    img.player_y = player->pos_y;
	img.mlx_win = mlx_new_window(img.mlx, width, height, "so_long");
	img.img = mlx_new_image(img.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
            
	draw_map(map, &img, player);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
    
    // mlx_hook(img.mlx_win, EVENT_EXIT, 0, handle_exit, &img);
	mlx_hook(img.mlx_win, KeyPress, KeyPressMask, &handle_keypress, &img); /* ADDED */
	mlx_hook(img.mlx_win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &img); /* CHANGED */
	// mlx_clear_window(img.mlx, img.mlx_win);
    ft_print_info(map, path, fd, img);
    
    mlx_loop(img.mlx);
    mlx_destroy_display(img.mlx_win);
	free(img.mlx_win);
    printf("pos[%d][%d]\n", player->pos_x, player->pos_y);
	return (0);
}
