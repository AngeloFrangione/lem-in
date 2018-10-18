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


t_paths		*path_recursion(t_info *info, t_paths *this_p, t_room *start)
{
	int i;

	i = 0;
	while ((this_p->a_path[this_p->size])->links[i])
	{
		int next;
		next =  sizeof(t_room*) * (this_p->size + 2);
		this_p->a_path = realloc(this_p->a_path, next);
		if (!ft_search_in_paths(info, (this_p->a_path[this_p->size])->links[i], start))
		{
			this_p->a_path[this_p->size + 1] = this_p->a_path[this_p->size]->links[i];
			this_p->size++;
			path_recursion(info, this_p, start);
		}
		else
			this_p->a_path[this_p->size + 1] = NULL;
		i++;
	}
	// if (((this_p->a_path[this_p->size])->links[i]) && ((this_p->a_path[this_p->size])->links[i])->end)
		// return (this_p);
	if (this_p->next && this_p->next->a_path[0])
		path_recursion(info, this_p->next, start);
	// path_recursion(info, this_p, start);
	return (NULL);
}

int		find_path(t_info *info, t_room *start)
{
	int nb_links;
	t_paths *path;	
	// t_room *tmp;
	// tmp = start;

	info->first_path = create_path(info->nb_paths);
	path = info->first_path;
	nb_links = ft_count_links_2(start);
	// stocker la start en a_path[0]
	while (info->nb_paths < nb_links)
	{
		// path->a_path[0] = get_room(info, start->tubes->connection);
		path->a_path[0] = start->links[info->nb_paths];
		// ft_putstr(start->links[0]);
		// start->tubes = start->tubes->next;
		// ft_putnbr(info->nb_paths);
		// print_paths(path);
		info->nb_paths++;
		add_path(&path, info->nb_paths);
		path = path->next;
	}
	path_recursion(info, info->first_path, start);
	print_paths(info->first_path);
	return (0);
}

// int		path_recursion(t_info *info, t_paths *this_p, t_room *start)
// {
// 	int nb_links;
// 	int	nb_valid_links;
// 	int i;
// 	int j;
	
// 	i = 0;
// 	nb_links = ft_count_links_2(start);
// 	nb_valid_links = nb_links - 1;
// 	while (this_p->a_path[this_p->size]->links[i]) // while
// 	{
// 		j = 0;
// 		while (this_p->a_path[j] || this_p->a_path[j] == this_p->a_path[this_p->size])
// 		{
// 			if (this_p->a_path[this_p->size]->links[i] == this_p->a_path[j]
// 					|| this_p->a_path[this_p->size]->links[i] == start)
// 			{
// 				i++;
// 				break ;
// 			}
// 			j++;
// 		}
// 		// ft_putstr(" i:");
// 		// ft_putnbr(i);
// 		// ft_putstr(" j:");
// 		// ft_putnbr(j);
// 		if (this_p->a_path[j] == this_p->a_path[this_p->size])
// 		{
			
// 			// if (nb_valid_links > 1)
// 			// {
// 			// memcopy ? j (taille du path)
// 				// copy(this_p)//jusqu'à size
// 				// Changement de path(prendre l'id de la copy pour add le link)
// 			// }
// 			// else if nb_valid_links == 1)
// 			// {
// 				int previous;
// 				int next;

// 				previous = sizeof(t_room*) * this_p->size + 1;
// 				next =  sizeof(t_room*) * (this_p->size + 2);

// 				this_p->a_path = realloc(this_p->a_path, next);
// 				// this_p->size++;
// 				this_p->a_path[this_p->size + 1] = this_p->a_path[this_p->size]->links[i];
// 				// ft_putstr((this_p->a_path[this_p->size + 1])->name);
// 				// ajoute this_p->a_paths[this_p->size]->links[i] dans this_p->a_path
// 				// valid_links++;
// 			// }
// 			// i++;
// 		}
// 		// nb_links = ft_count_links_2(this_p_path->a_paths[this_p_path->size]);
// 		// while (
// 		// while (nb_links > 1)
// 			// copy_path(this_p_path);
// 		// i++;
		
// 	}
// 	// if (valid_links > 0)
// 		// this_p->size++;
// 	// if (info->nb_ways != info->nb_solution)
// 	// {
// 		// current_path = first_path;
// 		// path_recursion(info, firstpath);
// 	// }
// 	// while (other_path size < this_p->size)
// 		// path_recursion;
// 	return (0);
// }