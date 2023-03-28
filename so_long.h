/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:46 by vgoret            #+#    #+#             */
/*   Updated: 2023/03/28 14:33:37 by vgoret           ###   ########.fr       */
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
	
} s_player;

typedef struct s_map{
	char	**map;
	char	*path;
	int		width;
	int		height;
	int		nb_c;
	int		nb_p;
	int		nb_e;
} t_map;

/* GET_NEXT_LINE */
int		ft_strlen(char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

/* PARSING */
int	verif_arg(char *str);

/* PLAYER */

/* MAP */
void	print_map(char *map_name);
int	map_height(char *map_name);
int	map_width(char *map_name);
char	*map_path(char *map_name);
t_map	*init_map(char *map_name);
char	**map_tab(char *path, t_map *map);

/* GAME */

#endif