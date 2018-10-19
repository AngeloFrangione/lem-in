/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 15:01:33 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/19 19:13:35 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	clean(t_info *info)
{
	t_room *tmp;

	while (info->room)
	{
		free(info->room->links);
		tmp = info->room->next;
		ft_strdel(&info->room->name);
		ft_memdel((void*)&info->room);
		info->room = tmp;
	}
}

int		main(void)
{
	t_info	*info;

	info = ft_memalloc(sizeof(t_info));
	ft_search_ants(info);
	ft_search_rooms(info);
	ft_search_links(info);
	ft_putendl(info->file);
	find_path(info, get_ending_room(info));
	clean(info);
	ft_strdel(&info->file);
	free(info);
	return (0);
}
