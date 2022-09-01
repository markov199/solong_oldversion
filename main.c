/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:23:38 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/01 15:21:40 by mkovoor          ###   ########.fr       */
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
	int		plyr_pos;
	int		col_C;
} t_map;

int ft_check_map(t_map *map);
int ft_valid_boundaries(t_map map);
int ft_isrectangle(char *map_str);

int ft_init_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->count_1 = 0;
	map->count_0 = 0;
	map->count_P = 0;
	map->count_C = 0;
	map->count_E = 0;
	plyr_pos = 0;
	col_C = 0;

	return (0);
}

char *ft_load_map(t_map *map)
{
	char *map_str;
	int	fd;
	int i;
	char	buff;

	i = 0;
	map_str = malloc(sizeof(char)* (map->width * map->height) + 1);
	fd = open(map->filename, O_RDONLY);
	while (read(fd, &buff, 1))
			map_str[i++] = buff;
	map_str[i] = '\0';
	printf("%s map\n", map_str);
	return (map_str);

}

int main(int ac, char *av[])
{
	t_map map;
	char	*map_str;

	map.filename = av[1];
	ft_init_map(&map);
	if (ft_check_map(&map) == -1)
		write(1, "Error. Check map elements\n", 27);
	map_str = ft_load_map(&map);
	ft_isrectangle(map_str);
	ft_valid_boundaries(map_str);
	// else if (ft_valid_boundaries(map) == -1)
	// 	write(1, "Error not valid boundaries\n", 28);

}

int ft_check_map(t_map *map)
{
	int line;
	char	buff;
	int fd;
	int w;

	line = 1;
	w = 0;
	fd = open(map->filename, O_RDONLY);
	while(read(fd, &buff, 1))
	{
		
		if(buff != '\n')
			w++;
		if(buff == '\n')
		{
			map->height++;
			if (!map->width)
				map->width = w;
		}	
		if (buff == 'C')
			map->count_C++;
		else if (buff == 'P')
		{
			map->plyr_pos = (map->height * map->width) 
			map->count_P++;
		}
		else if (buff == 'E')
			map->count_E++;
		if (buff != '1' && buff !='0' && buff != '\n' && buff != 'C'
			&& buff != 'P' && buff != 'E')
		{
			printf("%c buff %d w\n", buff, w);
			return (-1);
		}	
		
	}
	if (!(map->count_P == 1 && map->count_E == 1 && map->count_C > 0))
		return(-1);
	
	printf("%d lines, %d width %d\n", line, map->width, w);
	close(fd);
	// ft_check_walls(map);
	return (0);
}

int ft_isrectangle(char *map_str)
{
	int	i;
	int w;
	int	line;
	int len;

	i = 0;
	w = 0;
	line = 0;
	len = 0;
	while(map_str[i])
	{		
		if(map_str[i] != '\n')
			w++;
		if(map_str[i] == '\n' || map_str[i] == '\0')
		{
			if (line == 1)
				len = w;		
			if (line > 1)
			{
				if(len != w)
				{
					write(1, "Error , not a rectangle\n", 24);
					return(-1);
				}
			}
			line++;
			w = 0;
		}
		i++;
	}		
		return (0);
}

int ft_valid_boundaries(char *map_str)
{
	int	fd;
	int	line;
	int	ch;
	char	buff;

	fd = open(map.filename, O_RDONLY);
	line = 1;
	while(line++ <= map.height)
	{
		ch = 1;
		while(ch <= map.width)
		{
			read(fd, &buff, 1);
			if (buff != '\n')
			{
				ch++;
				if ((ch == 1) || (ch == map.width) && (buff != '1'))
				{
					printf("%d line, %d ch, %c buff edges\n", line, ch, buff);
					return (-1);
				}
				if ((line == 1 || line == map.height) && (buff != '1' || buff != '\n'))
				{
					printf("%d line, %d ch %c, buff top or bottom\n", line, ch, buff);
					return (-1);
				}
			}
		}
	}
	return (0);
}