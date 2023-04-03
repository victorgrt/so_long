/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 13:19:22 by victor            #+#    #+#             */
/*   Updated: 2023/04/03 17:42:00 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void printmap(t_data **game)
{
    int i = 0;
    while((*game)->map_struc->map[i])
    {
        printf("%s\n", (*game)->map_struc->map[i]);
        i++;
    }
}

void left(t_data **game)
{
    int img_w;
    int img_h;

    if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x - 1] != '1')
    {
        if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x - 1] == 'C')
        {
            ft_collect(game, 'l');
            return ;
        }
        else if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x - 1] == 'E')
        {
            ft_exit(game);  
            return ;
        }
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);


        // (*game)->map_struc->map[(*game)->player_x][(*game)->player_y] = '0';
        (*game)->player_x -= 1;
        // (*game)->map_struc->map[(*game)->player_x][(*game)->player_y] = 'P';
        
        
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
        // printmap(game);
        printf("[%d][%d]\n", (*game)->player_x, (*game)->player_y);
    }
    else    
    {
        // printmap(game);
        printf("Erreur : next char = %d\n", (*game)->map_struc->map[(*game)->player_y][(*game)->player_x-1]);
    }
}

void down(t_data **game)
{
    int img_w;
    int img_h;

    if ((*game)->map_struc->map[(*game)->player_y+1][(*game)->player_x] != '1')
    {
        if ((*game)->map_struc->map[(*game)->player_y+1][(*game)->player_x] == 'C')
        {
            ft_collect(game, 'd');
            return ;
        }
        else if ((*game)->map_struc->map[(*game)->player_y+1][(*game)->player_x] == 'E')
        {
            ft_exit(game);
            return ;
        }
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);

        (*game)->player_y += 1;

        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);

        printf("[%d][%d]\n", (*game)->player_x, (*game)->player_y);
    }
    else    
    {

        printf("Erreur : next char = %d\n", (*game)->map_struc->map[(*game)->player_y+1][(*game)->player_x]);
    }
}

void up(t_data **game)
{
    int img_w;
    int img_h;

    if ((*game)->map_struc->map[(*game)->player_y - 1][(*game)->player_x] != '1')
    {
        if ((*game)->map_struc->map[(*game)->player_y - 1][(*game)->player_x] == 'C')
        {
            ft_collect(game, 'u');
            return ;
        }
        else if ((*game)->map_struc->map[(*game)->player_y - 1][(*game)->player_x] == 'E')
        {
            ft_exit(game);
            return ;
        }
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);

        (*game)->player_y -= 1;

        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);
        // printmap(game);
        printf("[%d][%d]\n", (*game)->player_x, (*game)->player_y);
    }
         else    
    {
        // printmap(game);
        printf("Erreur : next char = %d\n", (*game)->map_struc->map[(*game)->player_y-1][(*game)->player_x]);
    }
}


void right(t_data **game)
{
    int img_w;
    int img_h;

    if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x + 1] != '1')
    {
        if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x + 1] == 'C')
        {
            ft_collect(game, 'r');
            printf("Collectabless>>>>>>>>>> %d/%d\n", (*game)->c, (*game)->max_c);
            return ;
        }
        else if ((*game)->map_struc->map[(*game)->player_y][(*game)->player_x + 1] == 'E')
        {
            ft_exit(game);
            return ;
        }
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/floor.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);


        (*game)->player_x += 1;
        
        
        (*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./ressources/alien.xpm", &img_w, &img_h);
        mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img, (*game)->player_x*64, (*game)->player_y*64);

    }
    else    
    {
        // printmap(game);
        printf("Erreur : next char = %d\n", (*game)->map_struc->map[(*game)->player_y][(*game)->player_x+1]);
    }
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
            // printf("ici : %d\n", game->map_struc->map[game->player_x][game->player_y-1]);
            // printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_x += -1;
            up(&game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65364)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_x += 1;
            down(&game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65361)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // int dest = game->player_y - 1;s
            left(&game);
            game->move++;
            printf("after:[%d][%d]\n", game->player_x, game->player_y);
        }
        if (keysym == 65363)
        {
            printf("before:[%d][%d]\n", game->player_x, game->player_y);
            // game->player_y += 1;
            right(&game);
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
