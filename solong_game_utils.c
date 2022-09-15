/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:46:34 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:46:05 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

void	ft_valid_map(t_map *map)
{
	if (ft_valid_chars(map) == -1)
	{
		printf("Error\nInvalid  number of element\n");
		free(map->map_str);
		exit(1);
	}
	ft_load_map(map);
	if (ft_valid_path(map) == -1)
	{
		free(map->map_str);
		printf("Error\n No valid path in map");
		exit(1);
	}
	map->valid_exit = 0;
	map->collected_c = 0;
}

void	ft_visit(char *str, int position, t_map *map, t_queue **queue)
{
	if (str[position] == '0' || str[position] == 'C')
	{
		if (str[position] == 'C')
			map->collected_c++;
		ft_queue_add_back(queue, ft_queue_new(position));
		str[position] = 'V';
	}
	else if (str[position] == 'E')
	{
		map->valid_exit++;
		str[position] = '1';
	}	
}

void	ft_move_player(t_data *data, int x, int y)
{
	if (data->move_left == 0)
	{
		if (data->map->player_moves % 2)
			mlx_put_image_to_window(data->mlx, data->win, data->pf_img, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->p2_img, x, y);
	}
	else
	{
		if (data->map->player_moves % 2)
			mlx_put_image_to_window(data->mlx, data->win, data->p_img, x, y);
		else
			mlx_put_image_to_window(data->mlx, data->win, data->p2f_img, x, y);
	}
}
