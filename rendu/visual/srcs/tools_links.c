/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:50:04 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/16 16:08:52 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_link_exists(t_room *room, char *connection)
{
	t_tube *tmp;

	tmp = room->tubes;
	while (tmp)
	{
		if (ft_strequ(tmp->connection, connection))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_check_link_exists_2(t_room *room, char *connection)
{
	int i;

	i = 0;
	while ((room->links[i]))
	{
		if (room->links[i]->name)
			if (ft_strequ((room->links[i])->name, connection))
				return (1);
		i++;
	}
	return (0);
}


void	ft_assignlink(t_room *room, t_room *link)
{
	int i;

	i = 0;
	while (room->links[i])
		i++;
	room->links = ft_memrealloc(room->links, sizeof(t_room) * (i),sizeof(t_room) * (i + 1));
	room->links[i] = link;
}

void	ft_addlink(t_info *info, char *room, char *link)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
		{
			if (!ft_check_link_exists(tmp, link))
				add_tube(&tmp->tubes, ft_strdup(link));
		}
		tmp = tmp->next;
	}
	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, room))
		{
			if (!ft_check_link_exists_2(tmp, link))
				ft_assignlink(tmp, get_room(info, link));
		}
		tmp = tmp->next;
	}

}

int		ft_check_room_exists(t_info *info, char *name)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_islink(t_info *info)
{
	char	**split;
	int		i;

	if (ft_strchr(info->buff, ' '))
		return (0);
	split = ft_strsplit(info->buff, '-');
	i = 0;
	while (split[i])
		i++;
	if (i != 2)
	{
		info->error_no_exit = -7;
		free_charofchar(split);
		return (0);
	}
	if (ft_strequ(split[0], split[1]))
		return (-1);
	if (!ft_check_room_exists(info, split[0]) ||
		!ft_check_room_exists(info, split[1]))
		return (-1);
	ft_addlink(info, split[0], split[1]);
	ft_addlink(info, split[1], split[0]);
	free_charofchar(split);
	return (1);
}
