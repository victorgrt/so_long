/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/04/02 23:11:18 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void left(t_data *game)
{
    int img_w;
    int img_h;

    if (game->map_struc->map[game->player_x - 1][game->player_y] != '1')
    {
        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);

        game->player_x -= 1;

        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);
    }
    else    
        printf("Erreur : next char = %d\n", game->map_struc->map[game->player_x - 1][game->player_y]);
}

void right(t_data *game)
{
    int img_w;
    int img_h;

    // if (game->map_struc->map[game->player_x][game->player_y])
    if (game->map_struc->map[game->player_x + 1][game->player_y] != '1')
    {
        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);

        game->player_x += 1;

        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);
    }
    else
        printf("Erreur : next char = %d\n", game->map_struc->map[game->player_x+1][game->player_y]);
}

void up(t_data *game)
{
    int img_w;
    int img_h;

    // if (game->map_struc->map[game->player_x][game->player_y])
    if (game->map_struc->map[game->player_x][game->player_y-1] != '1')
    {
        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);

        game->player_y -= 1;

        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);
    }
    else    
        printf("Erreur : next char = %d\n", game->map_struc->map[game->player_x][game->player_y-1]);
}

void down(t_data *game)
{
    int img_w;
    int img_h;

    // if (game->map_struc->map[game->player_x][game->player_y])
    if (game->map_struc->map[game->player_x][game->player_y+1] != '1')
    {
        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);

        game->player_y += 1;

        game->img = mlx_xpm_file_to_image(game->mlx, "./ressources/bitfuul-image.xpm", &img_w, &img_h);
        mlx_put_image_to_window(game->mlx, game->win, game->img, game->player_x*64, game->player_y*64);
    }
     else    
        printf("Erreur : next char = %d\n", game->map_struc->map[game->player_x][game->player_y+1]);
}

int key_hook(int keysym, t_data *game)
{
    // get_pos_player(map, player);
    if (keysym == 113 || keysym == 65307)
    {
        mlx_destroy_window(game->mlx, game->win);
        exit(0);
        return (0);
    }
    if (keysym == 65362 || keysym == 65364 || keysym == 65363 || keysym == 65361)
    {
        if (keysym == 65362)
        {
            printf("ici : %d\n", game->map_struc->map[game->player_x][game->player_y-1]);
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_x += -1;
            up(game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65364)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_x += 1;
            down(game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65361)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // int dest = game->player_y - 1;s
            left(game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65363)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_y += 1;
            right(game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        // ft_draw_window(*game, WINDOW_HEIGHT, WINDOW_WIDTH, BLACK);
        // draw_map(map, game, player);
        // mlx_put_image_to_window(game->mlx, game->win, game->game, 0, 0);
    }
    printf("Keypress: %d\n", keysym);
    printf("nb of move : %d\n", game->move);
    return (0);
}

    int handle_keyrelease(int keysym)
    {
        printf("Keyrelease: %d\n", keysym);
        return (0);
    }
