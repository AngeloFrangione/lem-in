/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/16 19:44:49 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_count_links_2(t_room *room)
{
	int		i;

	i = 0;
	while (room->links[i])
		i++;
	return (i);
}

int		find_path(t_info *info, t_room *start)
{
	int nb_links;
	t_paths *path;	
	//t_room *tmp;
	//tmp = start;

	info->first_path = create_path(info->nb_paths);
	path = info->first_path;
	nb_links = ft_count_links_2(start);
	//debuguer count_links
	while (info->nb_paths < nb_links)
	{
		// path->a_path[0] = get_room(info, start->tubes->connection);
		path->a_path[0] = start->links[info->nb_paths];
		// start->tubes = start->tubes->next;
		ft_putnbr(info->nb_paths);
		print_paths(path);
		info->nb_paths++;
		path = path->next;
		add_path(&path, info->nb_paths);
	}
	return (0);
}

