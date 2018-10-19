/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/19 16:37:13 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		find_path(t_info *info, t_room *end)
{
	int nb_links;
	int i;
	int size;

	size = -1;
	info->path = ft_memalloc(sizeof(t_room*) * count_rooms(info));
	info->path[0] = end;
	end->visited = 1;
	end->next_room = NULL;
	i = 0;
	while (info->path[i])
	{
		nb_links = 0;
		while (nb_links < ft_count_links(info->path[i]))
		{
			if (!(info->path[i]->links[nb_links]->visited))
			{
				size = ft_size_path(info);
				info->path[size] = info->path[i]->links[nb_links];
				info->path[size]->visited = 1;
				info->path[size]->next_room = info->path[i];
			}
			if ((info->path[size])->end)
				break ;
			nb_links++;
		}
		if (size != -1 && (info->path[size])->end)
			break ;
		i++;
	}
	while (info->path[size])
	{
		ft_putstr(info->path[size]->name);
		ft_putstr(" ==> ");
		info->path[size] = info->path[size]->next_room;
	}
	ft_putstr("Path found !!!!\n");
	free(info->path);
	return (0);
}
