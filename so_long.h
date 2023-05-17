/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:43:46 by vgoret            #+#    #+#             */
/*   Updated: 2023/05/17 14:50:18 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx_linux/mlx.h"
# include "./src/ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*path;

	char		**map;
	int			row;
	int			col;
	int			width;
	int			height;

	int			player_x;
	int			player_y;
	int			exit_x;
	int			exit_y;
	int			c;
	int			p;
	int			e;
	int			max_c;
	int			move;
	int			collected;
	int			collected_flood;

	int			fd;

	void		*wall;
	void		*floor;
	void		*player_right;
	void		*player_left;
	void		*collect;
	void		*exit_nc;
	void		*exit_colored;
	void		*textures[7];
}				t_data;

/* PARSING */
void			parsing(int ac, char **av, t_data *game);
int				verif_arg(char *str);
int				handle_map_error(t_data *game, char **map);
int				is_map_rules(t_data *game, char **map);
int				is_map_closed(t_data *game, char **map);

/* STRUCTURE */
int				init_structure(t_data *game);
int				init_game(t_data *game, char *path1);
void			init_objects(t_data *game);

/* PLAYER */
void			get_pos_player(t_data *game);

/* MAP */
int				map_height(char *map_name, int fd);
int				map_width(char *map_name, int fd);
void			get_map_info(t_data *game, int fd);
int				ft_check_objects(t_data *game);
char			**create_game(t_data *game);
int				ft_check_working_map(t_data *data);
void			flood_map(t_data *game, char **map, int row, int col);
void			ft_flood_map(t_data *game);
int 			path_finder(char **map);

/* GAME */
int				key_hook(int keysym, t_data *game);
void			ft_generate_window(t_data *game);
void			ft_collect(t_data **game, char c);
void			ft_exit(t_data *game);

/* PRINTER */
void			print_win(t_data *game);
void			print_loose(void);
void			print_move(t_data *game, int move, char *c);
void			ft_print_error(char *str);
void			print_map(t_data *game);

/* DEPLACEMENTS */
void			move(t_data **game, char c);
void			left(t_data **game);
void			right(t_data **game);
void			down(t_data **game);
void			up(t_data **game);

/* TEXTURES */
void			init_img(t_data *game);
void			render_player(t_data **game, int direction, char c);
void			render_img(t_data *game, char c, int x, int y);

/* FREE */
void			free_tab(char **tableau);
int				close_window(t_data *game);
int				close_window2(t_data *game);
void			close_window3(t_data *game);

/* UTILS */
char			*ft_strdup(char *s);
size_t			ft_strlen2(const char *str);
int				ft_strlen(char *str);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);



#endif