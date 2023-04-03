/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:46 by vgoret            #+#    #+#             */
/*   Updated: 2023/04/03 15:37:48 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

typedef struct s_player{
	int	pos_x;
	int	pos_y;
} s_player;

typedef struct s_map{
	char	**map;
	char	*path;
	int		row;
	int		col;
	int		nb_c;
	int		nb_p;
	int		nb_e;
} t_map;

typedef struct  s_textures
{
	// int		w;
	// int		h;
    void    *wall;
    void    *player;
    void    *exit;
    void    *floor;
}               t_textures;

typedef struct s_data {
	t_map	*map_struc;
	t_textures *textures;
    void    *mlx;
    void    *win;
    void    *img;
	int     bits_per_pixel;
    int     line_length;
	int     endian;
	int		player_x;
	int		player_y;
	int		c;
	int		p;
	int		e;
	int		max_c;
	int		move;
	int		width;
	int		height;
} t_data;




/* GET_NEXT_LINE */
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

/* PARSING */
int	verif_arg(char *str);

/* PLAYER */
void	get_pos_player(t_map *map, t_data *game);
void	draw_player(t_data *game, t_data *img);

/* MAP */
void	print_map(char *map_name, int fd);
int	map_height(char *map_name, int fd);
int	map_width(char *map_name, int fd);
char	*map_path(char *map_name);
t_map	*init_map(char *map_name, int fd);
char	**map_tab(t_map *map, int fd);

int		handle_map_error(t_map *map, s_player *player);

int is_map_rules(t_map *map, s_player *player);
int is_map_closed(t_map *map);
char	**read_map(t_map *map);
char	**ft_putmap_tab(t_map *map, int fd);
void    get_map_info(t_map *map, int fd);
/* GAME */
int init_structure(t_data *game, char *av, int fd);

/* UTILS */
char	*ft_strdup(const char *s);

/* PRINTER */
void	print_win();
void	print_loose();
void    ft_print_info(t_map *map, char *path, int fd, t_data img);

int key_hook(int keysym, t_data *game);

t_textures    *load_textures(t_data *game);
void    render_image(t_data **game, int x, int y, char *path);
void    put_image(char c, int x, int y, t_data **game);
void ft_draw_window(t_data *game);


#endif