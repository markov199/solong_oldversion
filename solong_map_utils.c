/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:04:02 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:46:05 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"
#include <fcntl.h>
#define FILETYPE ".ber"

// int ft_init_map(t_map *map);
// t_map *ft_load_map(t_map *map);
// int ft_read_map(t_map *map);
// int ft_valid_chars(t_map *map);
// int ft_valid_file_type(t_map *map);
// void ft_valid_map(t_map *map);
// int pop_queue (t_queue **queue);
// void ft_visit(char *str, int position, t_map *map, t_queue **queue);
// void ft_print_index(char *str);

int	ft_init_map(t_map *map)
{
	map->height = 1;
	map->width = 0;
	map->count_1 = 0;
	map->count_0 = 0;
	map->count_p = 0;
	map->count_c = 0;
	map->count_e = 0;
	map->plyr_pos = 0;
	map->collected_c = 0;
	map->valid_exit = 0;
	map->player_moves = 0;
	return (0);
}

t_map	*ft_load_map(t_map *map)
{
	int		fd;
	int		i;
	char	buff;

	i = 0;
	map->map_str = malloc(sizeof(char) * ((map->width + 1) * map->height) + 1);
	if (!map->map_str)
		exit(1);
	fd = open(map->filename, O_RDONLY);
	while (read(fd, &buff, 1))
	{
		map->map_str[i++] = buff;
		if (buff == 'P')
			map->plyr_pos = i - 1;
	}	
	map->map_str[i] = '\0';
	close(fd);
	return (map);
}

int	ft_read_map(t_map *map)
{
	char	buff;
	int		fd;

	fd = open(map->filename, O_RDONLY);
	while (read(fd, &buff, 1))
	{	
		if (!(buff == '1' || buff == '0' || buff == 'C' || buff == 'P' \
				|| buff == 'E' || buff == '\n'))
		{
			write(1, "Error\nCheck map elements\n", 26);
			exit(1);
		}	
		if (buff != '\n' && map->height == 1)
			map->width++;
		if (buff == '\n')
			map->height++;
		if (buff == 'C')
			map->count_c++;
		else if (buff == 'P')
			map->count_p++;
		else if (buff == 'E')
			map->count_e++;
	}
	close (fd);
	return (0);
}

int	ft_valid_chars(t_map *map)
{
	if (map->count_p == 1 && map->count_e == 1 && map->count_c > 0)
		return (0);
	else
		return (-1);
}

int	ft_valid_file_type(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(map->filename);
	i = i - 4;
	if (strcmp(&map->filename[i], FILETYPE) == 0)
		return (0);
	else
	{
		printf("Error\nInvalid  file_type\n");
		exit(1);
	}
}
