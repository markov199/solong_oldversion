/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:48:27 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:46:05 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_endgame(t_data *data)
{
	free(data->map->map_str);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	ft_move(t_data *data, t_map *map, int new_pos)
{	
	if (map->map_str[new_pos] == '0' || map->map_str[new_pos] == 'C' )
	{
		if (map->map_str[new_pos] == 'C')
			map->collected_c++;
		map->player_moves++;
		printf("moves = %d\n", map->player_moves);
		map->map_str[new_pos] = 'P';
		map->map_str[map->plyr_pos] = '0';
		map->plyr_pos = new_pos;
	}
	else if (map->map_str[new_pos] == 'E')
	{
		if ((map->collected_c - map->count_c) == 0)
		{
			map->player_moves++;
			printf("moves = %d\n", map->player_moves);
			ft_endgame(data);
		}	
	}
	return (0);
}

void	ft_map_loader(t_map *map)
{
	ft_valid_file_type(map);
	ft_init_map(map);
	ft_read_map(map);
	ft_valid_map(map);
}

int	main(void)
{
	t_data	data;
	t_map	map;
	int		size;

	size = 50;
	data.map = &map;
	map.filename = "map.ber";
	ft_map_loader(&map);
	data.mlx = mlx_init();
	ft_load_images(&data, size, map);
	data.win = mlx_new_window(data.mlx, data.window_width, \
	data.window_height, "SoLong");
	ft_load_map_to_window(data, map);
	mlx_hook(data.win, 17, 0, &ft_endgame, &data);
	mlx_hook(data.win, 2, 0, &key_hook, &data);
	mlx_loop(data.mlx);
}
