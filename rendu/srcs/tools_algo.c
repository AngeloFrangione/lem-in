/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:50:12 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/16 18:00:04 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*get_room(t_info *info, char *s)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (ft_strequ(s, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*get_starting_room(t_info *info)
{
	t_room *tmp;

	tmp = info->room;
	while (tmp)
	{
		if (tmp->start)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		ft_count_links(t_room *room)
{
	t_tubes *tmp;
	int		i;

	i = 0;
	if (room->tubes)
	{
		i = 1;
		while (tmp)
		{
			i ++;
			tmp = tmp->next;
		}
	}
	return (i);
}