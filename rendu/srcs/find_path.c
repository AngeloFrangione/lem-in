/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alanter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/19 15:26:59 by alanter          ###   ########.fr       */
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

int		find_path(t_info *info, t_room *end)
{
	int nb_links;
	int i;
	int size;
   
	//faire un malloc en fonction du nombre de room (compter au parsing !)
	//info->path = (t_room *)ft_memalloc(sizeof(t_room*) * nb_rooms);
	
	info->path = ft_memalloc(sizeof(t_room*) * 50);

	
	info->path[0] = end;
	end->visited = 1;
	end->next_room = NULL;
	i = 0;
	while (info->path[i])
	{
		nb_links = 0;
		while (nb_links < ft_count_links_2(info->path[i]))
		{
			if (!(info->path[i]->links[nb_links]->visited))
			{
				size = ft_size_path(info);
				info->path[size] = info->path[i]->links[nb_links];
				info->path[size]->visited = 1;
				info->path[size]->next_room = info->path[i];
			}
			if (info->path[size]->end)
				break;
			nb_links++;
		}
		if (info->path[size]->end)
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
	return (0);
}


/* Nouvel Algo :
 *
 * utiliser une chaine de room dans laquelle on liste toutes les rooms non visitées à la suite.
 *
 * - utilisation d'un booleen dans les rooms une fois visitées.
 * - stockage de la room dont on vient dans la room visitée.
 *
 * On parcourt toute la chaine de rooms en la remplissant au fur à mesure.
 *
 * On arrete de la parcourir dès qu'on a trouvé la end, ou quand on arrive au null (pas de sortie).
 */
