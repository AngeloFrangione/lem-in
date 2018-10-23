/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:07:32 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 16:21:23 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*create_room(char *name, int x, int y)
{
	t_room *node;

	if (!(node = ft_memalloc(sizeof(t_room))))
		return (NULL);
	else
	{
		node->x = x;
		node->y = y;
		node->name = name;
		node->next = NULL;
		node->links = ft_memalloc(sizeof(t_room) * 2);
	}
	return (node);
}

void		add_room(t_room **begin_node, char *name, int x, int y)
{
	t_room	*tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_room(name, x, y);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_room(name, x, y);
	}
}

t_tube		*create_tube(char *connection)
{
	t_tube *node;

	if (!(node = ft_memalloc(sizeof(t_tube))))
		return (NULL);
	else
	{
		node->connection = connection;
		node->next = NULL;
	}
	return (node);
}

void		add_tube(t_tube **begin_node, char *connection)
{
	t_tube	*tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_tube(connection);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_tube(connection);
	}
}
