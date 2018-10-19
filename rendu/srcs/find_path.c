/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efouille <efouille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/19 02:45:29 by efouille         ###   ########.fr       */
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

int	ft_search_in_paths(t_info *info, t_room *room, t_room *start)
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

int	ismarked(t_info *info, t_room *sommet)
{
/**/
	t_stack	*k;

	k = info->mark;
	while (k)
	{
		if (ft_strstr(k->content, sommet->name))
			return (1);
		k = k->next;
	}
/**/
	/*if (ft_strstr(info->mark, sommet->name))
		return (1);*/
	return (0);
}

void mark(t_info *info, t_room *sommet)
{
	//if (!info->mark)
	//{
		//info->mark = ft_memalloc(sizeof(char) * ( 1 + ft_strlen(sommet->name)));
		//ft_strcat(info->mark, sommet->name);
/**/
		ft_stackpush(&(info->mark), sommet->name, ft_strlen(sommet->name) + 1);
/**/
	/*}
	else
	{
		info->mark = ft_realloc(info->mark, sizeof(char) * (ft_strlen(info->mark) + ft_strlen(sommet->name) + 2));
		ft_strcat(info->mark, "-");
		ft_strcat(info->mark, sommet->name);

	}*/
}

int find_path(t_info *info, t_room *sommet, t_stack **path)
{
	int		nb_links;
	int		ret;

	ft_stackpush(path, sommet->name, ft_strlen(sommet->name) + 1);
	if (sommet->end)
		return (1);
	nb_links = ft_count_links_2(sommet);
	mark(info, sommet);
	// ft_putstr(sommet->name);
	ret = 0;
	while (nb_links--)
	{
		if (!ismarked(info, sommet->links[nb_links]))
			ret = find_path(info, sommet->links[nb_links], path);
		if (ret)
			return (1);
		else
			ft_stackpop(*path);
	}
	return (0);
}