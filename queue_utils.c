/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkovoor <mkovoor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:01:04 by mkovoor           #+#    #+#             */
/*   Updated: 2022/09/15 15:56:50 by mkovoor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"solong.h"

void	ft_queue_add_back(t_queue **lst, t_queue *new)
{
	t_queue	*ptr;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

t_queue	*ft_queue_new(int index)
{
	t_queue	*new;

	new = NULL;
	new = (t_queue *)malloc(sizeof (t_queue));
	if (new == NULL)
		return (NULL);
	new ->index = index;
	new ->next = NULL;
	return (new);
}

void	ft_queue_delete(t_queue **queue)
{
	t_queue	*temp;

	if (!(*queue))
		return ;
	while (*queue)
	{
		temp = *queue;
		*queue = (*queue)->next;
		free (temp);
	}
	*queue = NULL;
}

void	ft_queue_print(t_queue *queue)
{
	t_queue	*temp;

	temp = queue;
	while (temp)
	{
		printf("%d,", temp->index);
		temp = temp->next;
	}
	printf("\n");
}

int	pop_queue(t_queue **queue)
{
	int		temp;
	t_queue	*ptr;

	if (queue != NULL)
	{
		ptr = *queue;
		temp = ptr ->index;
		*queue = ptr->next;
		free(ptr);
		return (temp);
	}
	return (-1);
}
