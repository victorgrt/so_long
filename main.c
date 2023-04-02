/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:36:29 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/02 17:06:06 by victor           ###   ########.fr       */
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

#define TILE_SIZE 32 // Taille d'une tuile en pixels

void	draw_map(t_map *map, t_data *img, t_data *game)
{
    int x;
    int y;

    y = 0;
    while (y < map->row)
    {
        x = 0;
        while (x < map->col)
        {
            // draw_tile(x, y, map->map[y][x], img);
            if (map->map[y][x] == 'P')
            {
                // player->pos_x = x;
                // player->pos_y = y;
                draw_player(game, img);
            }
            x++;
        }
        y++;
    }
}

void	draw_player(t_data *game, t_data *img)
{
    if (game->player_x < 0 || game->player_x >= WINDOW_WIDTH || game->player_y < 0 || game->player_y >= WINDOW_HEIGHT)
        return;
    // ft_draw_rectangle(img->player_x * TILE_SIZE, img->player_y * TILE_SIZE,
        // TILE_SIZE, TILE_SIZE, RED, img);
    // printf("la[%d][%d]\n", player->pos_x, player->pos_y);
    mlx_pixel_put(img->mlx, img->win, img->player_x, img->player_y, RED);

}


int	handle_keypress(int keysym, t_data *img)
{
    // get_pos_player(map, player);

	if (keysym == XK_Escape || keysym == 113)
    {
		mlx_destroy_window(img->mlx, img->win);
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
        // ft_draw_window(*img, WINDOW_HEIGHT, WINDOW_WIDTH, BLACK);
        // draw_map(map, img, player);
                        // draw_player(player, img);
        // mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    }

	printf("Keypress: %d\n", keysym);
	return (0);
}

void    render_image(t_data *game, int x, int y, char *path)
{
    int tryx;
    int tryy;

    game->img = mlx_xpm_file_to_image(game->mlx, path, &tryx, &tryy);
    mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);

}

void    put_image(char c, int x, int y, t_data *game)
{
    if (c == '1')
        render_image(game, x, y, "./ressources/wall.xpm");
    if (c == '0')
        render_image(game, x, y, "./ressources/floor.xpm");
    if (c == 'C')
        render_image(game, x, y, "./ressources/collect.xpm");
    if (c == 'E')
        render_image(game, x, y, "./ressources/door.xpm");
    if (c == 'P')
        render_image(game, x, y, "./ressources/bitfuul-image.xpm");

}

void    ft_generate_window(t_data *game)
{
    int x;
    int y;
    int x_map;
    int y_map;

    y_map = 0;
    y = 0;
    while (y < game->map_struc->row)
    {
        x_map = 0;
        x = 0;
        while (x < game->map_struc->col)
        {
            put_image(game->map_struc->map[y][x], x_map, y_map, game);
            // printf("ici texture : [%d][%d]\n", x, y);
            x++;
            x_map += 64;
        }
        y++;
        y_map += 64;
    }
}

int	main(int ac, char **av)
{
    (void) ac;
	t_map	*map;
	t_data	game;
    s_player    *player;
    // int     height = 0;
    // int     width = 0;
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


    init_structure(&game, map);
    ft_print_info(map, path, fd, game);
    
        //init mlx
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    ft_generate_window(&game);
    mlx_hook(game.win, 2, (1L << 0), key_hook, &game); /* ADDED */
    // mlx_hook(game.win, KeyRelease, KeyReleaseMask, &key_hook, &game);
    // mlx_hook(); player input
    // mlx_hook(); exit

    mlx_loop(game.mlx);
    printf("pos[%d][%d]\n", player->pos_x, player->pos_y);
	return (0);
}
