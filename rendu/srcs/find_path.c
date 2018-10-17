/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/17 19:44:40 by alanter          ###   ########.fr       */
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

int		path_recursion(t_info *info, t_path *this, t_room *start)
{
	int nb_links;
	int i;
	int j;
	
	i = 0;
	
	while (this->a_paths[this->size]->links[i])
	{
		j = 0;
		while (this->a-path[j] || this->a_path[j] == this->a_path[this->size])
		{
			if (this->a_paths[this->size]->links[i] == this->a_path[j]
					|| this->a_path[j] = info->start)
			{
				i++;
				break ;
			}
			j++
		}
		if (this->a_path[j] == this->a_path[this->size])
		{
	//		if (nb_valid_links > 1)
	//		{
	//		memcopy ? j (taille du path)
	//			copy(this)//jusqu'à size
	//			Changement de path(prendre l'id de la copy pour add le link)
	//		}
			a_path realloc = link(room);
			// ajoute this->a_paths[this->size]->links[i] dans this->a_path
			valid_links++;
			i++
		}
//		nb_links = ft_count_links_2(this_path->a_paths[this_path->size]);
//		while (
//		while (nb_links > 1)
//			copy_path(this_path);
		

	}
	if (valid_links > 0)
		this->size++;
	if (info->nb_ways != info->nb_solution)
	{
		//current_path = first_path;
		path_recursion(info, firstpath)
	}
//	while (other_path size < this->size)
//		path_recursion;

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
	// stocker la start en a_path[0]
	while (info->nb_paths < nb_links)
	{
		// path->a_path[0] = get_room(info, start->tubes->connection);
		path->a_path[0] = start->links[info->nb_paths];
		// start->tubes = start->tubes->next;
//		ft_putnbr(info->nb_paths);
//		print_paths(path);
		info->nb_paths++;
		path = path->next;
		add_path(&path, info->nb_paths);
	}
	path_recursion(info, info->first_path, start);
	return (0);
}

