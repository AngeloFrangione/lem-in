/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 17:15:09 by alanter           #+#    #+#             */
/*   Updated: 2018/10/19 19:01:58 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		transform(t_info *info, int size)
{
	t_room *tmp;
	t_room *end;

	tmp = info->path[size];
	if (tmp->start)
	{
		tmp->ant = info->ants;
		while (!tmp->end)
		{
			ft_putstr(tmp->name);
			ft_putstr(" ==> ");
			tmp->next_room->previous_room = tmp;
			tmp = tmp->next_room;
		}
		end = tmp;
		tmp = tmp->previous_room;

		ft_putendl("");
		while (end->ant != info->ants)
		{
			tmp = end->previous_room;
			while(tmp)
			{
				if (tmp->ant)
				{
					if (tmp->start)
					{
						ft_putchar('L');
						ft_putnbr(info->ants - tmp->ant + 1);
						ft_putchar('-');
						ft_putstr(tmp->next_room->name);
						ft_putchar(' ');
						tmp->next_room->ant = info->ants - tmp->ant + 1;
						tmp->ant--;

					}
					else if (tmp->end)
					{
						ft_putchar('L');
						ft_putnbr(tmp->ant);
						ft_putchar('-');
						ft_putstr(tmp->next_room->name);
						ft_putchar(' ');
						tmp->next_room->ant++;
						tmp->ant = 0;
					}
					else
					{
						ft_putchar('L');
						ft_putnbr(tmp->ant);
						ft_putchar('-');
						ft_putstr(tmp->next_room->name);
						ft_putchar(' ');
						tmp->next_room->ant = tmp->ant;
						tmp->ant = 0;
					}
				}
				tmp = tmp->previous_room;
			}
			ft_putendl("");
		}
	}
	else
		ft_putstr("No path found !!!!\n");


}

void		find_path(t_info *info, t_room *end)
{
	int nb_links;
	int i;
	int size;

	size = -1;
	info->path = ft_memalloc(sizeof(t_room*) * count_rooms(info) + 10);
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
			if ((info->path[size])->start)
				break ;
			nb_links++;
		}
		if (size != -1 && (info->path[size])->start)
			break ;
		i++;
	}
	transform(info, size);
	free(info->path);
}
