/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 18:14:44 by alanter           #+#    #+#             */
/*   Updated: 2018/10/17 16:29:56 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_paths		*create_path(int id)
{
	t_paths *node;

	if (!(node = ft_memalloc(sizeof(t_paths))))
		return (NULL);
	else
	{
		node->id = id;
		node->a_path = ft_memalloc(sizeof(t_room) * 4);
		node->next = NULL;
	}
	return (node);
}

void		add_path(t_paths **begin_node, int id)
{
	t_paths	*tmp;

	tmp = *begin_node;
	if (!*begin_node)
		*begin_node = create_path(id);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_path(id);
	}
}

void	print_paths(t_paths *begin_node)
{
	int i;

	i = 0;
//	while (begin_node)
//	{
		while (begin_node->a_path[i])
		{
			ft_putstr("{\x1B[32m");
			ft_putnbr(i);
			ft_putstr("\e[m[\x1B[35m");
			ft_putstr(begin_node->a_path[i]->name);
			ft_putstr("==>");
			i++;
		}
		ft_putstr("\e[m]");
		ft_putchar('}');
		ft_putstr("\n");
//		if (begin_node->next)
//			ft_putstr("\n");
	//	begin_node = begin_node->next;
//	}
}
