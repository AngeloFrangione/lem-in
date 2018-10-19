/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angelo <angelo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/19 03:02:12 by angelo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_links_2(t_room *room)
{
	int		i;

	i = 0;
	while (room->links[i] )
		i++;
	return (i);
}

int		ft_search_in_paths(t_info *info, t_room *room, t_room *start)
{
	t_paths	*path;
	int		i;

	path = info->first_path;
	if (room == start)
		return (1);
	while (path)
	{
		i = 0;
		while (i <= path->size && path->a_path[i] != NULL)
		{
			if (room == path->a_path[i])
				return (1);
			i++;
		}
		path = path->next;
	}
	return (0);
}

int		ismarked(t_info *info, t_room *sommet)
{
	t_stack	*k;

	k = info->mark;
	while (k)
	{
		if (ft_strstr(k->content, sommet->name))
			return (1);
		k = k->next;
	}
	return (0);
}

int find_path(t_info *info, t_room *sommet, t_stack **path)
{
	int		nb_links;
	int		ret;
	
	ft_stackpush(path, sommet->name, ft_strlen(sommet->name) + 1);
	ft_stackpush(&(info->mark), sommet->name, ft_strlen(sommet->name) + 1);
	if (sommet->end)
		return (1);
	nb_links = ft_count_links_2(sommet);
	ret = 0;
	while (nb_links--)
	{
		if (!ismarked(info, sommet->links[nb_links]))
			ret = find_path(info, sommet->links[nb_links], path);
		else
			ft_stackpush(path, sommet->name, ft_strlen(sommet->name) + 1);
		if (ret)
			return (1);
		else
			ft_stackpop(*path);
	}
	return (0);
}