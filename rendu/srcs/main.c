/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:01:33 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/16 18:53:08 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean(t_info *info)
{
	t_room *tmp;
	t_tube *tmp_t;

	while (info->room)
	{
		free(info->room->links);
		tmp = info->room->next;
		ft_strdel(&info->room->name);
		while (info->room->tubes)
		{
			tmp_t = info->room->tubes->next;
			ft_strdel(&info->room->tubes->connection);
			ft_memdel((void*)&info->room->tubes);
			info->room->tubes = tmp_t;
		}
		// ft_memdel(info->room->links);
		ft_memdel((void*)&info->room);
		info->room = tmp;
	}
}

void	print_rooms(t_room *begin_node)
{
	while (begin_node)
	{
		ft_putstr("{\x1B[32m");
		ft_putstr(begin_node->name);
		ft_putstr("\e[m[\x1B[35m");
		while (begin_node->tubes)
		{
			ft_putstr(begin_node->tubes->connection);
			(begin_node->tubes->next) ? ft_putchar(',') : 0;
			begin_node->tubes = begin_node->tubes->next;
		}
		ft_putstr("\e[m]");
		ft_putchar('}');
		ft_putchar('(');
		ft_putstr("\x1B[34m");
		ft_putnbr(begin_node->start);
		ft_putnbr(begin_node->end);
		ft_putstr("\x1B[m");
		ft_putchar(')');
		if (begin_node->next)
			ft_putstr("->");
		begin_node = begin_node->next;
	}
}

int		main(void)
{
	t_info *info;

	info = ft_memalloc(sizeof(t_info));
	ft_search_ants(info);
	ft_search_rooms(info);
	ft_search_links(info);
	ft_putendl(info->file);
	find_path(info, get_starting_room(info));
	// print_rooms(info->room);
	clean(info);
	ft_strdel(&info->file);
	free(info);
	return (0);
}
