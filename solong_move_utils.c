/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_move_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 07:46:16 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:29:48 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_hook(int keycode, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13 || keycode == 126)
		ft_move(data, data->map, (data->map->plyr_pos - data->map->width - 1));
	if (keycode == 1 || keycode == 125)
		ft_move(data, data->map, (data->map->plyr_pos + data->map->width + 1));
	if (keycode == 0 || keycode == 123)
	{
		ft_move(data, data->map, (data->map->plyr_pos - 1));
		data->move_left = 1;
	}
	if (keycode == 2 || keycode == 124)
	{
		data->move_left = 0;
		ft_move(data, data->map, (data->map->plyr_pos + 1));
	}	
	if (keycode == 53)
		ft_endgame(data);
	ft_load_map_to_window(*data, *(data)->map);
	return (0);
}

void	ft_load_images(t_data *data, int size, t_map map)
{
	data->window_height = map.height * 50;
	data->window_width = map.width * 50;
	data->p_img = mlx_xpm_file_to_image(data->mlx, PLYR, &size, &size);
	data->p2_img = mlx_xpm_file_to_image(data->mlx, PLYR2, &size, &size);
	data->pf_img = mlx_xpm_file_to_image(data->mlx, PLYRF, &size, &size);
	data->p2f_img = mlx_xpm_file_to_image(data->mlx, PLYR2F, &size, &size);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, COIN, &size, &size);
	data->door_img = mlx_xpm_file_to_image(data->mlx, DOOR, &size, &size);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, WALL, &size, &size);
	data->grass_img = mlx_xpm_file_to_image(data->mlx, GRASS, &size, &size);
	data->i = -1;
}

void	ft_load_map_to_window(t_data data, t_map map)
{
	int	x;
	int	y;

	while (map.map_str[++data.i])
	{
		x = (data.i % (map.width + 1)) * 50;
		y = (data.i / (map.width + 1)) * 50;
		if (map.map_str[data.i] == 'P')
			ft_move_player(&data, x, y);
		else if (map.map_str[data.i] == '\n')
			mlx_string_put(data.mlx, data.win, x, y, 0, "\n");
		else if (map.map_str[data.i] == '1')
			mlx_put_image_to_window(data.mlx, data.win, data.wall_img, x, y);
		else if (map.map_str[data.i] == 'E')
			mlx_put_image_to_window(data.mlx, data.win, data.door_img, x, y);
		else if (map.map_str[data.i] == 'C')
			mlx_put_image_to_window(data.mlx, data.win, data.coin_img, x, y);
		else if (map.map_str[data.i] == '0')
			mlx_put_image_to_window(data.mlx, data.win, data.grass_img, x, y);
	}
}
