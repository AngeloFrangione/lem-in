/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 19:07:32 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 16:15:35 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		*create_room(char *name)
{
	t_room *node;

	if (!(node = ft_memalloc(sizeof(t_room))))
		return (NULL);
	else
	{
		node->name = name;
		node->next = NULL;
		node->links = ft_memalloc(sizeof(t_room) * 2);
		if (!node->links)
			return (NULL);
	}
	return (node);
}

void		add_room(t_room **begin_node, char *name)
{
	t_room	*tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_room(name);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_room(name);
	}
}
