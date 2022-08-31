/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:23:38 by mkovoor           #+#    #+#             */
/*   Updated: 2022/08/31 14:03:03 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_map
{
	char	*filename;
	int 	height;
	int 	width;
	int 	count_1;
	int		count_0;
	int 	count_P;
	int		count_C;
	int 	count_E;
} t_map;

int ft_check_map(char *filename, t_map *map);

int ft_init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->count_1 = 0;
	map->count_0 = 0;
	map->count_P = 0;
	map->count_C = 0;
	map->count_E = 0;
	return (0);
}

int main(int ac, char *av[])
{
	t_map map;

	map.filename = av[1];
	ft_init_map(&map);
	if (ft_check_map(map.filename, &map) == -1)
		write(1, "Error\n", 6);
}

int ft_check_map(char *filename, t_map *map)
{
	int line;
	char	buff;
	int fd;
	int w;

	line = 1;
	w = 1;
	fd = open(filename, O_RDONLY);	
	while(read(fd, &buff, 1))
	{
		
		if(buff != '\n')
			w++;
		if(buff == '\n')
			line++;
		if (line == 1)
			map->width = w;
		if (buff == 'C')
			map->count_C++;
		if (buff == 'P')
			map->count_P++;
		if (buff == 'E')
			map->count_E++;
	}
	if (!(map->count_P == 1 && map->count_E == 1 && map->count_C > 0))
		return(-1);
	map->height = line;
	printf("%d lines, %d width\n", line, map->width);
	// ft_check_walls(map);
	return (0);
}

// int ft_isrectangle()
// {

// }