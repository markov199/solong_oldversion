/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:52:29 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:46:05 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include<unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include<string.h>
# include"solong.h"
# include "./minilibx/mlx.h"

# define PLYR "images/player.xpm"
# define PLYRF "images/playerflip.xpm"
# define PLYR2 "images/player2.xpm"
# define PLYR2F "images/player2flip.xpm"
# define COIN "images/coin.xpm"
# define DOOR "images/door.xpm"
# define WALL "images/wall.xpm"
# define GRASS "images/grass.xpm"

typedef struct s_map
{
	char	*filename;
	int		height;
	int		width;
	int		count_1;
	int		count_0;
	int		count_p;
	int		count_c;
	int		count_e;
	int		plyr_pos;
	int		collected_c;
	int		valid_exit;
	char	*map_str;
	int		player_moves;
}	t_map;

typedef struct s_queue
{
	int				index;
	struct s_queue	*next;
}	t_queue;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*p_img;
	void	*p2_img;
	void	*p2f_img;
	void	*pf_img;
	void	*coin_img;
	void	*door_img;
	void	*wall_img;
	void	*grass_img;
	int		window_width;
	int		window_height;
	int		i;
	int		move_left;
	t_map	*map;
}	t_data;

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		get_rgb(int red, int green, int blue);
void	ft_queue_print(t_queue *queue);
void	ft_queue_delete(t_queue **queue);
t_queue	*ft_queue_new(int index);
void	ft_queue_add_back(t_queue **lst, t_queue *new);
int		pop_queue(t_queue **queue);

int		ft_read_map(t_map *map);
void	ft_valid_map(t_map *map);
int		ft_valid_chars(t_map *map);
int		ft_valid_file_type(t_map *map);
int		ft_valid_boundaries(t_map map);
int		ft_isrectangle(char *map_str);
int		ft_init_map(t_map *map);
t_map	*ft_load_map(t_map *map);

void	ft_load_map_to_window(t_data data, t_map map);
int		ft_endgame(t_data *data);
int		ft_move(t_data *data, t_map *map, int new_pos);
int		key_hook(int keycode, t_data *data);
void	ft_load_images(t_data *data, int size, t_map map);
void	ft_map_loader(t_map *map);
int		ft_valid_path(t_map *map);
void	ft_visit(char *str, int position, t_map *map, t_queue **queue);
void	ft_move_player(t_data *data, int x, int y);

#endif