/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:01:33 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 16:53:55 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "visual.h"

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

int		main(void)
{
	t_info *info;

	info = ft_memalloc(sizeof(t_info));
	ft_search_ants(info);
	ft_search_rooms(info);
	ft_search_links(info);
//	ft_putendl(info->file);
	window(info);
	clean(info);
	ft_strdel(&info->file);
	free(info);
	return (0);
}
