/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:06:12 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 17:46:05 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (dest == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_valid_path(t_map *map)
{
	int		node;
	t_queue	*queue;
	char	*str;

	queue = NULL;
	ft_queue_add_back(&queue, ft_queue_new(map->plyr_pos));
	str = ft_strdup(map->map_str);
	while (queue != NULL && (map->valid_exit < 1 \
		|| map->collected_c < map->count_c))
	{
		node = pop_queue(&queue);
		ft_visit(str, (node - 1), map, &queue);
		ft_visit(str, (node + 1), map, &queue);
		ft_visit(str, (node - map->width -1), map, &queue);
		ft_visit(str, (node + map->width + 1), map, &queue);
	}
	free(str);
	ft_queue_delete(&queue);
	if (map->valid_exit == 1 && map->collected_c == map->count_c)
		return (0);
	else
		return (-1);
}

int	get_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}
